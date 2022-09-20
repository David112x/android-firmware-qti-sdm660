#!/bin/bash
Base_path=`pwd`
MY_NAME=`whoami`
LOG_PATH=$Base_path/build_log


mod=$1

function main()
{
    echo "Building $mod"
    if [ x$mod == x"" ] ; then
        echo "Unknown funcion, please use a valid function"
        exit 0
    fi
	if [ ! -d $LOG_PATH ]; then
		mkdir $LOG_PATH
	fi


    if [ x$mod == x"all" ] || [ x$mod == x"ALL" ] ;then
        echo "Building all the firmware"
        # MPSS
        #build_MPSS
	# Building MPSS is commented because of a missing build script in ./modem_proc/build/ms
        # BOOT
        build_BOOT
        # TZ
        build_TZ
        # RPM
        build_RPM
        # ADSP
        build_ADSP 2>&1|tee $LOG_PATH/adsp.log
	#AOP
	build_AOP
        # CDSP
        build_CDSP
        # common
        build_common
    #elif [ x$mod == x"mpss" ] || [ x$mod == x"MPSS" ] ;then
        #build_MPSS
    elif [ x$mod == x"boot" ] || [ x$mod == x"BOOT" ] ;then
        build_BOOT
    elif [ x$mod == x"tz" ] || [ x$mod == x"TZ" ] ;then
        build_TZ
    elif [ x$mod == x"rpm" ] || [ x$mod == x"RPM" ] ;then
        build_RPM
    elif [ x$mod == x"adsp" ] || [ x$mod == x"ADSP" ] ;then
        build_ADSP
	elif [ x$mod == x"cdsp" ] || [ x$mod == x"CDSP" ] ;then
        build_CDSP
	elif [ x$mod == x"common" ] || [ x$mod == x"COMMON" ] ;then
        build_common
  elif [ x$mod == x"clean" ] || [ x$mod == x"CLEAN" ] ;then
		echo "Cleaning"
       cd $Base_path/modem_proc/build/ms
	   ./build.sh sdm660.gen.prod -c

		echo "Cleaning boot"
       cd $Base_path/boot_images/QcomPkg/Sdm660Pkg
       python -u ../buildit.py --variant LA -r RELEASE -t Sdm660Pkg,QcomToolsPkg --build_flags=cleanall

		echo "Cleaning TrustZone"
       cd $Base_path/trustzone_images/build/ms
       python build_all.py -b TZ.BF.4.0 CHIPSET=sdm660 -c

		echo "Cleaning CDSP"
       cd $Base_path/cdsp_proc
       python ./build/build.py -c sdm660 -o clean

		echo "Cleaning RPM"
	   cd $Base_path/rpm_proc/build
	   ./build_660.sh -c

		echo "Cleaning ADSP"
       cd $Base_path/adsp_proc
       python build/build.py -c sdm660 -f ADSP -o clean

    echo "******************************************"
    echo "*             Clean finished             *"
    echo "******************************************"
    exit 0
    
    else
        #echo ""
        exit 0
    fi
    echo "If you compiled Android in the LINUX folder, copy the images to the out directory."
    echo "******************************************"
    echo "*  Run the cpn script after you're done. *"
    echo "******************************************"
}



# MPSS
function build_MPSS()
{
    echo "Building MPSS"
    cd $Base_path/modem_proc/build/ms
    ./build.sh sdm660.gen.prod -c
    ./build.sh sdm660.gen.prod -k
    echo "MPSS build finished."
}

# BOOT
function build_BOOT()
{
    echo "Building bootloader"
	cd $Base_path/boot_images/QcomPkg/Sdm660Pkg
	python -u ../buildit.py --variant LA -r RELEASE -t Sdm660Pkg,QcomToolsPkg --build_flags=cleanall
    python -u ../buildit.py --variant LA -r RELEASE -t Sdm660Pkg,QcomToolsPkg
    echo "BOOT build finished."
}

# TZ
function build_TZ()
{
    echo "Building TrustZone Images"
    cd $Base_path/trustzone_images/build/ms
	python build_all.py -b TZ.BF.4.0 CHIPSET=sdm660 -c
	python build_all.py -b TZ.BF.4.0 CHIPSET=sdm660 devcfg sampleapp
    echo "TZ build finished."
}

# RPM
function build_RPM()
{
    echo "Building RPM"
    cd $Base_path/rpm_proc/build
    ./build_660.sh -c
    ./build_660.sh
    echo "RPM build finished."
}

# CDSP
function build_CDSP()
{
    echo "Building CDSP"
    cd $Base_path/cdsp_proc
	python ./build/build.py -c sdm660 -o clean
	python ./build/build.py -c sdm660 -o all
    echo "CDSP build finished."
}

# common
function build_common()
{
    echo "Building common"

    cd $Base_path/common/build
	python build.py --nonhlos  
    echo "Common build finished."
}

# ADSP
function build_ADSP()
{
    echo "Building ADSP"
    cd $Base_path/adsp_proc
    python build/build.py -c sdm660 -f ADSP -o clean
    python build/build.py -c sdm660 -f ADSP -o all
    echo "ADSP build finished."
}

main $1
