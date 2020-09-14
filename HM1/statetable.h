#ifndef STATETABLE_H
#define STATETABLE_H

#include "student.h"
#include <QMap>

class StateTable
{
public:
    StateTable();


    QMap<qint8, Student> ReturnStudents (QMap<qint8, Student> &map);

    QMap<qint8, Student> students() const;
    void setStudents(const QMap<qint8, Student> &student);

private:
    QMap<qint8, Student> _students;
};

#endif // STATETABLE_H
