#ifndef STUDENTMODEL_H
#define STUDENTMODEL_H

#include <QObject>
#include <QAbstractItemModel> //деревья
#include <QAbstractTableModel> //таблицы
#include <QAbstractListModel> //список

#include "student.h"
class StudentModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit StudentModel(QObject *parent = nullptr);

    void setStudents(const QMap<qint8, Student> &students);

    QMap<qint8, Student> getStudents();



signals:

public slots:

private:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section,Qt::Orientation orientation,int role=Qt::DisplayRole) const;

    enum Column{
        id,
        fio,
        zach,
        group
    };


    QMap<qint8, Student> _students;
};

#endif // STMODEL_H
