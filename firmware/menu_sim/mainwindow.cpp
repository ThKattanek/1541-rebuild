#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "../version.h"

#include <QTimer>

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

    QTimer::singleShot(2000, this,SLOT(StartMenue()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::StartMenue()
{
    ui->lcd->Clear();
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
