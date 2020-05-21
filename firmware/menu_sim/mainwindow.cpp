#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "../version.h"
#include "../gui_constants.h"

#include <QFileDialog>
#include <QDebug>


static MENU_ENTRY menu_entrys01[] = {{"Punkt1",0},{"Punkt2",1},{"Punkt3",2},{"Punkt4",3},{"Punkt5",4},{"Punkt6",5},{"Punkt7",6},{"Punkt8",7},{"Punkt9",8},{"Punkt10",9}};
static MENU_STRUCT menu1;

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

    // Zeichen für Menü Position setzen
    uint8_t arrow_char[] = {0,4,6,31,6,4,0,0};
    ui->lcd_generatechar(15, arrow_char);
    menu1.lcd_cursor_char = 15;

    menu_init(&menu1, (MENU_ENTRY*) &menu_entrys01, 10, 4);

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
    menu_update(ui->lcd, &menu1,current_keycode);
    current_keycode = NO_KEY;
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
