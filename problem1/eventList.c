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
    Event *actEvent = this->head;
    if (this->isEmpty == 0)
    {
        while (actEvent != NULL)
        {
            if (strcmp(name, actEvent->eventName) == 0)
                return actEvent;
            actEvent = actEvent->next;
        }
    }
    actEvent = NULL;
    return actEvent;
}

void AddEvent(EventList *this, Event *event)
{
    Event *actEvent = this->head;
    while (actEvent != NULL)
    {
        if (strcmp(event->eventName, actEvent->eventName) == 0)
        {
            return;
        }
        actEvent = actEvent->next;
    }

    if (this->isEmpty == 0)
    {
        this->last->next = event;
        this->last = event;
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
    if (this->isEmpty == 0)
    {
        Event *actEvent = this->head->next;
        Event *antEvent = this->head;
        if (strcmp(name, antEvent->eventName) == 0)
        {
            if (antEvent->next == NULL)
            {
                this->head = NULL;
                this->last = NULL;
                this->isEmpty = 1;
                DestroyEvent(antEvent);
            }
            else
            {
                this->head = actEvent;
                DestroyEvent(antEvent);
            }
        }
        while (actEvent != NULL)
        {
            if (strcmp(name, actEvent->eventName) == 0)
            {
                antEvent->next = actEvent->next;
                if (this->last->next == NULL)
                {
                    this->last = antEvent;
                    DestroyEvent(actEvent);
                }
            }
            antEvent = actEvent;
            actEvent = actEvent->next;
        }
    }
}

void ListEvents(EventList *this)
{
    if (this->isEmpty == 0)
    {
        Event *actEvent = this->head;

        while (actEvent != NULL)
        {
            printf("%s\n", actEvent->eventName);
            actEvent = actEvent->next;
        }
    }
    else
    {
        printf("empty\n");
    }
}
