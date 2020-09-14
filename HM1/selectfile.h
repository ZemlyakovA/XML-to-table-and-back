#ifndef SLECTFILE_H
#define SLECTFILE_H

#include "student.h"
#include <QMap>
#include <QFile>
#include <QMessageBox>
#include "QStandardItem"
#include <QFileDialog>
#include <QXmlStreamReader>

class SelectFile
{
public:
    SelectFile();

    void readFile(QMap<qint8, Student> &map);

    QString path;
};

#endif // SLECTFILE_H
