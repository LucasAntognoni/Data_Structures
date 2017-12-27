#ifndef LINKED_LISTS_H
#define LISTS_H

typedef struct node
{
    void *data;
    NODE *next;

} NODE;

NODE *createNode(void *item);

NODE *deleteNode(NODE **node);
NODE *deleteFist(NODE *list);

void deleteList(NODE *list);

void insert(NODE *list, void *item);
void insertFirst(NODE *list, void *item);

NODE *search(NODE* list, void *item);

void display(NODE *list);

bool isEmpty(NODE *list);

#endif