/*
 * Kickstart: A utility for uploading MSM images using the "DMSS-DL"
 * and Sahara protocols
 *
 * Copyright (C) 2010,2016, 2018 Qualcomm Technologies, Inc. All rights reserved.
 *                    Qualcomm Technologies Proprietary/GTDR
 *
 * All data and information contained in or disclosed by this document is
 * confidential and proprietary information of Qualcomm Technologies, Inc. and all
 * rights therein are expressly reserved.  By accepting this material the
 * recipient agrees that this material and the information contained therein
 * is held in confidence and in trust and will not be used, copied, reproduced
 * in whole or in part, nor its contents revealed in any manner to others
 * without the express written permission of Qualcomm Technologies, Inc.
 *
 *
 *  kickstart.c : Tool for uploading MSM images using "DMSS-DL" and Sahara protocols.
 * ==========================================================================================
 *   $Header: //components/rel/boot.xf/1.4/QcomPkg/Tools/storage/fh_loader/QSaharaServer/src/kickstart.c#3 $
 *   $DateTime: 2018/09/12 03:44:02 $
 *   $Author: pwbldsvc $
 *
 *  Edit History:
 *  YYYY-MM-DD       who     why
 *  -----------------------------------------------------------------------------
 *  2016-10-10       sj		 Added supported for taking multiple command and changing the image transfer mode.
 *  2016-04-20       wek     Add support to send reset state machine to the target.
 *  2016-04-20       wek     Print warning if the com port does not start with \\.\
 *  2010-09-28       ng      Added command mode support
 *  2010-10-18       ab      Added memory debug mode support
 *
 *
 *==========================================================================================
 */

#include "common_protocol_defs.h"
#include "comm.h"
#include "sahara_protocol.h"
#include "kickstart_utils.h"
#include "kickstart_log.h"
#ifdef WINDOWSPC
#include "windows_utils.h"
#endif

// Unfortunately, VC2010 doesn't support member-wise initialization
// unlike some compilers
kickstart_options_t kickstart_options = {
    "",   // path_to_save_files
    "",   // saved_file_prefix
    10,   // port_connect_retries
	0     // verbose
};

void usage(char *program_name)
{
	printf("Binary build date: %s @ %s\n", __DATE__, __TIME__);
	printf("Built %s %s\n",__DATE__,__TIME__);
	show_sahara_mapping_list();
	show_search_paths();
    printf("Usage options:\n");
    printf(
			" -h                     --help                      Brings up this help message\n"
			" -p <port name>         --port <port name>          COM Port / TTY device to use. Example /dev/ttyUSB0 or \\\\.\\COM5\n"
			" -v <numeric level>     --verbose <numeric level>   Print verbose messages\n"
			" -c <command_id>        --command                   Force Sahara command mode\n"
            " -m                     --memdump                   Force Sahara memory debug mode\n"
			" -i                     --image                     Force Sahara image transfer mode\n"
			" -s <img_id:file_name>  --sahara <img_id:file_name> Specify Sahara protocol file mapping\n"
			" -g <prefix>            --prefix <prefix>           Specify prefix to use on files received from target\n"
			" -w <path>              --where <path>              Path to store files received from target\n"
			" -r <image ID>          --ramdumpimage <image ID>   Image ID which must be transferred before forcing Sahara memory dump mode\n"
            " -l                     --efssyncloop               At the end of the Sahara state machine loop back to the beginning\n"
			" -t <timeout>           --rxtimeout <timeout>       Timeout for which to wait for data from the port\n"
			" -j <# bytes>           --maxwrite <# bytes>        Max bytes to write in a single shot to the port\n"
			" -b <path>              --addsearchpath  <path>     Where to look for files\n"
			" -k                     --sendclearstate            Send command to target to reset the Sahara State Machine. Does not work on all targets.\n"
            " -u <port number>       --portnumber <port number>  Specify the port number instead of port file. the string \\\\.\\COM will be added as the port.\n"
			" -x				     --switchimagetx			 Forcefully put the target into image transfer mode after command execution \n"
            "-o                      --nomodereset               After downloading ram dumps, do not switch to any mode, just return. If enabled returns error after downloading dumps.\n"
            " -a <cmd_id:file_path>  --cmdrespfilepath <cmd_id:path> File name with path to save response received for executed command, cmd"
// Option in Android             " -n                     --noreset                   Disable sending the sahara reset PKT\n"
// Option in Android             " -a                     --resettxfail               Send reset to client when image transfer fails, resets are not sent if flag -n or -noreset is set\n"
    );
    printf("\n\nNOTE: Only use -s option if you need to overwrite the default file mappings above"
           "\n\nExample usage: \n"
	       "%s -p \\\\.\\COM19 -s 13:ENPRG9x25.mbn\n"
		   "%s -p \\\\.\\COM19 -s 13:prog_emmc_firehose_8994_lite.mbn -b \\\\harv-ahughes\\dropbox\\Kevin_Builds\\RICK_BOOT.BF.2.3-00181-M8994AAAAANAAB-1_Next\\boot_images\\build\\ms\\bin\\8994\\\n"
           "sudo %s -p /dev/ttyUSB0 -s 11:my_osbl.mbn -s 2:testamss.mbn\n", program_name, program_name, program_name);

    printf(
        "\n\nTo retrieve serial number"
        "\n%s -r 21 -c 1 -w c:\\temp\\PATHFORMDMUPLOADS\\ -p \\\\.\\COM19 -s 16:efs1.bin -s 17:efs2.bin -s 20:efs3.bin -b c:\\temp\\PATHFORMDMUPLOADS\\ -b c:\\fusiononpc\\9x15_images\\"
        "\n\nFor image transfer"
        "\n%s -r 21 -w c:\\temp\\PATHFORMDMUPLOADS\\2d966200\\ -p \\\\.\\COM19 -s 16:m9kefs1 -s 17:m9kefs2 -s 20:efs3.bin -b c:\\temp\\PATHFORMDMUPLOADS\\2d966200\\ -b c:\\fusiononpc\\9x15_images\\ "
        "\n\nFor EFS sync"
        "\n%s -l -m -v 1 -w c:\\temp\\PATHFORMDMUPLOADS\\2d966200\\ -p \\\\.\\COM21 -g m9k1_\n\n", program_name, program_name, program_name);
    return;
}

