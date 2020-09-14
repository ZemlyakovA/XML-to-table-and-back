#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QXmlStreamReader>

class Student
{
public:
    Student();
    Student(const QString fio, const QString &zach, const QString &group);

//    friend QXmlStreamReader &operator>>(QXmlStreamReader &stream, Student &student);

    QString fio() const;

    QString zach() const;

    QString group() const;

    void setFio(const QString &fio);

    void setZach(const QString &zach);

    void setGroup(const QString &group);

private:
    QString _fio;
    QString _zach;
    QString _group;
};

#endif // STUDENT_H
