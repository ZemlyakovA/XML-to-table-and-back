#ifndef ADDNEWSTUDENT_H
#define ADDNEWSTUDENT_H

#include <QMainWindow>

namespace Ui {
class ui_AddNewStudent;
}

class ui_AddNewStudent : public QMainWindow
{
    Q_OBJECT

public:
    explicit ui_AddNewStudent(QWidget *parent = nullptr);
    ~ui_AddNewStudent();
private:
    Ui::ui_AddNewStudent *ui;
};

#endif // ADDNEWSTUDENT_H
