#include"animal.h"

class wisent : public animal
{
public:
    wisent()
    {
        setKind("wisent");
        setAlive(true);
        setZnak('z');
        setSpeed(1);
    }
};