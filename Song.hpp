#ifndef SONG_HPP
#define SONG_HPP

#include "AbstractAudio.hpp"

class Song : public Audio
{
public:
    Song()
    {
        std::cout<<"song created";
    }

    std::string getClassName() const override {
        return "[S]";
    }

    void repeat()
    {
        _isRepeated=true;
    };

    void settingAudio(std::string author,
                      int duration,
                      std::string releaseDate,
                      std::string genre,
                      std::string album,
                      std::string name)
    {
        _author=author;
        _duration=duration;
        _releaseDate=releaseDate;
        _genre=genre;
        _album=album;
        _name=name;
        _isRepeated=false;
    }
    std::string getgenre()
    {
        return _genre;
    }
    std::string get_album()
    {
        return _album;
    }

private:
    std::string _genre;
    std::string _album;
    bool _isRepeated;
};



#endif // SONG_HPP
