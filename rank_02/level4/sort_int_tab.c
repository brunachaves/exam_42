/*
Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.
*/
#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
    int aux;
    int i = 1;
    int j = 0;

    while(i < size)
    {
        j = i -1;
        while(j >= 0)
        {
            if(tab[i] < tab[j])
            {
                aux = tab[i];
                tab[i] = tab[j];
                tab[j] = aux;
            }
            j--;
        }
        i++;
    }
}
