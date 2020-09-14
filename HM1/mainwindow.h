#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "studentmodel.h"



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

    void on_SelectFile_triggered();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_SaveInFile_triggered();

    void on_NewStudent_triggered();

private:
    Ui::MainWindow *ui;

    StudentModel * _model;
};
#endif // MAINWINDOW_H
