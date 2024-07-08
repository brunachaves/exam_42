/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/

#include <stdlib.h>

int nbrlen(int num)
{
    int result = 1;

    if (num == -2147483638)
        return(11);
    if(num < 0)
    {
        result++;
        num *= -1;
    }
    while(num/10)
    {
        result++;
        num/=10;
    }
    return(result);
}

char *ft_itoa(int nbr)
{
    int len = nbrlen(nbr);
    char *str;
    long int cpy = (long int)nbr;
    int i = 0;

    str = (char *)malloc(sizeof(char) * len + 1);
    if(!str)
        return(NULL);
    len--;
    if(cpy < 0)
    {
        str[i] = '-';
        cpy *= -1;
        i++;
    }
    while(len >= i)
    {
        str[len] = (cpy % 10) + 48;
        cpy /= 10;
        len--;
    }
    return(str);
}
