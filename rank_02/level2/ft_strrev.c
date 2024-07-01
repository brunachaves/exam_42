/*
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);
*/

#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}

char    *ft_strcpy(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
}

char    *ft_strrev(char *str)
{
    int len;
    int i;

    len = ft_strlen(str);
    char aux[len];
    i = 0;
    len--;
    while (str[i])
    {
        aux[len] = str[i];
        i++;
        len--;
    }       
    str = ft_strcpy(str, aux);
    return (str);
}

int main (int argc, char **argv)
{
    char *rev_ft;

    if (argc == 2)
    {
        rev_ft =ft_strrev(argv[1]);
        printf("This is rev: %s\n", rev_ft);
    }
    else
        printf("\n");
    return (0);
}