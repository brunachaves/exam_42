
/*
Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);
*/
#include <stddef.h>
#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		++s;
	}
	return (NULL);
}

size_t	ft_strspn(const char *s, const char *accept)
{
    size_t len;

    len = 0;
    while (s[len])
	{
		if (!ft_strchr(accept, s[len]))
			break;
		++len;
	}
    return(len);
}

/* int main (int argc, char **argv)
{
    int spn_ft;
    int spn_original;

    if (argc == 3)
    {
        spn_ft =ft_strspn(argv[1], argv[2]);
        spn_original = strspn(argv[1], argv[2]);
        printf("This is ft: %d\n", spn_ft);
        printf("This is original: %d\n", spn_original);
    }
    else
        printf("\n");
    return (0);
} */