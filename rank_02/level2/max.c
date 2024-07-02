/*
Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/

/* #include <stdio.h> */

int		max(int* tab, unsigned int len)
{
    int  i = 0;
    int max;

    max = 0;
    if (!tab || len == 0)
        return (0);
    while (i + 1 < len)
    {
        if (tab[i] >= tab[i + 1])
            max = tab[i];
        i++;
    }
    return (max);
}

/* int main()
{
    int arr[6] = {123,8743,983};
    int nmax = max(arr, 0);
    printf("This is max: %d\n", nmax);
} */
