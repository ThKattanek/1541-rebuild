#ifndef GUI_CONSTANCY_H
#define GUI_CONSTANCY_H

#define TIMEOUT1_KEY2 15    // 15 * 50ms = 750ms
#define TIMEOUT2_KEY2 60    // 60 * 50ms = 3s

enum INPUT_MODE{INPUT_MODE_BUTTON, INPUT_MODE_ENCODER};
enum KEY_CODES{KEY0_DOWN, KEY0_UP, KEY1_DOWN, KEY1_UP, KEY2_DOWN, KEY2_UP, KEY2_TIMEOUT1, KEY2_TIMEOUT2, NO_KEY};
enum GUI_MODE{GUI_INFO_MODE, GUI_MENU_MODE, GUI_FILE_BROWSER};

// config of Display texts
#define disp_newinputmode_p   1,1
#define disp_newinputmode_s   "New Input Mode"

#define disp_inputmode_p      4,2
#define disp_encodermode_s    "Encoder Mode"
#define disp_buttonmode_s     "Button  Mode"

#define disp_wait4sdcard_p    0,1
#define disp_wait4sdcard_s    "Wait for SD-Card"

#define disp_tracktxt_p       0,0
#define disp_tracktxt_s       "Track:"
#define disp_trackno_p        7,0

#define disp_motortxt_p       0,1
#define disp_motortxt_s       "Motor: "
#define disp_motorstatus_p    7,1
#define disp_on_s             "On "
#define disp_off_s            "Off"

#define disp_writeprottxt_p   12,0
#define disp_writeprottxt_s   "WP: "

#define disp_scrollfilename_p 0,3
#define disp_nofilemounted_s  "  No Image Mounted  "
#define disp_unsupportedimg_p 0,1
#define disp_unsupportedimg_s "Not Supported Image!"

#define disp_errormsg_p       0,3
#define disp_errormsgempty_p  "                    "
#define disp_errsdrawinit_s   "err: sd_raw_init"
#define disp_errpartopen_s    "err: partition_open"
#define disp_errfatopen_s     "err: fat_open"
#define disp_errfatopenroot_s "err: fat_open_root"

#define disp_versiontxt_p     1,0
#define disp_versiontxt_s     "-- 1541-rebuild --"
#define disp_firmwaretxt_p    2,1
#define disp_firmwaretxt_s    "Firmware:  "
#define disp_authortxt_p      0,3
#define disp_authortxt_s      "by thorsten kattanek"

#define disp_sdinfo_manuf_p   0,0
#define disp_sdinfo_manuf_s   "MANUFACT.: "
#define disp_sdinfo_oem_p     0,1
#define disp_sdinfo_oem_s     "OEM      : "
#define disp_sdinfo_prod_p    0,2
#define disp_sdinfo_prod_s    "PRODUCT  : "
#define disp_sdinfo_size_p    0,3
#define disp_sdinfo_size_s    "SIZE     : "
#define disp_sdinfo_rev_p     0,0
#define disp_sdinfo_rev_s     "REVISION : "
#define disp_sdinfo_serial_p  0,1
#define disp_sdinfo_serial_s  "SERIALNR.: "
#define disp_sdinfo_part_p    0,2
#define disp_sdinfo_part_s    "PARTITION: "

#define disp_geterr_failure_p 0,1
#define disp_geterr_failure_s "Error: Get Failure"
#define disp_sdrawgetinfo_p   0,2
#define disp_sdrawgetinfo_s   "sd_raw_get_info"

#endif // GUI_CONSTANCY_H
