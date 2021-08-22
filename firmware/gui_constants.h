#ifndef GUI_CONSTANCY_H
#define GUI_CONSTANCY_H

#define TIMEOUT1_KEY2 15    // 15 * 50ms = 750ms
#define TIMEOUT2_KEY2 60    // 60 * 50ms = 3s

enum INPUT_MODE{INPUT_MODE_BUTTON, INPUT_MODE_ENCODER};
enum KEY_CODES{KEY0_DOWN, KEY0_UP, KEY1_DOWN, KEY1_UP, KEY2_DOWN, KEY2_UP, KEY2_TIMEOUT1, KEY2_TIMEOUT2, NO_KEY};
enum GUI_MODE{GUI_INFO_MODE, GUI_MENU_MODE, GUI_FILE_BROWSER};

// config of Display texts
#define disp_newinputmode_p   1,0
#define disp_newinputmode_s   "New Input Mode"

#define disp_inputmode_p      2,1
#define disp_encodermode_s    "Encoder Mode"
#define disp_buttonmode_s     "Button  Mode"

#define disp_wait4sdcard_p    0,0
#define disp_wait4sdcard_s    "Wait for SD-Card"

#define disp_tracktxt_p       0,0
#define disp_tracktxt_s       "T:"
#define disp_trackno_p        2,0

#define disp_motortxt_p       5,0
#define disp_motor_on_s       "Motor"
#define disp_motor_off_s      "     "

#define disp_writeprottxt_p   11,0
#define disp_writeprot_on_s   "WProt"
#define disp_writeprot_off_s  "     "

#define disp_scrollfilename_p 0,1
#define disp_nofilemounted_s  "No Image Mounted"
#define disp_unsupportedimg_p 0,0
#define disp_unsupportedimg_s "Img unsupported!"

#define disp_errormsg_p       0,1
#define disp_errormsgempty_p  "                "
#define disp_errsdrawinit_s   "err: sd_raw_init"
#define disp_errpartopen_s    "err: part_open"
#define disp_errfatopen_s     "err: fat_open"
#define disp_errfatopenroot_s "err: fatOpenRoot"

#define disp_versiontxt_p     0,0
#define disp_versiontxt_s     "- 1541-rebuild -"
#define disp_firmwaretxt_p    0,1
#define disp_firmwaretxt_s    "Firmware:"
#define disp_authortxt_p      0,0
#define disp_authortxt_s      "orig.by thorsten"
#define disp_authortxt1_p     8,1
#define disp_authortxt1_s     "kattanek"
#define disp_authortxt2_p     0,0
#define disp_authortxt2_s     "enhanced by"
#define disp_authortxt3_p     5,1
#define disp_authortxt3_s     "F00K42"

#define disp_sdinfo_manuf_p   0,0
#define disp_sdinfo_manuf_s   "MANU:"
#define disp_sdinfo_oem_p     8,0
#define disp_sdinfo_oem_s     "OEM: "
#define disp_sdinfo_prod_p    0,1
#define disp_sdinfo_prod_s    ""
#define disp_sdinfo_size_p    8,1
#define disp_sdinfo_size_s    ""
#define disp_sdinfo_rev_p     0,0
#define disp_sdinfo_rev_s     "REV:"
#define disp_sdinfo_serial_p  8,0
#define disp_sdinfo_serial_s  ""
#define disp_sdinfo_part_p    0,1
#define disp_sdinfo_part_s    "P:"

#define disp_geterr_failure_p 0,0
#define disp_geterr_failure_s "Err: Get Failure"
#define disp_sdrawgetinfo_p   0,1
#define disp_sdrawgetinfo_s   "sd_raw_get_info"

#endif // GUI_CONSTANCY_H
