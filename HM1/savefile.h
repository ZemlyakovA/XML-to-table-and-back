#ifndef SAVEFILE_H
#define SAVEFILE_H

#include "student.h"
#include <QFile>
#include <QMap>

#include <QMainWindow>
#include <QFileDialog>
#include <QXmlStreamWriter>

#include <QXmlStreamAttribute>
#include <QMessageBox>


class SaveFile
{
public:
    QString FileName;

    SaveFile();

    void writeFile(QMap<qint8, Student> *map);
};

#endif // SAVEFILE_H
