#include "dialog_form.h"

Dialog_form::Dialog_form(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Additional form");
    this->setFixedSize(200, 250);

    addbtn=new QPushButton("Add", this);
    addbtn->setGeometry(10, 200, 80, 30);
    connect(addbtn,&QPushButton::clicked,this,&Dialog_form::addbtn_clicked);

    cancelbtn=new QPushButton("Cancel", this);
    cancelbtn->setGeometry(110, 200, 80, 30);
    connect(cancelbtn, &QPushButton::clicked, this, &QDialog::close);

    classlabel=new QLabel(this);
    classlabel->setText("Class:");
    classlabel->setMinimumSize(30,10);
    classlabel->move(10,20);

    combo_classes=new QComboBox(this);
    combo_classes->addItem("Song");
    combo_classes->addItem("AudioMessage");
    combo_classes->addItem("AudioBook");
    combo_classes->insertItem(0, "");  // пустая строка
    combo_classes->setCurrentIndex(0); // выбран пустой элемент
    combo_classes->setGeometry(70, 18, 120, 22);

    namelabel=new QLabel(this);
    namelabel->setText("Name:");
    namelabel->setMinimumSize(30,10);
    namelabel->move(10,50);

    inputname=new QLineEdit(this);
    inputname->setGeometry(70, 50, 120, 20);


    authorlabel=new QLabel(this);
    authorlabel->setText("Author:");
    authorlabel->setMinimumSize(30,10);

    inputauthor=new QLineEdit(this);

    durationlabel=new QLabel(this);
    durationlabel->setText("Duration:");
    durationlabel->setMinimumSize(30,10);

    inputduration=new QLineEdit(this);

    genrelabel_song=new QLabel(this);
    genrelabel_song->setText("Genre:");
    genrelabel_song->setMinimumSize(30,10);

    inputgenre_song=new QLineEdit(this);

    albumlabel_song=new QLabel(this);
    albumlabel_song->setText("Album:");
    albumlabel_song->setMinimumSize(30,10);

    inputalbum_song=new QLineEdit(this);



    textDesclabel_book=new QLabel(this);
    textDesclabel_book->setMinimumSize(30,10);
    textDesclabel_book->setText("Description:");

    inputbookdescr=new QLineEdit(this);

    voiceArtistslabel_book=new QLabel(this);
    voiceArtistslabel_book->setMinimumSize(30,10);
    voiceArtistslabel_book->setText("VoiceArtist:");

    inputvoiceartist=new QLineEdit(this);


    authorlabel->hide();
    durationlabel->hide();
    genrelabel_song->hide();
    albumlabel_song->hide();
    textDesclabel_book->hide();
    voiceArtistslabel_book->hide();

    inputauthor->hide();
    inputduration->hide();
    inputalbum_song->hide();
    inputgenre_song->hide();
    inputbookdescr->hide();
    inputvoiceartist->hide();


    connect(combo_classes, &QComboBox::currentTextChanged, this, [=](const QString &text){
        authorlabel->hide();
        durationlabel->hide();
        genrelabel_song->hide();
        albumlabel_song->hide();
        textDesclabel_book->hide();
        voiceArtistslabel_book->hide();

        inputauthor->hide();
        inputduration->hide();
        inputalbum_song->hide();
        inputgenre_song->hide();
        inputbookdescr->hide();
        inputvoiceartist->hide();

        if (text == "Song")
        {

            authorlabel->move(10,80);
            authorlabel->show();

            inputauthor->setGeometry(70, 80, 120, 20);
            inputauthor->show();

            durationlabel->move(10,110);
            durationlabel->show();

            inputduration->setGeometry(70, 110, 120, 20);
            inputduration->show();

            genrelabel_song->move(10,140);
            genrelabel_song->show();

            inputgenre_song->setGeometry(70, 140, 120, 20);
            inputgenre_song->show();

            albumlabel_song->move(10,170);
            albumlabel_song->show();

            inputalbum_song->setGeometry(70, 170, 120, 20);
            inputalbum_song->show();
        }

        else if (text == "AudioMessage")
        {
            authorlabel->move(10,80);
            authorlabel->show();

            inputauthor->setGeometry(70, 80, 120, 20);
            inputauthor->show();

            durationlabel->move(10,110);
            durationlabel->show();

            inputduration->setGeometry(70, 110, 120, 20);
            inputduration->show();

        }

        else if (text == "AudioBook")
        {
            authorlabel->move(10,80);
            authorlabel->show();

            inputauthor->setGeometry(70, 80, 120, 20);
            inputauthor->show();

            durationlabel->move(10,110);
            durationlabel->show();

            inputduration->setGeometry(70, 110, 120, 20);
            inputduration->show();

            textDesclabel_book->move(10,140);
            textDesclabel_book->show();

            inputbookdescr->setGeometry(70, 140, 120, 20);
            inputbookdescr->show();

            voiceArtistslabel_book->move(10,170);
            voiceArtistslabel_book->show();

            inputvoiceartist->setGeometry(70, 170, 120, 20);
            inputvoiceartist->show();


        }
    });

}

void Dialog_form::addbtn_clicked()
{
    QString selectedClass = combo_classes->currentText();
    QString name = inputname->text();
    QString author = inputauthor->text();
    int duration = inputduration->text()=="" ? 0 :(inputduration->text()).toInt();

    if (selectedClass == "Song" && name!="")
    {

        QString genre =inputgenre_song->text();
        QString album = inputalbum_song->text();

        Song *song=new Song();
        song->settingAudio(author.toStdString(),duration,"",genre.toStdString(),album.toStdString(),name.toStdString());

        item=song;
        //qDebug()<<item->getClassName();
        // qDebug() << "Class: Song";
        // qDebug() << "Name:" << name << ", Author:" << author << ", Duration:" << duration;
        // qDebug() << "Genre:" << genre << ", Album:" << album;
        accept();
    }
    else if (selectedClass == "AudioMessage" && name!="")
    {
        Message *message=new Message();
        message->settingAudio(author.toStdString(),duration,"",name.toStdString());
        item=message;
        //qDebug()<<item->getClassName();
        // qDebug() << "Class: AudioMessage";
        // qDebug() << "Name:" << name << ", Author:" << author << ", Duration:" << duration;
        accept();
    }
    else if (selectedClass == "AudioBook" && name!="")
    {
        QString description = inputbookdescr->text();
        QString voiceArtist = inputvoiceartist->text();

        Book *book=new Book();
        book->settingAudio(author.toStdString(),duration,"",name.toStdString(),description.toStdString(),voiceArtist.toStdString(),{});
        item=book;
        //qDebug()<<item->getClassName();
        // qDebug() << "Class: AudioBook";
        // qDebug() << "Name:" << name << ", Author:" << author << ", Duration:" << duration;
        // qDebug() << "Description:" << description << ", Voice Artist:" << voiceArtist;
        accept();
    }
    else {
        qDebug() << "No class selected!";
    }



}
