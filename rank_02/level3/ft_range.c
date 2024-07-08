/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/

#include <stdlib.h>
/* #include <stdio.h> */

int calculate_size(int start, int end)
{
    int size;

    if(end >= start)
        size = end - start + 1;
    else
        size = ((end - start) * (-1)) + 1;
    return (size);
}
int     *ft_range(int start, int end)
{
    int *arr;
    int size;
    int i;

    size = calculate_size (start, end);
    arr = (int *)malloc(sizeof(int) * size);
    if(!arr)
        return (NULL);
    i = 0;
    if (start <= end)
    {
        while (start <= end)
        {
            arr[i] = start;
            i++;
            start++;
        }
    }
    else
    {
        while (start >= end)
        {
            arr[i] = start;
            i++;
            start--;
        }
    }      
    return (arr);
}

/* int main ()
{
    int start = 0;
    int end = -3;
    int *arr = ft_range(start, end);
    int size = calculate_size(start, end);
    int i = 0;

    while(i  < size)
    {
        printf("%d\n", arr[i]);
        i++;
    }
} */