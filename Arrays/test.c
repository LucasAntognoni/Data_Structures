#include <stdio.h>
#include <stdlib.h>

#include "arrays.h"

int main(void)
{
    int i;

    ARRAY *array;

    array =  array_init();
    //s
    add_element(array, "Bonjour");
    add_element(array, "tout");
    add_element(array, "le");
    add_element(array, "monde");

    for (i = 0; i < array_elements(array); i++)
    {
      printf("%s ", (char *) get_element(array, i));
    }
    printf("\n");

    delete_element(array, 3);
    delete_element(array, 2);
    delete_element(array, 1);

    set_element(array, 0, "Hello");
    add_element(array, "World");

    for (i = 0; i < array_elements(array); i++)
    {
      printf("%s ", (char *) get_element(array, i));
    }
    printf("\n");

    free_array(array);
}
