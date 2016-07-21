#include <stdlib.h>
#include <sdtio.h>
#include "arrays.h"

ARRAY *array_init()
{
  ARRAY *a = NULL;

  a = (ARRAY*) malloc (sizeof(ARRAY));

  if (a != NULL)
  {
    a -> capacity = ARRAY_INIT_CAPACITY;
    a -> elements = 0;
    a -> items = malloc (sizeof(void) * (a -> capacity));
  }

  return a;
}

void free_array(array *a)
{
  if (a -> elements != 0)
  {
    free(a -> items);
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

static void resize_array(array *a, int capacity)
{
  void **items = realloc(a->items, sizeof(void *) * capacity);

  if (items != NULL)
  {
    a->items = items;
    a->capacity = capacity;
  }
}

void add_element(array *a, void *item)
{
  if (a -> elements == a -> capacity)
  {
    resize_array(a, (a -> capacity) * 2);
  }

  a -> elements += 1;
  a -> items[a -> elements] = item;
}

void set_element(array *a, int index, void *item)
{
  if (index >= 0 && index < a -> elements)
  {
    a -> items[index] = item;
  }
}

void *get_element(array *a, int index)
{
  if (index >= 0 && index < a -> elements)
  {
    return a -> items[index];
  }

  return NULL;
}

void delete_element(array *a, int index)
{
  int i = 0;

  if (index >= 0 && index < a -> elements)
  {
    a -> items[index] = NULL;

    for(i = index; i < a -> elements - 2; i++)
    {
      a -> items[i] = a -> items[i + 1];
      a -> items[i + 1] =  NULL;
    }

    a -> elements -= 1;

    if (a -> elements > 0 && a -> elements == (v -> capacity) / 4)
    {
      resize_array(a, (a -> capacity / 2));
    }
  }
}
