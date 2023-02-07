#!/usr/bin/env python

#============================================================================
#
# @file buildit.py
#
# GENERAL DESCRIPTION
#   Unified script for building any/all targets available
#
# Copyright 2015-2016 by Qualcomm Technologies, Incorporated.
#                 All Rights Reserved.
#               QUALCOMM Proprietary/GTDR
#
#----------------------------------------------------------------------------
#
#                          EDIT HISTORY FOR MODULE
#
# This section contains comments describing changes made to the module.
# Notice that changes are listed in reverse chronological order.
#
# when       who     what, where, why
# --------   ---     -----------------------------------------------------------
# 11/29/16   aus     Added support for 32 bit LLVM compilation
# 10/18/16   ai      Print warning if directory name contains s/S due to EDK2 bug
# 09/12/16   vk      Add warning in parsing as error
# 08/03/16   yps     Changed perform merges output folder name to CLANG38
# 07/06/16   yps     update LLVM384 for XBLLoader and Core
# 06/22/16   bh      Fix target and single dsc related building
# 06/03/16   lg      Added options to build with QcomBinPkg folder
# 05/04/16   et      Changed options, updated alias call, general cleanup
# 05/02/16   et      Replaced extra_buildargs with compiler_flags and build_flags
# 04/26/16   et      Fix missing copy to unsigned bin
# 04/19/16   et      Update for new sectools drop
# 04/06/16   et      Moved build logs, .fv no elf support, build.cfg curr dir logic
# 03/24/16   et      Added dsc comiler tool support, --config arg case insensitivity
# 03/15/16   et      Added config file argument support, workspace check for dirty builds
# 02/29/16   et      Fix issue with stripping JtagProgrammer
# 02/23/16   et      Support for case-insensitive release,variant and some error handling
# 02/11/16   et      Removed buildproducts_builds output, formatted some output
# 02/09/16   et      Added single_dsc option, fixed calls with clean
# 02/05/16   et      Fixed search for flavors without giving variant
# 01/26/16   et      Added support for building packages without a variant
# 01/22/16   et      Fixed fd merging
# 01/21/16   et      Removed uefiplat call, changed fd filename
# 01/19/16   et      Added check to add extra buildargs, updated LLVM version
# 01/12/16   et      Added --extra_buildargs, cleaned up build products output
# 01/12/16   et      Added buildproducts feature, better help menu
# 01/08/16   et      Added check for python version requirement
# 01/06/16   et      Updated target searching logic, added fdf and dsc parsing, merge logic
# 10/28/15   et      Updated image version call, version argument, merge issue
# 10/16/15   et      Fixed env vars, builds tools if missing, handles sets of images, windows support
# 08/26/15   et      Initial release

import shutil
import stat
import subprocess
import glob
import re
from optparse import OptionParser
from collections import defaultdict
import platform
import os
import sys
import fnmatch
  

DEVDEBUG = False
GENERAL_ERROR_CODE = 1
ENVIRONMENT_SETUP_ERROR_CODE = 2
EDK_TOOL_ERROR_CODE = 3
FAILED_TO_BUILD_FLAVOR_ERROR_CODE = 4
BAD_RELEASE_TYPE_ERROR_CODE = 5

MINIMUM_PYTHON_VERSION = 34014192
DEFAULT_COMPILER_ARCH = "AARCH64"


WIN_AARCH64_TOOL         = "C:\\Apps\\LLVM\\3.8.4\\bin"
WIN_AARCH64_TOOL_PATH    = "C:\\Apps\\Linaro\\gcc-linaro-aarch64-none-elf-4.9-2014.07"
WIN_ARM_TOOL             = "C:\\Apps\\LLVM\\3.8.4\\bin"
WIN_ARM_TOOL_PATH        = "C:\\Apps\\gcc-linaro-arm-linux-gnueabihf-4.9-2014.05_win32"
CLANG38LINUX_BIN         = "/opt/clang/4.0.3"
CLANG38WIN_BIN           = "C:\\Apps\\LLVM\\3.8.4\\bin\\"
DEFAULT_ARM_LICENSE_FILE = "7117@license-wan-arm1"
DEFAULT_RELEASE_MODES    = "DEBUG,RELEASE"
BUILDIT_BUILDINFO_TAG    = "UserExtensions.Buildit.BuildInfo"
QCOM_DIR                 = "QcomPkg"
BOOT_IMAGES_DIR          = "boot_images"
COPY_IMAGES_AS_IS        = ["jtagprogrammer"]
BUILD_CFG_FILE           = "build.cfg"

# Default regexes
DEFAULT_TARGET_REGEX = "^([a-zA-Z]{3,4})(\d([\d|x|X]{2,3}))Pkg$"
DEFAULT_SUB_TARGET_REGEX = '^\d{3,4}$'
DEFAULT_VARIANT_REGEX = '^[A-Z][A-Z]$'

INF_HEADER = "#/** @file            FILENAME\n" \
			 "# \n" \
			 "#    Contains Qualcomm pre-built EFIs.\n" \
			 "# \n" \
			 "#    Copyright (c) 2015,2016 Qualcomm Technologies, Inc. All rights reserved.\n" \
			 "#\n" \
			 "#**/\n\n"

class build_flavor:
  def __init__(self, target, sub_target="", variant="", single_dsc=""):
	self.target = target
	self.sub_target = sub_target
	self.variant = variant
	self.single_dsc = single_dsc
	if sub_target:
	  self.dsc_list = generate_dsc_list(os.path.join(os.environ["WORKSPACE"], QCOM_DIR, self.target, self.sub_target),
										self.variant,
										single_dsc)
	else:
	  self.dsc_list = generate_dsc_list(os.path.join(os.environ["WORKSPACE"], QCOM_DIR, self.target),
										self.variant,
										single_dsc)
	
  def to_string(self):
	desc = "Target: " + self.target
	desc += " Subtarget: " + self.sub_target if self.sub_target else " Subtarget: ----"
	desc += " Varaint: " + self.variant if self.variant else " Variant: --"
	desc += " Single: " + self.single_dsc if self.single_dsc else " Single: --"
	return desc
  
# merge_book - Acts as a wrapper around a dictionary of merge_entry's
class merge_book:
  def __init__(self):
	self.merges = dict()
  def add_merge_item(self, merge_name, dll_path, sign_type, xbl_sec=""):
	# create merge_entry if it doesn't exist
	if merge_name not in self.merges:
	  new_merge = merge_entry(merge_name, sign_type, xbl_sec)
	  self.merges[merge_name] = new_merge
	# add the dll to merge_entry
	self.merges[merge_name].add_merge_item(dll_path, xbl_sec)
  
  # Same as above, but with a base to merge
  def add_merge_base(self, merge_name, base_dll_path, sign_type, xbl_sec=""):
	if merge_name not in self.merges:
	  new_merge = merge_entry(merge_name, sign_type, xbl_sec)
	  self.merges[merge_name] = new_merge
	self.merges[merge_name].set_merge_base_dll(base_dll_path, xbl_sec)


class merge_entry:
  def __init__(self, output_name, sign_type, xbl_sec=""):
	self.output_name = output_name
	self.sign_type = sign_type
	self.xbl_sec = xbl_sec
	self.dll_list = []
	self.merge_base_dll = ""
	
	if output_name == "":
	  print "Error: # MERGE value is invalid"
	  sys.exit(GENERAL_ERROR_CODE)
	
  def add_merge_item(self, dll_path, xbl_sec=""):
	self.dll_list.append(dll_path)
	if xbl_sec:
	  self.xbl_sec = xbl_sec
  
  def set_merge_base_dll(self, base_dll_path, xbl_sec=""):
	if self.merge_base_dll:
	  print "Error: Multiple MERGE_BASE tags found for " + self.output_name
	  sys.exit(GENERAL_ERROR_CODE)
	self.merge_base_dll = base_dll_path
	if xbl_sec:
	  self.xbl_sec = xbl_sec

  def modify_merge_entry_xbl_sec(self, xbl_sec):
	self.xbl_sec = xbl_sec

  def modify_merge_entry_dll_list(self, dll_list):
	self.dll_list = dll_list

  def print_merge_entry(self):
	print "[buildit.py] [MERGE DETAILS] output name: {0}".format(self.output_name)
	print "[buildit.py] [MERGE DETAILS] sign_type: {0}".format(self.sign_type)
	print "[buildit.py] [MERGE DETAILS] xbl sec: {0}".format(self.xbl_sec)
	print "[buildit.py] [MERGE DETAILS] dll list: {0}".format(self.dll_list)
	print "[buildit.py] [MERGE DETAILS] merge base dll: {0}".format(self.merge_base_dll)

