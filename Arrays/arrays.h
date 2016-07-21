#ifndef ARRAYS_H
#define ARRAYS_H

#define ARRAY_INIT_CAPACITY 4

typedef struct array
{
    void **items;
    int capacity;
    int elements;
} ARRAY;

ARRAY *array_init();

void free_array(ARRAY *);

int array_elements(ARRAY *);

int array_capacity(ARRAY *);

static void resize_array(ARRAY *, int);

void add_element(ARRAY *, void *);

void set_element(ARRAY *, int, void *);

void *get_element(ARRAY *, int);

void delete_element(ARRAY *, int);

#endif
