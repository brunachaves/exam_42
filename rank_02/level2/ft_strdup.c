/*
Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);
*/
#include <stdlib.h>
/* #include <stdio.h>
#include <string.h> */

int ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}

char    *ft_strdup(char *src)
{
    char *new_str;
    int len;
    int i;

    i = 0;
    len = ft_strlen(src);
    new_str = (char *)malloc(len + 1);
    while (src[i])
    {
        new_str[i] = src[i];
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}

/* int main (int argc, char **argv)
{
    char *dup_ft;
    char *dup_original;

    if (argc == 2)
    {
        dup_ft =ft_strdup(argv[1]);
        dup_original = strdup(argv[1]);
        printf("This is ft: %s\n", dup_ft);
        printf("This is original: %s\n", dup_original);
    }
    else
        printf("\n");
    free (dup_ft);
    free (dup_original);
    return (0);
} */