#include "student.h"

Student::Student()
{

}

Student::Student(const QString fio, const QString &zach, const QString &group)
{
    _fio = fio;
    _zach = zach;
    _group = group;
}

//QXmlStreamReader &operator>>(QXmlStreamReader &stream, Student &student)
//{
//    stream = student._fio = student._group >>student._zach  ;//>> student.stud["fio"] >> student.stud["shifr"];
//    return stream;

//}

QString Student::fio() const
{
    return _fio;
}

QString Student::zach() const
{
    return _zach;
}

QString Student::group() const
{
    return _group;
}

void Student::setFio(const QString &fio)
{
    _fio = fio;
}

void Student::setZach(const QString &zach)
{
    _zach = zach;
}

void Student::setGroup(const QString &group)
{
    _group = group;
}
