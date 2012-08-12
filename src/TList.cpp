#include "TList.h"
#include <stdlib.h>

TList::TList()
{
    this->first = NULL;
    this->current = NULL;
    length = 0;
}

TList::~TList()
{
    
}

bool TList::isEmpty()
{
    return (this->first == NULL);
}

int TList::addItem(void* item)
{
    TListItem* added = new TListItem();
    added->object = item;
    added->next = NULL;
    
    if (this->first == NULL)
    {
        this->first = added;
    } else {
        TListItem* curr = this->first;
        while (curr->next != NULL) curr = curr->next;
        curr->next = added;        
    }
    length++;
    return length;
}

bool TList::removeItem(void* item)
{
    if (this->first == NULL) return false;
    TListItem* curr = this->first;
    
    if (curr->object == item)
    {
        this->first == curr->next;
    } else {
        TListItem* prev = curr;
        curr = prev->next;
        while ((curr != NULL) && (curr->object != item))
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr->next == NULL) return false;
        
        prev->next = curr->next;
    }    
    delete curr;
    return true;
}

void TList::reset()
{
    this->current = this->first;
}

void TList::next()
{
    if (this->current != NULL)
    {
        this->current = this->current->next;
    }
}


void* TList::getItem()
{
    if (this->current != NULL)
    {
        return this->current->object;
    } else {
        return NULL;
    }
}