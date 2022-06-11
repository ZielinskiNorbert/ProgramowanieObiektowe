#include"animal.h"

class deer : public animal
{
public:
    deer()
    {
        setKind("deer");
        setAlive(true);
        setZnak('u');
        setSpeed(2);
    }
};
