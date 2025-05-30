#ifndef INFO_FORM_H
#define INFO_FORM_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>


#include "Song.hpp"
#include "Message.hpp"
#include "Book.hpp"

class Info_form : public QDialog
{
    Q_OBJECT
public:
    Info_form(QWidget *parent = nullptr,Audio *item=nullptr);

private slots:
    void editbtn_clicked(Audio *item);

private:
    QPushButton *editbtn;
    QPushButton *cancelbtn;

    QLabel *classlabel;

    QLabel *namelabel;
    QLabel *authorlabel;
    QLabel *durationlabel;

    QLabel *genrelabel_song;
    QLabel *albumlabel_song;


    QLabel *textDesclabel_book;
    QLabel *voiceArtistslabel_book;


    QLineEdit *inputname;
    QLineEdit *inputauthor;
    QLineEdit *inputduration;
    QLineEdit *inputgenre_song;
    QLineEdit *inputalbum_song;
    QLineEdit *inputbookdescr;
    QLineEdit *inputvoiceartist;
};

#endif // INFO_FORM_H
