/*
Assignment name  : search_and_replace
Expected files   : search_and_replace.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program called search_and_replace that takes 3 arguments, the first
arguments is a string in which to replace a letter (2nd argument) by
another one (3rd argument).

If the number of arguments is not 3, just display a newline.

If the second argument is not contained in the first one (the string)
then the program simply rewrites the string followed by a newline.

Examples:
$>./search_and_replace "Papache est un sabre" "a" "o"
Popoche est un sobre
$>./search_and_replace "zaz" "art" "zul" | cat -e
$
$>./search_and_replace "zaz" "r" "u" | cat -e
zaz$
$>./search_and_replace "jacob" "a" "b" "c" "e" | cat -e
$
$>./search_and_replace "ZoZ eT Dovid oiME le METol." "o" "a" | cat -e
ZaZ eT David aiME le METal.$
$>./search_and_replace "wNcOre Un ExEmPle Pas Facilw a Ecrirw " "w" "e" | cat -e
eNcOre Un ExEmPle Pas Facile a Ecrire $

*/
#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}

void    search_replace(char *str, char *a, char *b)
{
    int len;

    len = ft_strlen(str);
    if (a[1] || b[1])
    {
        write (1, str, len);
        write (1, "\n", 1);
        exit(0);
    }
    while (*str)
    {
        if (*str == a[0])
            write (1, b + 0, 1);
        else
            write (1, str, 1);
        str++;
    }
}

int main (int argc, char ** argv)
{
    if (argc == 4)
        search_replace(argv[1], argv[2], argv[3]);
    write (1, "\n", 1);
    return (0);
}