/*
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);
*/

#include <stdio.h>
#include <stdlib.h>

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

/* int main ()
{
    char source[5] = "Hey!";
    char *dest;

    dest = malloc(5);    
    ft_strcpy(dest, source);

    printf("%s\n", dest);
    return (0);
} */