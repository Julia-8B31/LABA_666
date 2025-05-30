#ifndef ABSTRACTAUDIO_HPP
#define ABSTRACTAUDIO_HPP


#include <iostream>
#include <string>


class Audio
{
public:
    virtual ~Audio() = default;
    virtual std::string getClassName() const = 0;
    void start()
    {
        std::cout<<"audio started";
    }
    void stop()
    {
        std::cout<<"audio stopped";
    }

    std::string getName()
    {
        return _name;
    }
    std::string getAuthor()
    {
        return _author;
    }
    int getDuration()
    {
        return _duration;
    }
protected:
    std::string _author;
    int _duration;
    std::string _releaseDate;
    std::string _name;

};




#endif // ABSTRACTAUDIO_HPP
