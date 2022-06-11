#include"animal.h"

class wolf :
public animal{
public:
    wolf()
    {
        setKind("wolf");
        setAlive(true);
        setZnak('w');
        setSpeed(3);
    }
};