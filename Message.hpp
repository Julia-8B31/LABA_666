#ifndef MESSAGE_HPP
#define MESSAGE_HPP


#include "Informative.hpp"

class Message:public Informative
{
public:

    Message()
    {
        std::cout<<"message created";
    }
    std::string getClassName() const override {
        return "[M]";
    }

    void settingAudio(std::string author, int duration, std::string releaseDate,std::string name)
    {
        _author=author;
        _duration=duration;
        _releaseDate=releaseDate;
        _pronunciationSpeed=1;
        _name=name;

    }

    void reply(std::string text)
    {
        std::cout<<text;
    }

};

#endif // MESSAGE_HPP
