#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lcd->SetRow(4);
    ui->lcd->SetColumn(20);

   // ui->lcd->setFixedHeight(ui.lcd.get)
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionSave_Image_triggered()
{

}

void MainWindow::on_action_Exit_triggered()
{
    this->close();
}

void MainWindow::on_button1_clicked()
{

}

void MainWindow::on_button2_clicked()
{

}

void MainWindow::on_button3_clicked()
{

}
