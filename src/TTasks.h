#include "TList.h"
class TTasks : public TApplet
{
    static TTasks* instance;
    
    private:
        TList tasks;
};