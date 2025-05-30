#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::updateList()
{
    list->clear();
    for (const auto& item : items) {
        QString className = QString::fromStdString(item->getClassName());
        QString name = QString::fromStdString(item->getName());
        list->addItem(className + "  :   " + name);
        //qDebug()<<item->getClassName();
        //qDebug()<<item->getName();
        //list->addItem(QString::fromStdString(item->getName()));
    }
}

QString MainWindow::convert_time()
{
    int totalSeconds = total_duration / 1000;
    int hours = totalSeconds / 3600;
    int minutes = (totalSeconds % 3600) / 60;
    int seconds = totalSeconds % 60;

    return QString("%1:%2:%3")
        .arg(hours, 2, 10, QChar('0'))
        .arg(minutes, 2, 10, QChar('0'))
        .arg(seconds, 2, 10, QChar('0'));
}

void MainWindow::deletebtn_clicked()
{
    QListWidgetItem* current = list->currentItem();
    if (current)
    {
        for (auto it = items.begin(); it != items.end(); ++it)
        {
            qDebug() << "Audio name:" << QString::fromStdString((*it)->getName());
            qDebug() << "Current text:" << current->text();
            std::string r=(*it)->getClassName()+"  :   "+(*it)->getName();
            if (r == current->text().toStdString())
            {
                total_duration =total_duration-(*it)->getDuration();
                duration_info->setText("Duration info:"+convert_time());
                delete *it;//вначале удаляю сам объект
                items.erase(it); //затем остаточный указатль
                break;
            }
        }
        delete list->takeItem(list->row(current));
    }
    qDebug()<<items.size();
}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("audio_player");
    this->setFixedSize(350, 270);
    addbtn = new QPushButton("Add", this);
    addbtn->setGeometry(20, 50, 80, 30);  // x, y, width, height
    connect(addbtn, &QPushButton::clicked, this, [this]() {
        Dialog_form *dialog = new Dialog_form(this);
        dialog->exec();//диалоговое окно открывается и ждет закрытия
        Audio *item=dialog->getItem();
        if(item!=nullptr)//чтобы не брать данные у несущствующих объектов
        {
            items.push_back(item);
            updateList();
            total_duration+=item->getDuration();
            duration_info->setText("Duration info:"+convert_time());
        }
        //qDebug()<<item->getClassName();
        delete dialog;
    });

    editbtn = new QPushButton("Edit", this);
    editbtn->setGeometry(20, 90, 80, 30);
    connect(editbtn, &QPushButton::clicked, this, [this]() {
        QListWidgetItem* current = list->currentItem();
        if (current)
        {
            for (auto it = items.begin(); it != items.end(); ++it)
            {
                std::string r=(*it)->getClassName()+"  :   "+(*it)->getName();
                if (r == current->text().toStdString())
                {
                    Info_form *info_form=new Info_form(this,(*it));
                    info_form->exec();//диалоговое окно открывается и ждет закрытия
                    updateList();
                    delete info_form;
                    qDebug()<<typeid((*it)).name();
                    break;
                }
            }
            int c=0;
            for(auto it = items.begin(); it != items.end(); ++it)
            {
                c+=(*it)->getDuration();
            }
            total_duration=c;
            duration_info->setText("Duration info:"+convert_time());
        }

    });

    deletebtn = new QPushButton("Delete", this);
    deletebtn->setGeometry(20, 130, 80, 30);
    connect(deletebtn,&QPushButton::clicked,this,&MainWindow::deletebtn_clicked);

    list = new QListWidget(this);
    list->setGeometry(110, 50, 215, 150);

    duration_info=new QLabel(this);
    duration_info->setText("Duration info:");
    duration_info->setMinimumSize(120,10);
    duration_info->move(113,205);
}




MainWindow::~MainWindow()
{
    delete ui;

    for (Audio* audio_item : items) {
        delete audio_item;
    }
    items.clear();
}
