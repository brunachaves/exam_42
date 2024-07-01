/*
Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);
*/
#include <stddef.h>
/* #include <string.h>
#include <stdio.h> */

size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t len;
    int i;

    len = 0;
    while(*s)
    {
        i = 0;
        while(reject[i])
        {
            if (*s == reject[i])
                break ;
            i++;
        }
        if(*s == reject[i]) 
            break;         
        else if (!reject[i])
            len++;
        s++;
    }
    return(len);
}

/* int main (int argc, char **argv)
{
    int cspn_ft;
    int cspn_original;

    if (argc == 3)
    {
        cspn_ft =ft_strcspn(argv[1], argv[2]);
        cspn_original = strcspn(argv[1], argv[2]);
        printf("This is ft: %d\n", cspn_ft);
        printf("This is original: %d\n", cspn_original);
    }
    else
        printf("\n");
    return (0);
} */