// Aaron: this is the LATEST. Renamed to QSaharaServer.exe to be more descriptive of what it actually does, which is speaks SAHARA protocol

int main (int argc, char *argv[])
{
    int    option;                                            // holds the option from getopt_long
    char cwd[1024];
    char port_str[16] = "\\.\\COM";
    const char *const short_options = "hp:v:c:mis:g:w:r:lt:j:b:ku:xa:o";  // possible cmd line short options
    const struct option long_options[] = {                    // possible cmd line long options
        { "help",           0, NULL, 'h' },
        { "port",           1, NULL, 'p' },
        { "verbose",        1, NULL, 'v' },
        { "command",        1, NULL, 'c' },
        { "memdump",        0, NULL, 'm' },
        { "image",          0, NULL, 'i' },
        { "sahara",         1, NULL, 's' },
        { "prefix",         1, NULL, 'g' },
        { "where",          1, NULL, 'w' },
        { "ramdumpimage",   1, NULL, 'r' },
        { "efssyncloop",    0, NULL, 'l' },
        { "rxtimeout",      1, NULL, 't' },
        { "maxwrite",       1, NULL, 'j' },
        { "addsearchpath",  1, NULL, 'b' },
        { "sendclearstate", 1, NULL, 'k' },
        { "portnumber",     1, NULL, 'u' },
        { "switchimagetx",  0, NULL, 'x' },
        { "cmdrespfilepath", 1, NULL, 'a' },
        { "nomodereset",    0, NULL, 'o' },
        { NULL,             0, NULL,  0  }
    };

    bool efs_sync = false;
    unsigned int i=0;
    bool   enable_sahara_transfer = false;

	char TempSz[2048] = { 0 };

    printf("Binary build date: %s @ %s\n", __DATE__, __TIME__);

	for (option=0; option < argc; option++)
	{
		strlcpy(TempSz+i,argv[option],strlen( argv[option] ));
		i+=strlen( argv[option] );
		TempSz[i] = ' ';
		i++;
	} // end looping through options

	printf("QSAHARASERVER CALLED LIKE THIS: '%s'",TempSz);

	if (1 == argc) {
		usage(argv[0]);
		return EXIT_SUCCESS;
	}

	if (false == init_search_path_list() || false == init_sahara_mapping_list()) {
		dbg(LOG_ERROR, "Could not initialize.");
		return EXIT_FAILURE;
	}

    /* parse command-line options */
    do {
        option = getopt_long (argc, argv, short_options, long_options, NULL);

        switch (option) {
        case -1:                /* no more option arguments */
            break;

        case 'h':               /* -h or --help */
            usage(argv[0]);
            return EXIT_SUCCESS;

        case 'p':               /* Get the port string name */
            com_port.port_name = optarg;
            break;

        case 'u':               /* Get the port number */
            strlcpy(port_str, "\\\\.\\COM", sizeof(port_str));
            strlcat(port_str, optarg, sizeof(port_str));
            com_port.port_name = port_str;
#ifndef WINDOWSPC
			dbg(LOG_WARN, "Argument -u or --portnumber is inteded for Windows only, port '%s' may be invalid", com_port.port_name);
#endif
            break;

        case 's':               /* -s or --sahara */
            /*add the input to <id,file_name> list*/
            if (false == add_input_to_mapping_list(optarg, true)) {
               dbg(LOG_ERROR, "Failed to add file to file list");
               return EXIT_FAILURE;
            }
            enable_sahara_transfer = true;
            break;

        case 'a':               /* -a or --cmddumppath */
            /*add the input to <id,file_name> list*/
            if (false == add_input_to_mapping_list(optarg, false)) {
                dbg(LOG_ERROR, "Failed to add cmd info to file list");
                return EXIT_FAILURE;
            }
            enable_sahara_transfer = true;
            break;

		case 'b':
            if (false == add_search_path(optarg)) {
               dbg(LOG_ERROR, "Failed to add to search path list");
               return EXIT_FAILURE;
            }
            break;

        case 'i':               /* -i or --image */
            sahara_data.mode = SAHARA_MODE_IMAGE_TX_PENDING;
			enable_sahara_transfer = true;
            break;

        case 'v':               /* -v or --verbose */
            kickstart_options.verbose = atoi(optarg);
            break;

        case 'm':               /* -m or --memdump */
            sahara_data.mode = SAHARA_MODE_MEMORY_DEBUG;
            enable_sahara_transfer = true;
            break;

        case 'r':               /* -r or --ramdumpimage */
            sahara_data.ram_dump_image = atoi(optarg);
			enable_sahara_transfer = true;
            break;

        case 'g':               /* -g or --prefix */
            kickstart_options.saved_file_prefix = optarg;
            break;

        case 'w':               /* -w or --where - path for memory dump */
            kickstart_options.path_to_save_files = optarg;
            break;

        case 'c':               /* -c or --command */
				
			sahara_data.mode = SAHARA_MODE_COMMAND;
			add_sahara_command(atoi(optarg));
			enable_sahara_transfer = true;
            break;

        case 'l':               /* -l or --loop */
            efs_sync = true;
			sahara_data.mode = SAHARA_MODE_MEMORY_DEBUG;
			com_port.rx_timeout = -1;
			enable_sahara_transfer = true;
            break;

        case 't':
            com_port.rx_timeout = atoi(optarg);
            break;

		case 'j':               /* -c or --command */
			com_port.MAX_TO_WRITE = atoi(optarg);
            break;

        case 'k':               /* -k or --sendclearstate */
            sahara_data.clear_state_machine = true;
            break;

		case 'x':
			 dbg(LOG_INFO,"switch to image transfer after done\n");
			 sahara_data.switch_command = true;
			 break;

        case 'o':               /* -o or --nomodereset */
            sahara_data.no_mode_reset = true;
            break;

		default:                /* unknown option. */
            dbg(LOG_ERROR, "unrecognized option: '%c'", option);
            usage (argv[0]);
            return EXIT_FAILURE;
        }
    } while (option != -1);


   if (getcwd(cwd, sizeof(cwd)) != NULL)
       printf("Current working dir: %s\n", cwd);
   else
       printf("getcwd() error");

#ifdef LINUXPC
    strlcat(cwd,"/",sizeof(cwd));
#else
    strlcat(cwd,"\\",sizeof(cwd));
#endif

    add_search_path(cwd);

	show_sahara_mapping_list();

	if (true == enable_sahara_transfer) {
        if (NULL == com_port.port_name) {
            dbg(LOG_ERROR, "Port device name not specified; use -p option.");
            return EXIT_FAILURE;
        }
        else {
            dbg(LOG_INFO, "Port name '%s'", com_port.port_name);
#ifdef WINDOWSPC
            /* Print warning if the com port does not start with \\.\ */
            if (strncmp (com_port.port_name, "\\\\.\\", 4) != 0)
				dbg(LOG_WARN, "Port name in windows typically start with '\\\\.\\' not using it may cause errors. Port '%s'", com_port.port_name);
#endif
        }

        for (i = 0; i < kickstart_options.port_connect_retries; i++) {
            if (true == port_connect(com_port.port_name)) {
                break;
            }
        }
        if (kickstart_options.port_connect_retries == i) {
            dbg(LOG_ERROR, "Could not connect to %s", com_port.port_name);
            return EXIT_FAILURE;
        }

        if (false == sahara_main (efs_sync))
        {
           dbg(LOG_ERROR, "Uploading  Image using Sahara protocol failed\n\n");
           use_wakelock(WAKELOCK_RELEASE);
           port_disconnect();
           return EXIT_FAILURE;
        }
    }

    port_disconnect();
    return EXIT_SUCCESS;
}
