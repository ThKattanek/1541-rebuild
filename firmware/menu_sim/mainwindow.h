#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "../menu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void StartMenue();
    void MainLoopSimulation();

    void on_actionSave_Image_triggered();
    void on_action_Exit_triggered();

    void on_button1_pressed();

    void on_button1_released();

    void on_button2_pressed();

    void on_button2_released();

    void on_button3_pressed();

    void on_button3_released();

private:
    Ui::MainWindow *ui;

    QTimer timer1;
    uint8_t current_keycode;
};
#endif // MAINWINDOW_H
