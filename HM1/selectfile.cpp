#include "selectfile.h"
#include "student.h"

SelectFile::SelectFile()
{
    if(path.isEmpty())
            path = QFileDialog::getOpenFileName(0, "Open Dialog", "C:\\Users\\User\\Desktop\\3 KURS\\QT\\build-HM1-Desktop_Qt_5_14_1_MinGW_64_bit-Debug", "*.xml");
}

void SelectFile::readFile(QMap<qint8, Student> &map)
{
//    QString filename = QFileDialog::getOpenFileName(nullptr,
//                                                    ("Open Xml"), ".",
//                                                    ("Xml files (*.xml)"));
    QFile file(path);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(nullptr,
                             "Ошибка файла",
                             "Не удалось открыть файл",
                             QMessageBox::Ok);
    }
    else
    {

        QXmlStreamReader xmlReader;
        QStandardItem *item;
        QString name, group, zach;
        xmlReader.setDevice(&file);
        xmlReader.readNext();
        qint16 i = 0;
        while(!xmlReader.atEnd())
        {
            if(xmlReader.isStartElement())
            {
                {
                    if(xmlReader.name() == "name")
                    {
                        item = new QStandardItem(QString(xmlReader.readElementText()));
                        name = item->text();

                    } else if (xmlReader.name() == "group"){

                        item = new QStandardItem(QString(xmlReader.readElementText()));
                        group = item->text();
                    } else if (xmlReader.name() == "card"){

                        item = new QStandardItem(QString(xmlReader.readElementText()));
                        zach = item->text();
                        Student *student = new Student(name, group, zach);
                        map.insert(i, Student(student->fio(), student->group(), student->zach()));
                        delete (student);
                        i++;
                    }
                }
            }
            xmlReader.readNext();

        }
        file.close();

    }
}