def main():
  
  if sys.hexversion < MINIMUM_PYTHON_VERSION:
	print "\n[buildit.py] Error: Incorrect version of Python detected: " + sys.version
	print "[buildit.py]        Requires use of Python 2.7.3 or later."
	sys.exit(GENERAL_ERROR_CODE)

  if re.search("\.[sS]", os.getcwd()):
	print "\n[buildit.py] Error: Directory name containing \".[sS]\" detected: " + os.getcwd() 
	print "[buildit.py]        Please rename directory or use a different vce workspace name"
	print "[buildit.py]        that does not start with an 's' or 'S'."
	sys.exit(GENERAL_ERROR_CODE)
  
  desc = "python buildit.py [options]\n"\
		 "\nExample invocations:\n"\
		 "  python buildit.py -t Msm8998Pkg\n"\
		 "  python buildit.py -t Msm8998Pkg --variant LA\n"\
		 "  python buildit.py -t Msm8998Pkg --variant LA,WP -r DEBUG --version 123\n"
  parser = OptionParser(usage=desc)

  parser.add_option('-r', "--release",
					  action="store", default=DEFAULT_RELEASE_MODES,
					  help="Release mode for building, default is 'DEBUG,RELEASE'."\
							" Both modes will be built.")

  parser.add_option('-t', '--target', default="",
					help="Target(s) that will be built, separated by comma. " + \
						 "Example: -t Msm8998Pkg. " + \
						 "If not specified, all targets will be built",)
  
  parser.add_option('-s', '--sub_target', default="",
					help="Sub target(s) that will be built, separated by comma. " + \
						  "If not specified, all sub targets will be built per target")
  
  parser.add_option('-v', '--variant', default="",
					help="Variant(s) that will be built, separated by comma. " + \
						 "Example: -v la. " + \
						 "If not specified, all variants will be built per target,sub_target")
  
  parser.add_option('-q', '--query',
					action = "store_true", default=False, 
					help="Displays target, sub_target, and variant for all available flavors.")
  
  parser.add_option('-V', "--version",
					  action="store", default="0",
					  help="Specify build version. Default is 0. Example: -v 123.")
  
  parser.add_option('-a', "--alias",
					  action="store", default="",
					  help="Specify argument alias from config file QcomPkg/build.cfg. " + \
						   "Example: -a 98ladbg")
  
  parser.add_option('-b', '--build_flags',
					  action="store", default="",
					  help="Flags to be passed to the build invocation. " + \
							"Specify multiple arguments separated by a comma or enclosed in double quotes. " + \
							'Example: -b -v,-n,1')
  
  parser.add_option('-c', '--compiler_flags',
					  action="store", default="",
					  help="Extra flags to be passed to the build compiler directly. " + \
							"Specify multiple arguments enclosed in double quotes. " + \
							'Example: "-c -DPRE_SIL -DANOTHER_FLAG"')
  
  parser.add_option('-d', '--single_dsc',
					  action="store", default="",
					  help="Specify a single dsc to be built." + \
					  "Note: Merging may fail if a full build is not done prior to using this option.")
  
  parser.add_option('--create_intermediate_core',
					  action="store", default="",
					  help="Saves EFI's generated in this build into a new folder, QcomBinPkg/<variant>/XBLCore.")

  parser.add_option('--use_intermediate_core',
					  action="store", default="",
					  help="Speficy a path to the QcomBinPkg folder used to build using pre-built Core EFI's." +
						   "Note: This will fail if a full build with flag --create_intermediate_core is not done prior to using this option.")

  parser.add_option('--create_intermediate_loader',
					  action="store", default="",
					  help="Saves XBLLoader binaries generated in this build into a new folder, QcomBinPkg/Common/XBLLoader.")

  parser.add_option('--use_intermediate_loader',
					  action="store", default="",
					  help="Speficy a path to the QcomBinPkg folder used to build using pre-built Loader dll's." +
						   "Note: This will fail if a full build with flag --create_intermediate_loader is not done prior to using this option.")

  (options,args) = parser.parse_args()
  
  # Handle env setup for Windows or Linux
  try:
	setup_environment()
  except Exception as error:
	print error
	sys.exit(ENVIRONMENT_SETUP_ERROR_CODE)
  
  
  if options.query == True:
	query_all_flavors()
  
  if options.alias:
	try:
	  options = parse_alias_options(options)
	except Exception as error:
	  print error
	  sys.exit(GENERAL_ERROR_CODE)
  print options
  
  # make sure release_mode is valid
  options.release  = options.release.upper()
  for mode in options.release.split(','):
	if mode not in DEFAULT_RELEASE_MODES:
	  print 'Error: Release mode "' + mode + '" is invalid. Please see --help for more information'
	  sys.exit(BAD_RELEASE_TYPE_ERROR_CODE)
	
  
  # Creates BuildVersion.h if build version is provided
  create_build_version(options.version)
  
  # Check that tools exist, otherwise make them
  try:
	make_edk_tools()
  except Exception as error:
	print error
	sys.exit(EDK_TOOL_ERROR_CODE)
  
  # Delete old build products file
  build_products_file = os.path.join(os.environ["WORKSPACE"],
						"..", "BuildProducts.txt")
  if os.path.isfile(build_products_file):
	os.remove(build_products_file)
  
  # Collect flavors for given target/sub_target/variant
  options.variant = options.variant.upper()
  all_flavors = []
  for target in options.target.split(","):
	# Find all flavors with variants
	for sub_target in options.sub_target.split(","):
	  for variant in options.variant.split(","):
		if variant:
		  all_flavors = all_flavors + find_all_build_flavors(target, sub_target, variant, options.single_dsc)
		else:
		  all_flavors = all_flavors + find_all_build_flavors(target, sub_target, single_dsc=options.single_dsc)
	
	# Also search for flavors without variant, based on target only
	all_flavors = all_flavors + find_all_build_flavors(target=target, variant="", single_dsc="")
  
  # Build each flavor in specified mode (DEBUG and/or RELEASE)
  try:
	for flavor in all_flavors:
	  for release_mode in options.release.split(','):
		build_single_flavor(flavor, release_mode, options.compiler_flags, options.build_flags,
									options.use_intermediate_core, options.use_intermediate_loader)

		# If --create_intermediate_core was used, copy EFI files to QcomBinPkg/<variant>/XBLCore folder and create new INF's for those EFI's
		if options.create_intermediate_core and release_mode == "RELEASE":
		  copy_intermediate_files(os.path.join(options.create_intermediate_core, options.variant, "XBLCore"),
								  flavor, release_mode, "create_intermediate_core")

		# If --create_intermediate_loader was used, copy dll's/mbn's to QcomBinPkg/Common/XBLLoader folder
		if options.create_intermediate_loader and release_mode == "RELEASE":
		  copy_intermediate_files(os.path.join(options.create_intermediate_loader, "Common", "XBLLoader"),
								  flavor, release_mode, "create_intermediate_loader")
		if("Sdm660Pkg" == flavor.target):
			print "[buildit.py] Generating XBLLoader Memory Usage as XBLL_Memoy_Usage.txt... ",
			Mapit_script_root = os.path.join(os.environ["WORKSPACE"], "QcomPkg", "Tools")
			Mapit_script = os.path.join(Mapit_script_root, 'Mapit.py')
			XBL_loader_map_path = os.path.join(os.environ["WORKSPACE"],
										   "Build",
										   os.environ["TARGETMSM"] + "_Loader",
										   release_mode + "_" + arch_to_compiler("AARCH64"),
										   "AARCH64","QcomPkg","XBLLoader","XBLLoader","OUTPUT")
			map_file = os.path.join(XBL_loader_map_path ,"XBLLoader.map")
			op_file = os.path.join(XBL_loader_map_path ,"XBLL_Memoy_Usage.txt")
			if os.path.exists(Mapit_script) is True:
				print "Done [Memory Usage - Section wise Summary]"              
				cmds = "python" + ' ' + Mapit_script + " -t " + os.path.join(Mapit_script_root,"SDM660 ") + map_file + ' > ' + op_file
				subprocess.call(cmds,shell=True)

  except Exception as error:
	print error
	sys.exit(FAILED_TO_BUILD_FLAVOR_ERROR_CODE)

  display_build_summary(all_flavors, options.release)
  
  print "\n[buildit.py] Now exiting...\n"
  return
  
