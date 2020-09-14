#include "ui_addnewstudent.h"

ui_AddNewStudent::ui_AddNewStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ui_AddNewStudent)
{
    ui->setupUi(this);
}

AddNewStudent::~AddNewStudent()
{
    delete ui;
}
