#include <stdio.h>
#include <stdlib.h>

#include "arrays.h"

int main(void)
{
    int i;

    ARRAY *arrei;

    arrei =  array_init();

    printf("bananaaaa\n");

    add_element(arrei, (int*) 1);
    add_element(arrei, (int*) 2);
    add_element(arrei, (int*) 3);

    for (i = 0; i < array_elements(arrei); i++)
    {
      printf("%d ", (int *) get_element(arrei, i));
    }
    printf("\n");

    delete_element(arrei, 0);
    delete_element(arrei, 1);
    delete_element(arrei, 2);

    set_element(arrei, 0, (int *) 4);
    add_element(arrei, (int *) 5);

    for (i = 0; i < array_elements(arrei); i++)
    {
      printf("%d ", (int *) get_element(arrei, i));
    }
    printf("\n");

    free_array(arrei);
}