##############################################################################
# parse_alias_options
##############################################################################
  
def parse_alias_options(options):
  
  # Check for cfg file in current dir
  cfg_file = os.path.join(os.getcwd(),BUILD_CFG_FILE)
  if not os.path.isfile(cfg_file):
	# Otherwise check in QcomPkg dir
	cfg_file = os.path.join(os.environ["WORKSPACE"],QCOM_DIR,BUILD_CFG_FILE)
	if not os.path.isfile(cfg_file):
	  raise NameError("ERROR: buildit::parse_alias_options: " + \
						  "could not find config file " + cfg_file)
  
  print "[buildit.py] Using config file: " + cfg_file.split(BOOT_IMAGES_DIR + os.sep)[1]
  
  with open (cfg_file, "r") as cf:
	
	# skip to desired preset
	found = False
	line = cf.readline()
	while line:
	  if line.lower().find('[' + options.alias.lower() + ']') == -1:
		line = cf.readline()
	  else:
		found = True
		break
	
	if not found:
		raise NameError("ERROR: buildit::parse_alias_options: " + \
						"Could not find preset " + options.alias)
	
	print "[buildit.py] Using preset from config file: " + options.alias.upper()
	# Update each argument if present
	for line in cf.readlines():
	  # break if another preset is reached
	  if line.find("[") != -1:
		break
	  
	  # skip comment lines
	  if not line.strip() or line.strip()[0] == "#":
		continue
	  
	  # This regex grabs the arg and value pair from each line
	  # " (arg) = (val) "
	  search = re.search("\s*(\S+)\s*=\s*(.+)", line)
	  if search:
		arg = search.group(1)
		val = search.group(2)
		
		# options.arg = val
		setattr(options, arg, val)
		  
  return options

##############################################################################
# display_build_summary
##############################################################################
def display_build_summary(all_flavors, release_modes):
  if all_flavors:
	print "\n[buildit.py] Successfully built following flavors:\n" \
		 "###################################################"
	for flavor in all_flavors:
	  for release_mode in release_modes.split(','):
		print flavor.to_string() + " release: " + release_mode
  else:
	print "\n[buildit.py] Nothing built\n"
  
##############################################################################
# build_single_flavor
##############################################################################
def build_single_flavor(flavor, release_mode, compiler_flags, build_flags, use_intermediate_core, use_intermediate_loader):
  print "\n********************************************************************************"
  print "[buildit.py] Now building following flavor..."
  print "[buildit.py] " + flavor.to_string(), " Release: " + release_mode
  print "********************************************************************************\n"
  
  os.environ["TARGETPKG"]  = flavor.target
  os.environ["TARGETMSM"]  = flavor.target.split("Pkg")[0]

  matches = re.search(DEFAULT_TARGET_REGEX, flavor.target)
  if matches:
	os.environ["TARGETID"] = matches.group(2)
  else:
	# Handles app packages (e.g. QcomToolsPkg)
	os.environ["TARGETID"] = os.environ["TARGETMSM"]

  os.environ['TARGETROOT'] = os.path.join(QCOM_DIR, os.environ["TARGETPKG"])
  
  image_version_setup(os.environ["TARGETMSM"], flavor.variant)
  
  #
  # Compile all dsc's for this flavor
  #
	  
  for item in flavor.dsc_list:
	
	if platform.system() == "Windows":
	  if item[1] == "ARM":
		os.environ["TOOLS_PATH"] = WIN_ARM_TOOL
		os.environ["TOOLS_PATH_GCC"] = WIN_ARM_TOOL_PATH	  
	  elif item[1] == "AARCH64":
		os.environ["TOOLS_PATH"] = WIN_AARCH64_TOOL
		os.environ["TOOLS_PATH_GCC"] = WIN_AARCH64_TOOL_PATH
	  if "CLANG38_BIN" not in os.environ:
		os.environ["CLANG38_BIN"] = CLANG38WIN_BIN
	  if "CLANG38_ARM_PREFIX" not in os.environ:
		clang38_path = re.search(r"(.*)(bin\b)",os.getenv("CLANG38_BIN"))
		if clang38_path:
		  os.environ["CLANG38_ARM_PREFIX"] = clang38_path.group(1) + "tools\\bin\\"
	  os.environ["MAKE_PATH"] = "nmake"
	  os.environ["MAKE_FLAGS"] = "/C"
		  
	  if not os.path.isdir(os.environ["TOOLS_PATH"]):
		raise NameError("ERROR: buildit::build_single_flavor: " + \
						"Missing compiler tool chain." + \
						"Expected location " + os.environ["TOOLS_PATH"])
	  if not os.path.isdir(os.environ["TOOLS_PATH_GCC"]):
		raise NameError("ERROR: buildit::build_single_flavor: " + \
						"Missing GCC tool chain." + \
						"Expected location " + os.environ["TOOLS_PATH_GCC"])
	else:
	  if "CLANG38_BIN" not in os.environ:
		os.environ["CLANG38_BIN"] = CLANG38LINUX_BIN
	  if "CLANG38_ARM_PREFIX" not in os.environ:
		clang38_path = re.search(r"(.*)(bin\b)",os.getenv("CLANG38_BIN"))
		if clang38_path:
		  os.environ["CLANG38_ARM_PREFIX"] = clang38_path.group(1) + "tools/bin/"
	  os.environ["MAKE_PATH"] = "make"
	  os.environ["MAKE_FLAGS"] = ""		
	if not os.path.isdir(os.environ["CLANG38_BIN"]):
	  raise NameError("ERROR: buildit::build_single_flavor: " + \
						"Missing LLVM tool chain." + \
						"Expected location " + os.environ["CLANG38_BIN"])
	if not os.path.isdir(os.environ["CLANG38_ARM_PREFIX"]):
	  raise NameError("ERROR: buildit::build_single_flavor: " + \
						"Missing LLVM tool chain." + \
						"Expected location " + os.environ["CLANG38_ARM_PREFIX"])
	  
	is_clang38_bin_exist = False
	for path in os.environ["PATH"].split(os.pathsep):
	  if path == os.getenv("CLANG38_BIN"):
		is_clang38_bin_exist = True
		break
		
	if not is_clang38_bin_exist:
	  os.environ["PATH"] = os.environ["CLANG38_BIN"]+ os.pathsep + os.environ["PATH"]

	log_file = os.path.join(QCOM_DIR, flavor.target, flavor.sub_target, flavor.variant,
						  "build_" + os.path.basename(item[0]).split(".dsc")[0] + ".log")
	
	# if --use_intermediate_core was used, pick up *.dsc files from QcomBinPkg folder
	ind = flavor.dsc_list.index(item)
	if use_intermediate_core and "Core" in item[0]:
		dsc = os.path.join(use_intermediate_core, flavor.variant, os.path.basename(item[0]))
		if "boot_images" in dsc:
		  flavor.dsc_list[ind] = [dsc.split("boot_images" + os.sep)[1], item[1]]
		item = flavor.dsc_list[ind]
		log_file = os.path.join(use_intermediate_core, flavor.sub_target, flavor.variant,
								"build_" + os.path.basename(item[0]).split(".dsc")[0] + ".log")

	build_cmd = ['-p', item[0], #dsc
				 '-j', log_file,
				 '-w',
				 '-a', item[1], #arch
				 '-t', arch_to_compiler(item[1], item[0]),
				 '-b', release_mode]
				 
	if release_mode == "RELEASE":
	  build_cmd += ['-D', 'PRODMODE=PRODMODE']
	else:
	  build_cmd += ['-D', 'PRODMODE=DEBUGMODE']
	  
	# Set FEATURE_FLAGS environment variable, dsc will pass to compiler
	if compiler_flags:
	  os.environ["FEATURE_FLAGS"] = compiler_flags
	
	# Add build.exe specific OptionParser
	if build_flags:
	  build_cmd += build_flags.strip('"').split(',')
	# if --use_intermediate_loader was used and we are compiling loader, skip build step
	if use_intermediate_loader and "Loader" in item[0]:
		print "[buildit.py] SKIP BUILDING XBL LOADER"
	else:
		print "[buildit.py] Building with arguments...\n", build_cmd, '\n'
		try:
			subprocess.check_call(["build"] + build_cmd)
		except Exception as error:
			raise NameError("ERROR: buildit::build_single_flavor: " + \
							"Building failed with error... " + str(error))
  
  if "clean" in build_flags:
	return
  
  # Make a full flavor; Requried for finding all merge dependencies
  full_flavor = build_flavor(flavor.target, 
							 flavor.sub_target, 
							 flavor.variant)

  # Determine what to merge
  merge_dict = generate_merge_items(full_flavor,release_mode, flavor.single_dsc)
  
  # Send each merge entry i.e. image.elf off to get merged,
  # and collect the items(elfs) that were created
  built_items = []
  for merge_name, merge_entry in merge_dict.merges.iteritems():
	build_product = perform_merges(merge_entry,
									  flavor.target,
									  flavor.sub_target,
									  flavor.variant,
									  release_mode,
								   use_intermediate_loader)
	# make sure something was actually built.
	if build_product:
	  built_items.append(build_product)
  
  # Write out after merging for nicer looking output
  try:
	append_build_products(built_items)
  except Exception as error:
	raise NameError("ERROR: buildit::append_build_products: " + \
					"Failed to append to build products file.")  
  
  print "*******\n[buildit.py] Completed building ", flavor.to_string(), " Release: " + release_mode
	
