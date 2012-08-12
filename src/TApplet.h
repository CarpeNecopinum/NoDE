#include "Direction.h"
class TApplet
{
    public:
        //Dimensions of the Applet on the Desk
        int top;
        int left;
        int width;
        int height;
        
        //"Neighbors" of the Applet
        TApplet* above;
        TApplet* below;
        TApplet* toLeft;
        TApplet* toRight;
        
        int getPreferredHeight() = 0; //Only when bottom or top
        int getPreferredWidth() = 0;  //Only when left or right
        void setDirection(Direction dir);
        Direction getDirection();
        void render() = 0;
        
        
    protected:
        Direction direction;
        
        
};