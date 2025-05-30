#ifndef DIALOG_FORM_H
#define DIALOG_FORM_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>


#include "Song.hpp"
#include "Message.hpp"
#include "Book.hpp"

class Dialog_form : public QDialog
{
    Q_OBJECT
public:
    Dialog_form(QWidget *parent = nullptr);

    Audio* getItem(){return item;}

private slots:
    void addbtn_clicked();

private:
    Audio* item=nullptr;

    QPushButton *addbtn;
    QPushButton *cancelbtn;

    QLabel *classlabel;

    QLabel *namelabel;
    QLabel *authorlabel;
    QLabel *durationlabel;

    QLabel *genrelabel_song;
    QLabel *albumlabel_song;


    QLabel *textDesclabel_book;
    QLabel *voiceArtistslabel_book;

    QComboBox *combo_classes;

    QLineEdit *inputname;
    QLineEdit *inputauthor;
    QLineEdit *inputduration;
    QLineEdit *inputgenre_song;
    QLineEdit *inputalbum_song;
    QLineEdit *inputbookdescr;
    QLineEdit *inputvoiceartist;
};

#endif // DIALOG_FORM_H

bool is_number(const QString &input);