##############################################################################
# append_build_products
##############################################################################
def append_build_products(built_items):
  for item in built_items:
	output_dir = item[0]
	file_name = item[1]
	bp_cmd = ['python', os.path.join(os.environ['WORKSPACE'],'QcomPkg','Tools',
								   'scripts','buildproducts_builder.py'),
			'-t', os.path.join(os.environ["WORKSPACE"],'..'),
			'-s', output_dir,
			'-i', file_name]
	subprocess.check_output(bp_cmd)
	
##############################################################################
# perform_merges
##############################################################################
def perform_merges(merge_entry, target, sub_target ,variant, release_mode, use_intermediate_loader):

  # if --use_intermediate_loader was used, modify paths to dll's
  if use_intermediate_loader is not "" and "xbl" in merge_entry.output_name:
	# xbl_sec
	xbl_sec = os.path.join(os.path.basename(use_intermediate_loader), "Common", "XBLLoader",
									   os.path.basename(merge_entry.xbl_sec))
	merge_entry.modify_merge_entry_xbl_sec(xbl_sec)

	# dll_list
	temp_dll_list = []
	for index in range(len(merge_entry.dll_list)):
	  dll = merge_entry.dll_list[index]
	  if "XBLRamDumpLib" in dll or "XBLLoader" in dll:
		temp_dll_list.append(os.path.join(use_intermediate_loader, "Common", "XBLLoader",
												   os.path.basename(dll)))
	merge_entry.modify_merge_entry_dll_list(temp_dll_list)
	if "XBLLoader.dll" in merge_entry.merge_base_dll:
	  merge_entry.merge_base_dll = os.path.join(use_intermediate_loader, "Common", "XBLLoader",
												os.path.basename(merge_entry.merge_base_dll))

  output_name = merge_entry.output_name
  sign_type = merge_entry.sign_type
  xbl_sec = merge_entry.xbl_sec
  dlls = merge_entry.dll_list
  merge_base_dll = merge_entry.merge_base_dll
  
  merge_output_dir = os.path.join(os.environ["WORKSPACE"],
								   "Build",
								   os.environ["TARGETMSM"] + "_Loader",
								   release_mode + "_" + arch_to_compiler("AARCH64"),
								   "AARCH64")
  merged_output_elf = os.path.join(merge_output_dir, output_name)

  # Make sure path where merging will happen exists
  if not os.path.isdir(merge_output_dir):
	os.makedirs(merge_output_dir)
	
  # Check that all images to merge with are present
  for dll in dlls + [merge_base_dll]:
	if dll and not os.path.isfile(dll):
	  print "** WARNING ** Cannot merge " + output_name + ". Missing file: " + dll.split(os.environ["WORKSPACE"] + os.sep)[1]
	  return None
	  
  
  cxbl_script = os.path.join(os.environ["WORKSPACE"], QCOM_DIR, 'Tools', 'createxbl.py')
  
  #
  # createxbl single
  #
  single_dll =""
  if len(dlls) == 1:
	single_dll = dlls[0]
  elif len(dlls) == 0 and merge_base_dll != "":
	single_dll = merge_base_dll
	
  if single_dll:
	# Skip createxbl step to avoid stripping symbols
	if output_name.split('.')[0].lower() in COPY_IMAGES_AS_IS:
	  merged_output_elf = dlls[0]
	else:
	  # Single merge
	  cxbl_cmd = [cxbl_script,
				  '-f', single_dll,
				  '-o', merged_output_elf,
				  '-a', "64"]
				  
	  # Add xbl_sec if included
	  if xbl_sec:
		cxbl_cmd += ["-x", os.path.join(os.environ["WORKSPACE"],xbl_sec),
					 "-d", "64"]
	  
	  # Run merge command
	  try:
		subprocess.check_output(['python'] + cxbl_cmd)
	  except Exception as error:
		raise NameError("ERROR: buildit::perform_merges: " + \
						"Failed to merge with error: " + str(error))
	
  #
  # createxbl multiple merge
  #
  else:
	
	if merge_base_dll:
	  dlls = [merge_base_dll] + dlls
	
	first_dll = dlls[0]
	num_dlls = len(dlls)
	
	for x in xrange(1,num_dlls):
	  # grab the next dll
	  second_dll = dlls[x]
	  # Everything is always merged into 64-bit elfs
	  cxbl_cmd = [cxbl_script,
				'-f', first_dll,
				'-s', second_dll,
				'-o', merged_output_elf,
				'-a', "64",
				'-b', "64"]
				
	  # if not final merge
	  if x < (num_dlls - 1):
		cxbl_cmd.append('-n')
	  if x == 1 and xbl_sec:
		# final merge: add xbl_sec if included
		cxbl_cmd += ["-x", os.path.join(os.environ["WORKSPACE"],xbl_sec),
					 "-d", "64"]
		  
	  # Run merge command
	  try:
		cmd_output = subprocess.check_output(["python"] + cxbl_cmd)
	  except Exception as error:
		raise NameError("ERROR: buildit::perform_merges: " + \
						"Failed to merge with error: " + str(error))
	  first_dll = merged_output_elf
  
  # handle non-signed images
  if not sign_type:
	# setup directories
	output_dir_root = get_output_dir_root(sub_target, variant, release_mode)
	sign_bin = os.path.join(output_dir_root, "sign")
	unsigned_bin = os.path.join(output_dir_root, "unsigned")
	
	# create dirs if not yet created
	for path in [sign_bin, unsigned_bin]:
	  if not os.path.isdir(path): 
		os.makedirs(path)
		
	print "[buildit.py] Copying over " + output_name + " image as-is...",
	shutil.copy2(merged_output_elf, os.path.join(output_dir_root, output_name))
	shutil.copy2(merged_output_elf, os.path.join(unsigned_bin, output_name))
	print "Done"
	return [output_dir_root, output_name]
  
  # handle signed images
  sign_image(merged_output_elf, output_name, sign_type, variant, release_mode)
  
  output_dir_root = get_output_dir_root(sub_target, variant, release_mode)
  return [output_dir_root, output_name]

