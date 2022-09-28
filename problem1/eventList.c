#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{
    EventList *eventList = malloc(sizeof(EventList));
    eventList->head = NULL;
    eventList->last = NULL;
    eventList->isEmpty = 1;
    return eventList;
}

void DestroyEventList(EventList *this)
{
    free(this);
}

Event *SearchEvent(EventList *this, char *name)
{
    Event *crntEvent = this->head;
    if (this->isEmpty == 0)
    {
        while (crntEvent != NULL)
        {
            if (strcmp(name, crntEvent->eventName)==0)
            return crntEvent;
            crntEvent = crntEvent->next;
        }
    }
    crntEvent = NULL;
    return crntEvent;
}

void AddEvent(EventList *this, Event *event)
{    
     Event *crntEvent = this->head;
     while (crntEvent != NULL)
     {
         if(strcmp(event->eventName, crntEvent->eventName) == 0)
         {
            return;
         }
         crntEvent = crntEvent->next;
     }

     if(this->isEmpty == 0)
     {
          this->last->next = event;
          this->last=event;
     }
     else
     {
         this->head = event;
         this->last = event;
         this->isEmpty = 0;    
     }
}

void RemoveEvent(EventList *this, char *name)
{

}

void ListEvents(EventList *this)
{

}
