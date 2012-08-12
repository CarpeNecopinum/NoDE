#include "TDesk.h"
#include "TTasks.h"
#include "Direction.h"

int main (int argc, char** argv)
{
    TDesk desk = new TDesk();
    desk.addApplet(new TTasks(), left);
}