##############################################################################
# sign_image
##############################################################################
def sign_image(input_image, output_image, sign_type, variant, release_mode):
  
  # Setup Bin directories
  output_dir_root = get_output_dir_root(os.environ["TARGETID"], variant, release_mode)
  sign_bin = os.path.join(output_dir_root, "sign")
  unsigned_bin = os.path.join(output_dir_root, "unsigned")
  
  # Create Bin directories
  for path in [sign_bin, unsigned_bin]:
	if not os.path.isdir(path): 
	  os.makedirs(path)
  
  # copy input image to unsigned bin
  shutil.copy2(input_image, os.path.join(unsigned_bin, output_image))
  
  print "[buildit.py] Generating default signed " + output_image + " image...",
  
  sign_config = get_sectool_config()
  
  sec_sign_cmd = [os.path.join(os.environ["SECTOOLS_SCRIPTS_PATH"], "sectools_builder.py"),
				  "-t" , output_dir_root,
				  "-i" , input_image,
				  "-g" , sign_type,
				  "--config" , os.path.join(os.environ["SECTOOLS_CFG_PATH"], sign_config["config_xml"])]
  # append optional arguments
  for option,arg in sign_config.iteritems():
	if option in ["msmid", "soc_hw_version", "soc_vers"]:
	  sec_sign_cmd += ['--' + option, arg]
  
  # Run sectools sign command
  try:
	sec_cmd_output = subprocess.check_output(['python'] + sec_sign_cmd)
  except Exception as error:
	raise NameError("ERROR: buildit::sign_image: " + \
					"Failed to sign image with error: " + str(error))
  
  # copy signed image to Bin root
  signed_output_elf = os.path.join(sign_bin, "default", sign_type, output_image)
  shutil.copy2(signed_output_elf, os.path.join(output_dir_root, output_image))
  
  print "Done"
  
##############################################################################
# get_sectool_config
##############################################################################                
def get_sectool_config():
  # Add TargetPkg folder to path
  pkgdir = os.path.join(os.environ["WORKSPACE"], QCOM_DIR, os.environ["TARGETPKG"])
  sys.path.append(pkgdir)
  
  import sectools_config
  
  # Remove TargetPkg folder from path
  sys.path = sys.path[:-1]
  
  return sectools_config.get_config()

##############################################################################
# get_output_dir_root
##############################################################################                
def get_output_dir_root(sub_target, variant, release_mode):
  if sub_target:
	return os.path.join(os.environ["WORKSPACE"], 
						os.environ["TARGETROOT"],"Bin", 
						sub_target, variant, release_mode)
  else:
	return os.path.join(os.environ["WORKSPACE"], 
						os.environ["TARGETROOT"],"Bin", 
						os.environ["TARGETID"], variant, release_mode)
	
##############################################################################
# get_dll_from_dsc_inf
##############################################################################
def get_dll_from_dsc_inf(dsc,inf,release_mode):
  
  dsc_path = dsc[0]
  arch = dsc[1]
  
  output_dir = ""
  for section in ["Defines", "Defines." + arch]:
	result = find_tag_in_descriptor_file(dsc_path, section, "OUTPUT_DIRECTORY")
	if result:
	  output_dir = result
  if not output_dir:
	raise NameError("ERROR: buildit::get_dll_from_dsc_inf: " + \
					"Missing OUTPUT_DIRECTORY tag in dsc: " + dsc[0])
  
  #if use_intermediate_loader and "Loader" in dsc[0]:
  #    dll_path = os.path.join(use_intermediate_loader, "Common", "XBLLoader",
  #                            find_tag_in_descriptor_file(inf, "Defines", "BASE_NAME") + ".dll")
  #else:
  dll_path = os.path.join(os.environ["WORKSPACE"],
							  output_dir,
							  release_mode + "_" + arch_to_compiler(arch, dsc[0]),
							  dsc[1],
							  inf.split(".inf")[0],
							  "DEBUG",
							  find_tag_in_descriptor_file(inf, "Defines", "BASE_NAME") + ".dll")
  return dll_path

##############################################################################
# generate_merge_items
##############################################################################
def generate_merge_items(flavor, release_mode, single_dsc):

  merge_dict = merge_book()
  
  # Check for normal merges of images inside dsc
  for dsc in flavor.dsc_list:
	  
	# check for fdf
	fdf_file = find_tag_in_descriptor_file(dsc[0], "Defines", "FLASH_DEFINITION")
	if fdf_file:
	  
	  # do fdf merging if this is the single_dsc or no single_dsc is given
	  do_fdf_merging = (os.path.basename(dsc[0]) == single_dsc) or (single_dsc == "")
	  fdf_details = handle_fdf_file(flavor, dsc, fdf_file, release_mode, do_fdf_merging)
		
	  # Only add an item if we are merging and have a dll
	  if fdf_details and fdf_details["merge_name"] and fdf_details["dll"]:
		merge_dict.add_merge_item(fdf_details["merge_name"],
								  fdf_details["dll"],
								  fdf_details["sign_type"],
								  fdf_details["xbl_sec"])
	
	#Check for any merge entries inside DSC
	with open(os.path.join(os.environ["WORKSPACE"],dsc[0]), 'r') as d:
	  # skip to [Components.common]
	  while not re.search('\[Components.common\]', d.readline()):
		pass
	  
	  # Search for infs now
	  inf = sign_type = xbl_sec_image = ""
	  merge_name = None
	  merge_base = None
	  bracket_count = 0
	  
	  for line in d.readlines():
		
		# 0 implies not inside inf block yet
		if bracket_count == 0:
		  
		  # skip commented lines if outside of an inf block
		  if line.lstrip().find("#") == 0:
			continue
			
		  # look for open bracket, start of inf block
		  if line.find(".inf") != -1 and line.find("{") != -1:
			bracket_count = 1
			inf = re.search("(\S+.inf)", line).group(1)
			merge_name = sign_type = xbl_sec_image = ""
			
		elif bracket_count > 0:
		  #Inside INF
		  if line.find("{") != -1:
			bracket_count = bracket_count + 1
		  elif line.find("}") != -1:
			bracket_count = bracket_count - 1
			
			# Upon closing brackets, validate and add merge item
			if bracket_count == 0 and inf and merge_name:
			  merge_dict.add_merge_item(merge_name, 
										get_dll_from_dsc_inf(dsc,inf,release_mode),
										sign_type, 
										xbl_sec_image)

			# Upon closing brackets, validate and add merge_base
			elif bracket_count == 0 and inf and merge_base:  
			  merge_dict.add_merge_base(merge_base, 
										get_dll_from_dsc_inf(dsc,inf,release_mode),
										sign_type, 
										xbl_sec_image)

		  if bracket_count < 0:
			raise NameError("ERROR: buildit::generate_merge_items: " + \
							"Malformed dsc file: " + dsc)
			
		  # check for #MERGE TAG
		  search = re.search("#\s*BUILD.MERGE", line)
		  if search:
			merge_name = ""
		  
		  # check for #MERGE  (note: no merge name)
		  search = re.search("#\s*BUILD.MERGE\s(\S+)", line)
		  if search:
			merge_name = search.group(1)
		  
		  # check for #MERGE_BASE
		  search = re.search("#\s*BUILD.MERGE_BASE\s(\S+)", line)
		  if search:
			merge_base = search.group(1)
		  
		  # check for #SIGN TAG
		  search = re.search("#\s*BUILD.SIGN\s*(\S+)", line)
		  if (search is not None):
			sign_type = search.group(1)

	  # check for #XBL_SEC TAG
		  search = re.search("#\s*BUILD.XBL_SEC\s*(\S+)", line)
		  if (search is not None):
			xbl_sec_image = search.group(1)

  return merge_dict

