/*
Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);
*/
/* #include <stdio.h>
#include <string.h> */

int    ft_strcmp(char *s1, char *s2)
{
    while(*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

/* int main (int argc, char **argv)
{
    int comp_ft;
    int comp_original;

    if (argc == 3)
    {
        comp_ft =ft_strcmp(argv[1], argv[2]);
        comp_original = strcmp(argv[1], argv[2]);
        printf("This is ft: %d\n", comp_ft);
        printf("This is original: %d\n", comp_original);
    }
    else
        printf("\n");
        return (0);
} */