#include "studentmodel.h"

StudentModel::StudentModel(QObject *parent) : QAbstractListModel(parent)
{

}

int StudentModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return _students.size(); // сделаем фиксированно 5 строк в таблице
    //если вы станете использовать скажем QList, то пишите return list.size();
}
int StudentModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 4; // количество колонок сделаем также фиксированным
}

QVariant StudentModel::data(const QModelIndex &index, int role) const
{

    if (role == Qt::DisplayRole) {
        switch (index.column()) {
            case 0: return QVariant(_students.find(index.row()).key());
            case 1: return QVariant(_students.find(index.row())->fio());
            case 2: return QVariant(_students.find(index.row())->group());
            case 3: return QVariant(_students.find(index.row())->zach());
        }
    }
    return QVariant();
}

QVariant StudentModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole){
            return QVariant();
        }

        if (orientation == Qt::Horizontal){
            switch (section)
            {
            case id:
                return  QStringLiteral("ID");
            case fio:
                return  QStringLiteral("ФИО");
            case zach:
                return  QStringLiteral("Группа");
            case group:
                return  QStringLiteral("Шифр");
            default:
                return QVariant();
            }
        }
        return QVariant();
}


void StudentModel::setStudents(const QMap<qint8, Student> &students)
{
    beginResetModel();
    _students = students;
    endResetModel();
}

QMap<qint8, Student> StudentModel::getStudents()
{
    return _students;
}