##############################################################################
# handle_fdf_file
##############################################################################
def handle_fdf_file(flavor,dsc, fdf, release_mode, do_fdf_merging):
  merge_details = {}
  
  # setup bin paths
  output_bin_root = get_output_dir_root(flavor.sub_target, flavor.variant, release_mode)
  sign_bin = os.path.join(output_bin_root, "sign")
  unsigned_bin = os.path.join(output_bin_root, "unsigned")
  
  # create bin folders if non-existent
  for path in [sign_bin, unsigned_bin]:
	if not os.path.isdir(path): 
	  os.makedirs(path)
	  
  build_dir = find_tag_in_descriptor_file(dsc[0], "Defines", "OUTPUT_DIRECTORY")
  if not build_dir:
	build_dir = find_tag_in_descriptor_file(dsc[0], "Defines." + dsc[1], "OUTPUT_DIRECTORY")
	if not build_dir:
	  raise NameError("ERROR: buildit::handle_fdf_file: " + \
					  "Unable to find OUTPUT_DIRECTORY tag in dsc: " + dsc[0])
	  
  ih_output_name = find_tag_in_descriptor_file(dsc[0], BUILDIT_BUILDINFO_TAG, "OUTPUT_NAME")
  if not ih_output_name:
	raise NameError("ERROR: buildit::handle_fdf_file: " + \
					  "Unable to find OUTPUT_NAME tag in dsc: " + dsc[0])
  
  target_msm_efi = "FVMAIN_COMPACT.Fv"
  target_msm_elf = "FVMAIN_COMPACT.elf"
  
  efi_fd_dir = os.path.join(os.environ["WORKSPACE"],
						  build_dir,
						  release_mode + "_" + arch_to_compiler(dsc[1], dsc[0]),
						  "FV")
  
  if ih_output_name.endswith(".fv"):
	# copy to bin root
	shutil.copy2(os.path.join(efi_fd_dir, target_msm_efi),
				os.path.join(output_bin_root, ih_output_name))
	# copy to unsigned bin
	shutil.copy2(os.path.join(efi_fd_dir, target_msm_efi),
				os.path.join(unsigned_bin, ih_output_name))
	return merge_details
  
  # Find out what is to be added to the merge list
  merge_details["merge_name"] = find_tag_in_descriptor_file(dsc[0], BUILDIT_BUILDINFO_TAG, "MERGE")
  merge_details["sign_type"] = find_tag_in_descriptor_file(dsc[0], BUILDIT_BUILDINFO_TAG, "SIGN")
  merge_details["xbl_sec"] = find_tag_in_descriptor_file(dsc[0], BUILDIT_BUILDINFO_TAG, "XBL_SEC")
  merge_details["dll"] = os.path.join(efi_fd_dir, 
									  target_msm_elf)
  # Make sure we actually have merge_name and dll
  for arg in ["merge_name","dll"]:
	if arg not in merge_details:
	  raise NameError("ERROR: buildit::handle_fdf_file: " + \
					  "Unable to find " + arg + " tag in fdf: " + fdf)
  
  # conditionally skip merging
  if not do_fdf_merging:
	return merge_details
  
  # returned value will look like "0x00000|blahblahblah"
  # so split on the "|" and take first one(0)
  target_addr = find_tag_in_descriptor_file(fdf, "", "BaseAddress").split("|")[0]
  if not target_addr:
	raise NameError("ERROR: buildit::handle_fdf_file: " + \
					  "Unable to find BaseAddress tag in dsc: " + dsc[0])
  
  ih_cmd = [os.path.join(os.environ["WORKSPACE"],QCOM_DIR,"Tools", "image_header.py"),
			os.path.join(efi_fd_dir, target_msm_efi),
			os.path.join(efi_fd_dir, ih_output_name),
			target_addr,
			"elf"]
  if dsc[1] == "AARCH64":
	ih_cmd.append("64")
  
  print "[buildit.py] Generating ELF header for image " + ih_output_name,
  try:
	cmd_output = subprocess.check_output(["python"] + ih_cmd)
  except Exception as error:
	raise NameError("ERROR: buildit::handle_fdf_file: " + \
					"Failed to generate ELF header with error: " + str(error))
  
  print "Done"
  
  # Get the sing_type
  sign_type = find_tag_in_descriptor_file(dsc[0], BUILDIT_BUILDINFO_TAG, "SIGN_FD")
  if not sign_type:
	raise NameError("ERROR: buildit::handle_fdf_file: " + \
					"SIGN_FD tag not found in dsc: " + dsc[0])
  
  # Perform signing
  sign_image(os.path.join(efi_fd_dir,ih_output_name),
			 ih_output_name,
			 sign_type,
			 flavor.variant,
			 release_mode)
  
  return merge_details

##############################################################################
# arch_to_compiler
##############################################################################
def arch_to_compiler(arch, dsc=""):
  
  # Look for COMPILER_<platform> tag if dsc was provided
  if dsc:
	if platform.system().lower() == "windows":
	  compiler_flag = "COMPILER_WIN"
	else:
	  compiler_flag = "COMPILER_LINUX"
	compiler = find_tag_in_descriptor_file(dsc, BUILDIT_BUILDINFO_TAG,compiler_flag)
	if compiler: return compiler
  
  # Otherwise, determine 
  if arch == "AARCH64":
	if platform.system() == "Windows":
	  return "CLANG38WIN"
	else:
	  return "CLANG38LINUX"
  elif arch == "ARM":
	if platform.system() == "Windows":
	  return "RVCT501"
	else:
	  return "RVCT501LINUX"

##############################################################################
# search_valid_dirs
##############################################################################
def search_valid_dirs(search_path, regex):
  valid_dirs = []
  for f in os.listdir(search_path):
	if re.search(regex, f):
	  valid_dirs += [os.path.join(search_path, f)]
  
  return valid_dirs

##############################################################################
# match_whole_word
##############################################################################
def match_whole_word(raw_regex):
  return '^'+raw_regex+'$'


##############################################################################
# find_all_build_flavors
##############################################################################  
def find_all_build_flavors(target=None, sub_target=None, variant=None, single_dsc=""):
  flavors = []
	
  # Set Target regex
  if target:
	target_regex = target
  else:
	target_regex = DEFAULT_TARGET_REGEX
  
  # Search for all matching targets
  boot_dir = os.environ["WORKSPACE"]
  search_path = os.path.join(boot_dir, QCOM_DIR)
  for target_match in search_valid_dirs(search_path, target_regex):
	# Set sub_target regex
	if sub_target:
	  sub_target_regex = match_whole_word(sub_target)
	else:
	  sub_target_regex = DEFAULT_SUB_TARGET_REGEX
	
	# Search for all sub targets
	for sub_target_match in search_valid_dirs(target_match, sub_target_regex):
	  
	  # Search for variant
	  if variant:
		variant_regex = match_whole_word(variant)
	  else:
		variant_regex = DEFAULT_VARIANT_REGEX
		
	  for variant_match in search_valid_dirs(sub_target_match, variant_regex):
		variant_flavor = build_flavor(strip_basename(target_match), 
									  strip_basename(sub_target_match), 
									  strip_basename(variant_match),
									  single_dsc)
		# Flavor is only valid if there is at least one dsc collected
		if variant_flavor.dsc_list:
		  flavors.append(variant_flavor)
		  
	# Search for variant
	if variant is None:
	  variant_regex = DEFAULT_VARIANT_REGEX
	elif variant is "":
	  no_variant_flavor = build_flavor(strip_basename(target_match),
									   "",
									   "",
									   single_dsc)
	  
	  if (no_variant_flavor.dsc_list):
		flavors.append(no_variant_flavor)
	  
	  variant_regex = match_whole_word(variant)

	else:
	  variant_regex = match_whole_word(variant)
	  
	for variant_match in search_valid_dirs(target_match, variant_regex):
	  variant_flavor = build_flavor(strip_basename(target_match), 
									"", 
									strip_basename(variant_match),
									single_dsc)
	  if variant_flavor.dsc_list:
		flavors.append(variant_flavor)
   
  return flavors

##############################################################################
# query_all_flavors
##############################################################################
def query_all_flavors():
  all_flavors = find_all_build_flavors()
  print "\n[buildit.py] All available flavors:\n"\
		  "###############################################"
  for flavor in all_flavors:
	print flavor.to_string()
  sys.exit(0)
  
