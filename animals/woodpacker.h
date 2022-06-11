#include"animal.h"

class woodpacker : public animal
{
public:
    woodpacker()
    {
        setKind("woodpacker");
        setAlive(true);
        setZnak('x');
        setSpeed(3);
    }
};