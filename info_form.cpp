#include "info_form.h"

void Info_form::editbtn_clicked(Audio *item)
{
    QString name = inputname->text();
    QString author = inputauthor->text();
    int duration = inputduration->text()=="" ? 0 :(inputduration->text()).toInt();

    if (auto song = dynamic_cast<Song*>(item))
    {
        QString genre =inputgenre_song->text();
        QString album = inputalbum_song->text();
        song->settingAudio(author.toStdString(),duration,"",genre.toStdString(),album.toStdString(),name.toStdString());
        accept();
    }
    else if (auto message = dynamic_cast<Message*>(item))
    {
        message->settingAudio(author.toStdString(),duration,"",name.toStdString());
        accept();
    }
    else if (auto book = dynamic_cast<Book*>(item))
    {
        QString description = inputbookdescr->text();
        QString voiceArtist = inputvoiceartist->text();

        book->settingAudio(author.toStdString(),duration,"",name.toStdString(),description.toStdString(),voiceArtist.toStdString(),{});
        accept();
    }
    else {
        qDebug() << "unexpected mistake!";
    }
}


Info_form::Info_form(QWidget *parent,Audio *item) : QDialog(parent)
{
    setWindowTitle("Editable form");
    this->setFixedSize(200, 250);


    editbtn=new QPushButton("Edit", this);
    editbtn->setGeometry(10, 200, 80, 30);
    connect(editbtn, &QPushButton::clicked, this, [this, item]() {
        editbtn_clicked(item);
    });


    cancelbtn=new QPushButton("Cancel", this);
    cancelbtn->setGeometry(110, 200, 80, 30);
    connect(cancelbtn, &QPushButton::clicked, this, &QDialog::close);


    classlabel=new QLabel(this);
    classlabel->setText("Class:  "+QString::fromStdString(item->getClassName()));
    classlabel->setMinimumSize(30,10);
    classlabel->move(10,20);

    namelabel=new QLabel(this);
    namelabel->setText("Name:");
    namelabel->setMinimumSize(30,10);
    namelabel->move(10,50);

    inputname=new QLineEdit(this);
    inputname->setGeometry(70, 50, 120, 20);
    inputname->setText(QString::fromStdString(item->getName()));

    authorlabel=new QLabel(this);
    authorlabel->setText("Author:");
    authorlabel->setMinimumSize(30,10);
    authorlabel->move(10,80);

    inputauthor=new QLineEdit(this);
    inputauthor->setGeometry(70, 80, 120, 20);
    inputauthor->setText(QString::fromStdString(item->getAuthor()));

    durationlabel=new QLabel(this);
    durationlabel->setText("Duration:");
    durationlabel->setMinimumSize(30,10);
    durationlabel->move(10,110);

    inputduration=new QLineEdit(this);
    inputduration->setGeometry(70, 110, 120, 20);
    inputduration->setText(QString::number(item->getDuration()));

    genrelabel_song=new QLabel(this);
    genrelabel_song->setText("Genre:");
    genrelabel_song->setMinimumSize(30,10);
    genrelabel_song->move(10,140);

    inputgenre_song=new QLineEdit(this);
    inputgenre_song->setGeometry(70, 140, 120, 20);

    albumlabel_song=new QLabel(this);
    albumlabel_song->setText("Album:");
    albumlabel_song->setMinimumSize(30,10);
    albumlabel_song->move(10,170);

    inputalbum_song=new QLineEdit(this);
    inputalbum_song->setGeometry(70, 170, 120, 20);

    textDesclabel_book=new QLabel(this);
    textDesclabel_book->setText("Description:");
    textDesclabel_book->setMinimumSize(30,10);
    textDesclabel_book->move(10,140);

    inputbookdescr=new QLineEdit(this);
    inputbookdescr->setGeometry(70, 140, 120, 20);

    voiceArtistslabel_book=new QLabel(this);
    voiceArtistslabel_book->setMinimumSize(30,10);
    voiceArtistslabel_book->setText("VoiceArtist:");
    voiceArtistslabel_book->move(10,170);

    inputvoiceartist=new QLineEdit(this);
    inputvoiceartist->setGeometry(70, 170, 120, 20);


    genrelabel_song->hide();
    inputgenre_song->hide();
    albumlabel_song->hide();
    inputalbum_song->hide();
    textDesclabel_book->hide();
    inputbookdescr->hide();
    voiceArtistslabel_book->hide();
    inputvoiceartist->hide();

    if (auto song = dynamic_cast<Song*>(item))
    {
        genrelabel_song->show();
        albumlabel_song->show();

        inputgenre_song->show();
        inputalbum_song->show();
        qDebug()<<song->getgenre();
        qDebug()<<song->get_album();
        inputgenre_song->setText(QString::fromStdString(song->getgenre()));
        inputalbum_song->setText(QString::fromStdString(song->get_album()));

    }
    else if (auto message = dynamic_cast<Message*>(item))
    {
    }
    else if (auto book = dynamic_cast<Book*>(item))
    {
        textDesclabel_book->show();
        voiceArtistslabel_book->show();

        inputbookdescr->show();
        inputbookdescr->setText(QString::fromStdString(book->gettextDesc()));
        inputvoiceartist->show();
        inputvoiceartist->setText(QString::fromStdString(book->getvoiceArtist()));
    }
}