##############################################################################
# generate_dsc_list
##############################################################################
def generate_dsc_list(target_dir, variant_dir, single_dsc):
  
  # Either search for the single dsc specified or all dsc's
  dsc_regex = single_dsc if single_dsc else "*.dsc"
  
  # collect dsc's from variant_dir + target_dir/VARIANT
  dsc_sources = glob.glob(os.path.join(target_dir, variant_dir, dsc_regex))
  
  # Only check Common folder if this flavor has a variant
  # Otherwise, flat structure is assumed
  if variant_dir:
	dsc_sources = dsc_sources + glob.glob(os.path.join(target_dir, "Common", dsc_regex))
  
  trimmed_sources = []
  for dsc in dsc_sources:
	# Remove BOOT_IMAGES_DIR from path
	trim_dsc = dsc.split(BOOT_IMAGES_DIR + os.sep)[1]
	dsc_arch = find_tag_in_descriptor_file(dsc, BUILDIT_BUILDINFO_TAG, "COMPILER_ARCH")
	if not dsc_arch:
	  dsc_arch = DEFAULT_COMPILER_ARCH
	
	trimmed_sources.append([trim_dsc, dsc_arch])
  
  return trimmed_sources

##############################################################################
# find_tag_in_descriptor_file
##############################################################################
def find_tag_in_descriptor_file(dsc, section, tag):
  
  with open(os.path.join(os.environ["WORKSPACE"], dsc), 'r') as f:
	
	if section:
	  in_desired_section = False
	else:
	  in_desired_section = True
	  
	for line in f.readlines():
	  # Check if entering new section, only if section is provided
	  if section:
		section_search = re.search("\[(\S+)\]", line)
		if section_search:
		  # Check if entering desired section
		  if section_search.group(1) == section:
			in_desired_section = True
		  elif in_desired_section:
			# Hit new section, and already hit desired
			# No tag was found, return early
			return ""
	  
	  if in_desired_section or not section:
		expr = tag + "\s*=\s*(\S+)"
		tag_search = re.search(expr, line)
		if tag_search:
		  return tag_search.group(1)
  
  # Not found anywhere
  return ""

##############################################################################
# strip_basename
##############################################################################
def strip_basename(string):
  return string.split(os.path.dirname(string)+os.sep)[1]

##############################################################################
# setup_environment
##############################################################################
def setup_environment():
  
  print "[buildit.py] Building on " + platform.system()
  make_name = ""
  if platform.system() is "Windows":
	make_name = "nmake.exe"
	EDK_ENV_FLAG = 'EDK_ENV_STARTS_HERE'
	os.chdir(os.path.dirname(os.path.realpath(__file__)) + os.sep + "..")
	edk_output = subprocess.check_output('edksetup.bat --nt32 && echo ' + EDK_ENV_FLAG + ' && set', shell=True)
	parse_and_set_edk_env(edk_output, EDK_ENV_FLAG)

  else:
	make_name = "make"
	os.environ["ARMLMD_LICENSE_FILE"] = DEFAULT_ARM_LICENSE_FILE
	curr_dir = os.getcwd()
	os.chdir(os.path.dirname(os.path.realpath(__file__)) + os.sep + "..")
	edk_command = ['bash', '-c', 'source edksetup.sh BaseTools && env']
	proc = subprocess.Popen(  edk_command, stdout=subprocess.PIPE)
	for line in proc.stdout:
	  (key, _, value) = line.partition("=")
	  os.environ[key] = value.strip()
	proc.communicate()
	os.chdir(curr_dir)
  
	# Check if nmake.exe/make.exe is in PATH
	make_found = False
	for path in os.environ["PATH"].split(os.pathsep):
	  if os.path.exists(os.path.join(path, make_name)):
		make_found = True
		break
	if not make_found:
	  raise NameError("ERROR: buildit::setup_environment: " + make_name +\
					  " not found in PATH")
					  
  if "WORKSPACE" not in os.environ:
	raise NameError("ERROR: buildit::setup_environment: " + \
					"Failed to setup environment variable WORKSPACE.")
  
  # Check that boot_images folder exists, there are dependencies on this
  if BOOT_IMAGES_DIR not in os.environ["WORKSPACE"]:
	raise NameError("ERROR: buildit::setup_environment: " + \
					"Build root folder 'boot_images' is missing. Please ensure this folder exist.")
  
  # Enable sectools and set sectools_policy
  os.environ["USE_SECTOOLS"] = "1"
  os.environ["SECTOOLS_POLICY"] = "USES_SEC_POLICY_MULTIPLE_DEFAULT_SIGN"
  os.environ["USES_PLATFORM_IMAGE_INTEGRITY_CHECK"] = "1"
  os.environ[os.environ["SECTOOLS_POLICY"]] = "1"
  os.environ["SECTOOLS_CFG_PATH"] = os.path.join(os.environ["WORKSPACE"], QCOM_DIR,"Tools","sectools", "config","integration")
  os.environ["SECTOOLS_SCRIPTS_PATH"] = os.path.join(os.environ["WORKSPACE"], QCOM_DIR,"Tools","sectools")
  
  
  if DEVDEBUG:
	print "[buildit.py] WORKSPACE:" + os.environ["WORKSPACE"]
	print "[buildit.py] Environment\n"
	print os.environ

##############################################################################
# parse_and_set_edk_env
##############################################################################    
def parse_and_set_edk_env(edk_output, EDK_ENV_FLAG):
  
  # Go through every line
  # Skip until 'ENDFLAG'
  # Then add everything in env to current env
  skipping = True
  for line in edk_output.splitlines():
	if not skipping:
	  envvar = line[0:line.index('=')]
	  envval = line[line.index('=')+1:]
	  os.environ[envvar] = envval
	  
	elif re.search(EDK_ENV_FLAG, line):
	  skipping = False
  return
  
##############################################################################
# create_build_version
############################################################################## 
def create_build_version(build_version):
  build_version_file = os.path.join(os.environ["WORKSPACE"],
											   QCOM_DIR, 
											   "Include",
											   "BuildVersion.h" )
  
  if os.path.isfile(build_version_file) and build_version == "0":
	print "[buildit.py] QcomPkg\Include\BuildVersion.h already exists."
	print "[buildit.py] No build version specified. Will use existing version."
	return
  
  print "[buildit.py] Creating QcomPkg\Include\BuildVersion.h with version: " + build_version
  try:
	with open(build_version_file, 'w') as vf:
	  vf.write("/* DO NOT EDIT: This file is autogenerated */\n")
	  vf.write("#ifndef __BUILDVERSION_H__\n")
	  vf.write("#define __BUILDVERSION_H__\n\n")
	  vf.write("#ifndef UEFI_BUILD_VERSION\n")
	  vf.write("  #define UEFI_BUILD_VERSION        \"" + build_version + "\"\n")
	  vf.write("#endif\n\n")
	  vf.write("#endif /* __BUILDVERSION_H__ */\n")
  except:
	raise NameError("ERROR: buildit::create_build_version: " + \
					"Unable to build version file")

##############################################################################
# make_edk_tools
##############################################################################
def make_edk_tools():
  if platform.system() == "Windows":
	return
	
  workspace_file = os.path.join(os.environ["WORKSPACE"], "BaseTools", "workspace.txt")
  
  # Skip building if file exists and current workspace matches
  if os.path.isfile(workspace_file) and \
	 os.environ["WORKSPACE"] == open(workspace_file).read().strip():
	print "[buildit.py] Using prebuilt tools"
	return
  
  tools_path = os.path.join(os.environ["WORKSPACE"], "BaseTools")
  
  # Clean build tools if it already exists
  if not os.path.isdir(os.path.join(os.environ["WORKSPACE"],"BaseTools","Source","C", "bin")):
	subprocess.call(["make", "-C", tools_path, "clean"])
  
  print "[buildit.py] Building tools..."
  subprocess.call(["make", "-C", tools_path])
  # write workspace to file
  with open(workspace_file, 'w') as wsf:
	wsf.write(os.environ["WORKSPACE"])
  print "Done"

