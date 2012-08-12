#define MAX_APPLETS 10

class TDesk
{
    public:
        TDesk();
        ~TDesk();
        void addApplet(TApplet* applet, Direction dir);
        void renderAll();
        void render(int index);
        
        int width, height;
 
    private:
        TApplet* applets[MAX_APPLETS - 1];
        int applet_count;
        
};