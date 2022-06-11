#include"animal.h"

class moose : public animal
{
public:
    moose()
    {
        setKind("moose");
        setAlive(true);
        setZnak('v');
        setSpeed(3);
    }
};