##############################################################################
# image_version_setup
##############################################################################
def image_version_setup(target, variant):
  image_version_dir = os.path.join(os.environ['WORKSPACE'], 'QcomPkg', 'Library', 'ImageVersionLib')
  image_version_builder = os.path.join(os.environ['WORKSPACE'], 'QcomPkg', 'Tools', 'scripts', 'version_builder.py')
  
  version_files = [os.path.join(image_version_dir, 'oem_version.c'),
				   os.path.join(image_version_dir, 'oem_uuid.c'),
				   os.path.join(image_version_dir, 'qc_version.c')]
				   
  for vf in version_files:
	if os.path.isfile(vf): os.remove(vf)
  
  version_build_cmd = ['python', image_version_builder, 
					   '-t', image_version_dir,
					   '-b', target + variant]
  curr_dir = os.getcwd()
  os.chdir(os.environ["WORKSPACE"])
  print "[buildit.py] Generating image version file..."
  
  if platform.system() == "Windows":
	print "\tPlease be patient. This step may take a while on Windows machines..."
  
  try:
	subprocess.check_call(version_build_cmd)
  except Exception as error:
	if error.returncode == 1:
	  raise NameError("ERROR: buildit::image_version_setup:" + \
					  "image version setup failed.")
	elif error.returncode == 2:
	  raise NameError("ERROR: buildit::image_version_setup:" + \
					  "image version setup failed with following error: " + \
					  "manifest.xml not found!")
  
  for vf in version_files:
	if not os.path.isfile(vf):
	  print "\nError: Image Version File not generated"
	  raise NameError("ERROR buildit::image_version_setup:" + \
					  "image version setup failed to genearte file: " + vf)
  print "Done"

##############################################################################
# copy_intermediate_files
##############################################################################

def copy_intermediate_files(output_dir_root, flavor, release_mode, flag):
	print "*******\n[buildit] Copying binaries to QcomBinPkg:"
	if not os.path.isdir(output_dir_root):
		os.makedirs(output_dir_root)

	if flag == "create_intermediate_core":
	  # get dsc filename
	  dsc_file = ""
	  arch = ""
	  for item in flavor.dsc_list:
		if "Core" in item[0]:
		  (dsc_file,arch) = (item[0], item[1])
		  break 

	  # Get target dir and source dir for EFI copy
	  target_dir = os.path.basename(dsc_file.split(".dsc")[0])
	  r = re.search(r'(Msm\d{4})(.*)(_.*)', target_dir)
	  if r is not None:
		  target_dir = r.group(1) + flavor.variant + r.group(3)
	  else:
		  print "Could not find target directory."
		  return

	  # construct efi source dir path
	  source_dir_efis = os.path.join(os.environ["WORKSPACE"], "Build", target_dir, release_mode +
										   "_" + arch_to_compiler(arch, dsc_file), arch, "*.efi")

	  # delete old efi's and inf's
	  filelist = glob.glob(os.path.join(output_dir_root, "*.efi")) + glob.glob(os.path.join(output_dir_root, "*.inf"))
	  for f in filelist:
		  os.remove(f)

	  # Get list of Qcom packages
	  dsc_fd = open(dsc_file)
	  dsc_contents = dsc_fd.read()
	  dsc_fd.close()
	  dsc_components = dsc_contents.split("[Components.common]")[1]
	  dsc_components_qcom = re.findall(r'([^#|]QcomPkg/[\w/]+\.inf)', dsc_components)
	  for index in range(len(dsc_components_qcom)):
		  inf_filepath_list = dsc_components_qcom[index].split("/")
		  inf_filepath = os.environ["WORKSPACE"]
		  for str in inf_filepath_list:
			  inf_filepath = os.path.join(inf_filepath, str.strip())
		  dsc_components_qcom[index] = find_basename_using_inf(inf_filepath)

	  for file in glob.glob(source_dir_efis):
		  # copy the efi if it is a Qcom package and generate a new INF for it
		  basename = os.path.splitext(os.path.basename(file))[0]
		  if basename in dsc_components_qcom:
			  output_dir_file = os.path.join(output_dir_root, os.path.basename(file))
			  print "[buildit] Copying {0} to {1}".format(file, output_dir_file)
			  inf_location = find_inf_using_basename(basename)
			  try:
				  if inf_location != "":
					  shutil.copy(file, output_dir_file)
			  except:
				  print "[buildit] Could not copy file {0}".format(file)
			  try:
				  if inf_location != "":
					  create_inf(basename, inf_location, output_dir_root, release_mode)
			  except:
				  print "[buildit] Could not create inf for {0}".format(file)

	elif flag == "create_intermediate_loader":
	  # get dsc filename
	  dsc_file = ""
	  arch = ""
	  for item in flavor.dsc_list:
		if "Loader" in item[0]:
		  (dsc_file,arch) = (item[0], item[1])
		  break 

	  target_dir = os.path.basename(dsc_file.split(".dsc")[0])
	  r = re.search(r'(Msm\d{4})(.*)(_.*)', target_dir)
	  if r is not None:
		  target_dir = r.group(1) + "_Loader"
		  target_dir_pkg = r.group(1) + r.group(2)
	  else:
		  print "Could not find target directory."
		  return

	  source_dll_root = os.path.join(os.environ["WORKSPACE"], "Build", target_dir, release_mode +
									 "_" + arch_to_compiler(arch, dsc_file), arch)

	  source_mbn_root = os.path.join(os.environ["WORKSPACE"], "QcomPkg", target_dir_pkg, "Library", "XBL_SEC")

	  for p in [source_dll_root, source_mbn_root]:
		  for root, dirnames, filenames in os.walk(p):
			  for dll in fnmatch.filter(filenames, '*.dll') + fnmatch.filter(filenames, '*.mbn'):
				  match = os.path.join(root, dll)
				  basename = os.path.basename(match)
				  output_dir_file = os.path.join(output_dir_root, basename)
				  print "[buildit] Copying {0} to {1}".format(match, output_dir_file)
				  try:
					  shutil.copy(match, output_dir_file)
				  except:
					  print "[buildit] Could not copy file {0}".format(match)

##############################################################################
# create_inf
##############################################################################

def create_inf(filename, initial_inf, copy_location, release_mode):
	filepath = os.path.join(copy_location, os.path.basename(initial_inf))
	# first create file
	newfile = open(filepath, 'w+')

	# open and read existing inf
	oldfile = open(initial_inf, 'r')
	oldfile_contents = oldfile.read()

	# header
	newfile.write(INF_HEADER.replace("FILENAME", os.path.basename(initial_inf)))

	# defines
	newfile.write("[Defines]\n")
	new_defines = (oldfile_contents.split("[Defines]")[1]).split("[")[0]
	for line in new_defines.split("\n"):
		if "ENTRY_POINT" not in line and "#" not in line:
			newfile.write(line + "\n")
	newfile.write("\n")

	# binaries
	newfile.write("[Binaries]\n")
	newfile.write("\t{0}|{1}|{2}\n\n".format("PE32", os.path.basename(filename)+".efi", release_mode.upper()))
	newfile.close()

##############################################################################
# find_inf_using_basename
##############################################################################

def find_inf_using_basename(basename):
	root_folder = os.path.join(os.environ["WORKSPACE"], "QcomPkg")
	for root, dirnames, filenames in os.walk(root_folder):
		for inf in fnmatch.filter(filenames, '*.inf'):
			match = os.path.join(root, inf)
			inf_fd = open(match)
			inf_contents = inf_fd.read()
			r = re.search(r'(BASE_NAME\s+=\s+)(\w+)', inf_contents)
			if r is not None:
				temp_basename = r.group(2)
			if temp_basename == basename:
				inf_fd.close()
				return match
			inf_fd.close()
	return ""

##############################################################################
# find_inf_using_basename
##############################################################################

def find_basename_using_inf(inf):
	inf_fd = open(inf)
	inf_contents = inf_fd.read()
	r = re.search(r'(BASE_NAME\s+=\s+)(\w+)', inf_contents)
	if r is not None:
		return r.group(2)
	return ""

if __name__ == "__main__":
	main()

