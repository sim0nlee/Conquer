#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definizioni.h"



typedef struct List {
    void* data;
    struct List* next;
} List;



List* newNode (void* data);

List* push (List* list, void* data);

List* append (List* list, void* data);

int contains (List* list, void* data, int (*areEqual)(void*, void*));

List* delete (List* list, void* data, int (*areEqual)(void*, void*), void (*freeData)(void*));  // freedata la si passerebbe qualora i dati richiedessero deallocazione

int length (List* list);

List* freelist (List* list, void (*freeData)(void*));   // freedata la si passerebbe qualora i dati richiedessero deallocazione

#endif
