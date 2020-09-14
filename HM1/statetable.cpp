#include "statetable.h"

StateTable::StateTable()
{

}

QMap<qint8, Student> StateTable::students() const
{
    return _students;
}

void StateTable::setStudents(const QMap<qint8, Student> &student)
{
    _students.insert(student);
}
