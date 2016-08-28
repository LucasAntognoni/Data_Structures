#ifndef ARRAYS_H
#define ARRAYS_H

#define ARRAY_INIT_CAPACITY 4


/*
  Array structure
*/

typedef struct array
{
    void **data;
    int capacity;
    int elements;
} ARRAY;

/*
  Inicialize the array, with inicial capacity
  defined by ARRAY_INIT_CAPACITY.
*/

ARRAY *array_init();

/*
  Destroy the array and its contents
*/

void free_array(ARRAY *);

/*
  Returns the number of elements in the array
*/

int array_elements(ARRAY *);

/*
  Returns the array capacity
*/

int array_capacity(ARRAY *);

/*
  Resizes the array if the number of elements in it
  equals it's capacity
*/

static void resize_array(ARRAY *, int);

/*
  Add an element to the array
*/

void add_element(ARRAY *, void *);

/*
  Rewrites an element in the array given 
  it's index
*/

void set_element(ARRAY *, int, void *);

/*
  Retuns an element given it's index
*/

void *get_element(ARRAY *, int);

/*
  Deletes an element in the array given
  it's index
*/

void delete_element(ARRAY *, int);

#endif
