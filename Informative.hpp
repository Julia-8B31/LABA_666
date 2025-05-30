#ifndef INFORMATIVE_HPP
#define INFORMATIVE_HPP


#include "AbstractAudio.hpp"

class Informative : public Audio //по сути абстрактный класс
{
public:

    void transformToText(){};

    void changeSpeed(double factor)
    {
        _pronunciationSpeed=factor;
    }

protected:
    double _pronunciationSpeed;
};

#endif // INFORMATIVE_HPP
