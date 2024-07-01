/*
Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);
*/
#include <stdlib.h>
/* #include <string.h>
#include <stdio.h> */

char	*ft_strpbrk(const char *s1, const char *s2)
{
    char *ptr;
    int i;

    while(*s1)
    {
        i = 0;
        while(s2[i])
        {
            if (*s1 == s2[i])
            {
                ptr = (char *)s1;
                return (ptr);
            } 
            i++;
        }
        s1++;
    }
    return(NULL);
}

/* int main (int argc, char **argv)
{
    char *pbrk_ft;
    char *pbrk_original;

    if (argc == 3)
    {
        pbrk_ft =ft_strpbrk(argv[1], argv[2]);
        pbrk_original = strpbrk(argv[1], argv[2]);
        printf("This is ft: %p\n", pbrk_ft);
        printf("This is original: %p\n", pbrk_original);
    }
    else
        printf("\n");
    return (0);
} */