#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "../version.h"
#include "../gui_constants.h"

#include <QFileDialog>
#include <QDebug>

enum  MENU_IDS{M_BACK, M_IMAGE, M_SETTINGS, M_INFO, \
               M_BACK_IMAGE, M_INSERT_IMAGE, M_REMOVE_IMAGE, M_WP_IMAGE, M_NEW_IMAGE, M_SAVE_IMAGE, \
               M_BACK_SETTINGS,M_DEBUG_LED,M_RESTART, \
               M_BACK_INFO, M_VERSION_INFO, M_SDCARD_INFO};

static MENU_STRUCT main_menu;
static MENU_STRUCT image_menu;
static MENU_STRUCT settings_menu;
static MENU_STRUCT info_menu;

/// Menüs einrichten
/// Hauptmenü
MENU_ENTRY main_menu_entrys[] = {{"Back",M_BACK},{"Disk Image",M_IMAGE,ENTRY_MENU,0,&image_menu},{"Settings",M_SETTINGS,ENTRY_MENU,0,&settings_menu},{"Info",M_INFO,ENTRY_MENU,0,&info_menu}};
/// Image Menü
MENU_ENTRY image_menu_entrys[] = {{"Back",M_BACK_IMAGE,ENTRY_TO_PARENT}, {"Insert Image",M_INSERT_IMAGE}, {"Remove Image",M_REMOVE_IMAGE}, {"Write Protect",M_WP_IMAGE,ENTRY_ONOFF,1}, {"New Image",M_NEW_IMAGE}, {"Save Image",M_SAVE_IMAGE}};
/// Setting Menü
MENU_ENTRY settings_menu_entrys[] = {{"Back",M_BACK_SETTINGS,ENTRY_TO_PARENT}, {"Debug LED",M_DEBUG_LED,ENTRY_ONOFF,0}, {"Restart",M_RESTART}};
/// Info Menü
MENU_ENTRY info_menu_entrys[] = {{"Back",M_BACK_INFO,ENTRY_TO_PARENT}, {"Version",M_VERSION_INFO}, {"SD Card Info",M_SDCARD_INFO}};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lcd->SetRow(4);
    ui->lcd->SetColumn(20);

    ui->lcd->Clear();
    ui->lcd->SetCursor( 1, 2);
    ui->lcd->String("-- 1541-rebuild --");
    ui->lcd->SetCursor( 2,3);
    ui->lcd->String("Firmware:  ");
    ui->lcd->String(VERSION);

    current_keycode = NO_KEY;

    main_menu.lcd_cursor_char = 2;  // 126 Standard Pfeil
    menu_init(&main_menu, main_menu_entrys, 4,4);

    image_menu.lcd_cursor_char = 2;  // 126 Standard Pfeil
    menu_init(&image_menu, image_menu_entrys, 6,4);

    settings_menu.lcd_cursor_char = 2;  // 126 Standard Pfeil
    menu_init(&settings_menu, settings_menu_entrys, 3,4);

    info_menu.lcd_cursor_char = 2;  // 126 Standard Pfeil
    menu_init(&info_menu, info_menu_entrys, 3,4);

    menu_set_root(&main_menu);

    // Zeichen für Menü More Top setzen
    uint8_t char00[] = {4,14,31,0,0,0,0,0};
    ui->lcd->SetUserChar(0, char00);

    // Zeichen für Menü More Down setzen
    uint8_t char01[] = {0,0,0,0,31,14,4,0};
    ui->lcd->SetUserChar(1, char01);

    // Zeichen für Menü Position setzen
    uint8_t arrow_char[] = {0,4,6,31,6,4,0,0};
    ui->lcd->SetUserChar(2, arrow_char);

    current_menu = &main_menu;

    QTimer::singleShot(2000, this,SLOT(StartMenue()));

    timer1.setInterval(20);
    connect(&timer1, SIGNAL(timeout()), this, SLOT(MainLoopSimulation()));
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::StartMenue()
{
    ui->lcd->Clear();
    timer1.start();
}

void MainWindow::MainLoopSimulation()
{
    uint16_t ret = menu_update(ui->lcd, current_keycode);
    current_keycode = NO_KEY;

    if(ret >> 8 != MC_NO_COMMAND) qDebug() << "Command:" << (ret >> 8) << " Value: " << (ret & 0x0ff);

    CheckMMenuEvents(ret);
}


void MainWindow::on_actionSave_Image_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),QDir::homePath(),tr("Images (*.png *.xpm *.xbm *.jpg *.jpeg *.bmp *.ppm)"));

    if(fileName != "")
    {
       ui->lcd->SaveImage(fileName);
    }
}

void MainWindow::on_action_Exit_triggered()
{
    this->close();
}

void MainWindow::on_button1_pressed()
{
    current_keycode = KEY0_DOWN;
}

void MainWindow::on_button1_released()
{
    current_keycode = KEY0_UP;
}

void MainWindow::on_button2_pressed()
{
    current_keycode = KEY1_DOWN;
}

void MainWindow::on_button2_released()
{
    current_keycode = KEY1_UP;
}

void MainWindow::on_button3_pressed()
{
    current_keycode = KEY2_DOWN;
}

void MainWindow::on_button3_released()
{
    current_keycode = KEY2_UP;
}

void MainWindow::CheckMMenuEvents(uint16_t menu_event)
{
    uint8_t command = menu_event >> 8;
    uint8_t value = menu_event & 0xff;

    switch(command)
    {
    case MC_SELECT_ENTRY:
        switch(value)
        {
        /// Main Menü
        case M_BACK:
          //  set_gui_mode(GUI_INFO_MODE);
            break;
        case M_IMAGE:
            //current_menu = &image_menu;
            menu_refresh(ui->lcd);
            break;
        case M_SETTINGS:
            //current_menu = &settings_menu;
            menu_refresh(ui->lcd);
            break;
        case M_INFO:
          //  show_start_message();
            menu_refresh(ui->lcd);
            break;

        /// Settings Menü
        case M_DEBUG_LED:
            /*
            if(menu_get_entry_var1(&settings_menu, M_DEBUG_LED))
                debug_led1_on();
            else
                debug_led1_off();
                */
            menu_refresh(ui->lcd);
            break;

        /// Image Menü
        case M_BACK_IMAGE:
            current_menu = &main_menu;
            menu_refresh(ui->lcd);
            break;
        case M_INSERT_IMAGE:
          //  set_gui_mode(GUI_FILE_BROWSER);
            break;
        case M_REMOVE_IMAGE:
          //  remove_image();
          //  set_gui_mode(GUI_INFO_MODE);
            break;
        case M_WP_IMAGE:
            /*
            if(akt_image_type != G64_IMAGE)
                menu_set_entry_var1(&image_menu, M_WP_IMAGE, 1);

            if(menu_get_entry_var1(&image_menu, M_WP_IMAGE))
                set_write_protection(1);
            else
                set_write_protection(0);
                */
            menu_refresh(ui->lcd);

            break;
        }
        break;
    }
}
