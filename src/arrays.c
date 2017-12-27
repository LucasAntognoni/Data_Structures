#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arrays.h"

ARRAY *array_init()
{
  ARRAY *a = NULL;

  a = (ARRAY*) malloc (sizeof(ARRAY));

  if (a != NULL)
  {
    a -> capacity = ARRAY_INIT_CAPACITY;
    a -> elements = 0;
    a -> data = malloc (sizeof(void) * (a -> capacity));
  }

  return a;
}

void free_array(ARRAY *a)
{
  if (a -> elements != 0)
  {
    free(a -> data);
  }
  free(a);
}

int array_elements(ARRAY *a)
{
  return a -> elements;
}

int array_capacity(ARRAY *a)
{
  return a -> capacity;
}

static void resize_array(ARRAY *a, int capacity)
{
  void** data = malloc(sizeof(void *) * capacity);

  if(data)
  {
    memcpy(data, a -> data, (a -> elements) * sizeof(void*));
    a->data = data;
    a->capacity = capacity;
  }
}

void add_element(ARRAY *a, void *item)
{
  if (a -> elements == a -> capacity)
  {
    resize_array(a, (a -> capacity) * 2);
  }

  a -> data[a -> elements] = item;
  a -> elements += 1;
}

void set_element(ARRAY *a, int index, void *item)
{
  if (index >= 0 && index < a -> elements)
  {
    a -> data[index] = item;
  }
}

void *get_element(ARRAY *a, int index)
{
  if (index >= 0 && index < a -> elements)
  {
    return a -> data[index];
  }

  return NULL;
}

void delete_element(ARRAY *a, int index)
{
  int i = 0;

  if (index >= 0 && index < a -> elements)
  {
    for(i = index; i < a -> elements - 2; i++)
    {
      a -> data[i] = a -> data[i + 1];
    }

    a -> elements -= 1;

    if (a -> elements > 0 && a -> elements == (a -> capacity) / 4)
    {
      resize_array(a, (a -> capacity / 2));
    }
  }
}
