#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_lists.h"


NODE *createList()
{
    NODE *head = (NODE*) malloc (sizeof(NODE));

    head->data = NULL;
    head->next = NULL;

    return head;
}

NODE *createNode(void *item)
{
    NODE *new = (NODE*) malloc (sizeof(NODE));

    new->data = item;

    return new;
}

NODE *deleteNode(NODE *list, void *key)
{     
   NODE *current = list;
   NODE *previous = NULL;
	
   if (list->next == NULL) 
   {
      return NULL;
   }

   while (current->data != key)
   {
       if (current->next == NULL)
       {
           return NULL;
       }
       else
       {
           previous = current;
           current = current->next;
       }
   }

    if (current->next == NULL)
    {
        previous->next = NULL;
        return current;
    }
    else
    {
        previous->next = current->next;
        return current;
    }

    return NULL;
}

NODE *deleteFist(NODE *list)
{
    if (list->next == NULL) 
    {
      return NULL;
    }
    
    NODE *first = list->next;
    list->next = first->next;
    
    return first;
}

void freeNode(NODE **node)
{
    if (*node) free(*node);
    node = NULL;
}

void deleteList(NODE *list)
{
    NODE *current = list->next;
    NODE *previous = NULL;
    
    while(current->next != NULL)
    {
        previous = current;
        current = current->next;

        deleteNode(&previous);
    }

    deleteNode(&current);
    deleteNode(&list);
}

void insert(NODE *list, void *item)
{
    NODE *current = list;
        
    while (current->next != NULL)
    {
        current = current->next;
    }

    NODE *new = createNode(item);
    
}
void insertFirst(NODE *list, void *item);

NODE *search(NODE* list, void *item)
{
    NODE *current = list;
    
    if (list->next == NULL) 
    {
        return NULL;
    }

    while (current->data != key)
    {
        if (current->next == NULL)
        {
            return NULL;
        }
        else
        {
            return current;
        }
   }
}

void display(NODE *list)


