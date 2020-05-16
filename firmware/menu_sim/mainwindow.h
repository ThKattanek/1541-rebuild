#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_actionSave_Image_triggered();

    void on_action_Exit_triggered();

    void on_button1_clicked();

    void on_button2_clicked();

    void on_button3_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
