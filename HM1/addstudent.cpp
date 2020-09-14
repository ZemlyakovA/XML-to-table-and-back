#include "addstudent.h"
#include "ui_addstudent.h"

#include <QMessageBox>

AddStudent::AddStudent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStudent)
{
    ui->setupUi(this);
    ui->Delete->setVisible(false);
}


AddStudent::~AddStudent()
{
    del = false;
    ui->ADD->setText("Добавить студента");
    delete ui;
    delete _student;
}

void AddStudent::setData(QString name, QString group, QString zach)
{
    ui->nameEDIT->setText(name);
    ui->groupEDIT->setText(group);
    ui->zachEDIT->setText(zach);
    ui->Delete->setVisible(true);
    ui->ADD->setText("Применить редактирование");
}

void AddStudent::on_ADD_clicked()
{
    if ((ui->nameEDIT->text().isEmpty()) or (ui->groupEDIT->text().isEmpty()) or (ui->zachEDIT->text().isEmpty()))
    {
        QMessageBox::warning(nullptr,
                             "Поле(я) не заполнено(ы)",
                             "Не удалость добавить студента",
                             QMessageBox::Ok);
    }
    else
    {
        _student->setFio(ui->nameEDIT->text());
        _student->setGroup(ui->groupEDIT->text());
        _student->setZach(ui->zachEDIT->text());
        this->close();
    }
}

void AddStudent::on_Exit_clicked()
{
    this->close();
}

Student AddStudent::getData()
{

    return *_student;
}

bool AddStudent::delReturn()
{
    return del;
}

void AddStudent::on_Delete_clicked()
{
    del = true;
    this->close();
}
