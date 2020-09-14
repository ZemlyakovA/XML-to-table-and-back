#include "mainwindow.h"
#include "savefile.h"
#include "selectfile.h"
#include "studentmodel.h"
#include "addstudent.h"
#include "ui_mainwindow.h"
#include "QStandardItemModel"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    _model = new StudentModel(this);

    ui->tableView->setModel(_model);

    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    //    QMap<qint8, Student> student;
    //    student.insert(0, Student("Земляков А А", "17Б0278", "БИСО-01-17"));
    //    student.insert(1, Student("Карпеченко Д С", "17Б0111", "БИСО-01-17"));
    //    student.insert(2, Student("Демидов И В", "17Б0228", "БИСО-01-17"))



    //    _model->setStudents(student);
    //    ui->tableView->setModel(_model);

    //    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    //    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    //    ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    //    ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SaveInFile_triggered()
{
    SaveFile file;
    QMap<qint8, Student> *student = new QMap<qint8, Student>;
    *student = _model->getStudents();
    file.writeFile(student);
}

void MainWindow::on_SelectFile_triggered()
{
    _model = new StudentModel(this);
    QMap<qint8, Student> student;

    SelectFile *outFile = new SelectFile();
    outFile->readFile(student);

    _model->setStudents(student);
    ui->tableView->setModel(_model);

}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    const QAbstractItemModel *model = index.model();
    if (model == NULL)
    {
        return;
    }
    else
    {
        QMap<qint8, Student> student;
        student = _model->getStudents();
        AddStudent  *myform = new AddStudent();
        myform->setData(student.find(index.row())->fio(),
                        student.find(index.row())->group(),
                        student.find(index.row())->zach());

        if (myform->exec() == QDialog::Accepted)
        {

        }
        else
        {
            if (myform->delReturn())
            {
                foreach (qint8 key, student.keys())

                {
                    if (key >= index.row() and key < student.size()-1)
                        student.insert(key, Student(student.find(key+1).value().fio(), student.find(key+1).value().group(), student.find(key+1).value().zach()));
                }
                student.remove(student.size()-1);

                _model->setStudents(student);
                ui->tableView->setModel(_model);
            }
            else
                if (!myform->getData().fio().isEmpty() and !myform->getData().group().isEmpty() and !myform->getData().zach().isEmpty())
                {
                    student.insert(index.row(), Student(myform->getData().fio(), myform->getData().group(), myform->getData().zach()));
                    _model->setStudents(student);
                    ui->tableView->setModel(_model);
                }

            delete myform;
        }
    }
}

void MainWindow::on_NewStudent_triggered()
{
    AddStudent  *myform = new AddStudent();
    if (myform->exec() == QDialog::Accepted)
    {

    }
    else
    {
        if (!myform->getData().fio().isEmpty() and !myform->getData().group().isEmpty() and !myform->getData().zach().isEmpty())
        {
            QMap<qint8, Student> *student = new QMap<qint8, Student>;
            *student = _model->getStudents();
            *student->insert(student->size(), Student(myform->getData().fio(), myform->getData().group(), myform->getData().zach()));

            _model->setStudents(*student);
            ui->tableView->setModel(_model);

            delete student;
        }
        delete myform;
    }
}
