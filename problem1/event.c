#include "event.h"
#include <string.h>
#include <stdlib.h>

Event *CreateEvent(char *name)
{
    Event *event = malloc(sizeof(Event));
    strncpy(event->eventName, name, strnlen(name,15));
    event->next = NULL;
    return event;
}

void DestroyEvent(Event *this)
{
    free(this);
}
