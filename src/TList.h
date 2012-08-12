#include "TListItem.h"

class TList
{
public:
    TList();
    ~TList();
    
    int addItem(void* item);
    bool removeItem(void* item);
    bool isEmpty();
    void reset();
    void next();
    void* getItem();
    
private:
    TListItem *first;
    TListItem *current;
    int length = 0;   
};