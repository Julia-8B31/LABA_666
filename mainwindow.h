#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QListWidget>
#include <QLabel>
#include "dialog_form.h"
#include "info_form.h"
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateList();
    QString convert_time();
    void deleteitem();

private slots:
    void deletebtn_clicked();


private:
    Ui::MainWindow *ui;
    std::vector<Audio*> items;
    int total_duration=0;

    QLabel *duration_info;
    QPushButton *addbtn;
    QPushButton *editbtn;
    QPushButton *deletebtn;
    QListWidget *list;
};
#endif // MAINWINDOW_H
