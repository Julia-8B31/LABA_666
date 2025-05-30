#ifndef BOOK_HPP
#define BOOK_HPP


#include "Informative.hpp"
#include <vector>

class Book:public Informative
{
public:
    Book()
    {
        std::cout<<"book created";
    }
    std::string getClassName() const override {
        return "[B]";
    }


    void settingAudio(std::string author,
                      int duration,
                      std::string releaseDate,
                      std::string name,
                      std::string textDesciptiton,
                      std::string voiceArtist,
                      std::vector<uint64_t> notes)
    {
        _author=author;
        _duration=duration;
        _releaseDate=releaseDate;
        _name=name;
        _pronunciationSpeed=1;
        _textDesciptiton=textDesciptiton;
        _voiceArtist=voiceArtist;
        _notes=notes;
    }

    void makeNotes(uint64_t timestamp)
    {
        _notes.push_back(timestamp);
    }

    void setTimer(uint64_t time)
    {
        //какая то логика проверки времени
        stop();
    }

    std::string gettextDesc()
    {
        return _textDesciptiton;
    }
    std::string getvoiceArtist()
    {
        return _voiceArtist;
    }

private:
    std::string _textDesciptiton;
    std::string _voiceArtist;
    std::vector<uint64_t> _notes;
};


#endif // BOOK_HPP
