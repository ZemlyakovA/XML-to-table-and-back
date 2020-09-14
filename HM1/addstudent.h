#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <QDialog>
#include "student.h"

namespace Ui {
class AddStudent;
}

class AddStudent : public QDialog
{
    Q_OBJECT

public:
    explicit AddStudent(QWidget *parent = nullptr);
    ~AddStudent();

    void setData(QString name, QString group, QString zach);

    Student getData();
    bool delReturn();

private slots:
    void on_ADD_clicked();

    void on_Exit_clicked();

    void on_Delete_clicked();

private:
    Ui::AddStudent *ui;

    Student *_student = new Student();
    bool del = false;
};

#endif // ADDSTUDENT_H
