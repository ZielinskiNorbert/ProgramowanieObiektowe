#include"animal.h"

class boar : public animal
{
public:
    boar()
    {
        setKind("boar");
        setAlive(true);
        setZnak('B');
        setSpeed(2);
    }
};