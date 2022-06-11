
#pragma once
#include"animal.h"

class ant : public animal
{
public:
    ant()
    {
        setKind("ant");
        setAlive(true);
        setZnak('a');
        setSpeed(3);
    }
};

