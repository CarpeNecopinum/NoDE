#include "TDesk.h"
#include "src/TApplet.h"

TDesk::TDesk()
{
    applet_count = 0;
}

TDesk::~TDesk()
{
    for (int i = 0; i < applet_count; i++)
    {
        delete applets[i];
    }
}

void TDesk::addApplet(TApplet* applet, Direction dir)
{
    if (applet_count == MAX_APPLETS)
    {
        throw "Maximum Number of Applets reached.";
        return;
    }
    applet->setDirection(dir);
    applets[applet_count] = applet;
    applet_count++;   
}

void TDesk::renderAll()
{
    int rest_left, rest_top, rest_width, rest_height;
    rest_left = 0;
    rest_top = 0;
    rest_width = width;
    rest_height = height;    
    
    for (int i = 0; i < applet_count; i++)
    {
        TApplet* applet = applets[index];
        switch(applet->getDirection())
        {
            case left:
                applet->width   = applet->getPreferredWidth();
                applet->height  = rest_height;
                applet->top     = rest_top;
                applet->left    = rest_left;
                rest_left      += applet->width;
                rest_width     -= applet->width;
                break;
                
            case right:
                applet->width   = applet->getPreferredWidth();
                applet->height  = rest_height;
                applet->top     = rest_top;
                applet->left    = rest_left + rest_top - applet->width;
                rest_width     -= applet->width;
                break;
                
            case top:
                applet->width   = rest_width;
                applet->height  = applet->getPreferredHeight();
                applet->top     = rest_top;
                applet->left    = rest_left;
                rest_top       += applet->height;
                rest_height    -= applet->height;
                break;
                
            case bottom:
                applet->width   = rest_width;
                applet->height  = applet->getPreferredHeight();
                applet->top     = rest_top + rest_height - applet->height;
                applet->left    = rest_left;
                rest_height    -= applet->height;
                break;
        }
        render(i);
    }
}

void TDesk::render(int index)
{
    applets[index]->render();
}