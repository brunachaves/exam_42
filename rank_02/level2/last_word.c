/*
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/

#include <unistd.h>

int ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}

void    last_word(char *str)
{
    int index_last_word = ft_strlen(str) - 1;

    while(str[index_last_word] == 32 || str[index_last_word] == 9)
        index_last_word--;
    while (!(str[index_last_word] == 32 || str[index_last_word] == 9))
        index_last_word--;
    index_last_word++;
    while(str[index_last_word])
    {
        write(1, str + index_last_word, 1);
        index_last_word++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        last_word(argv[1]);
    write(1, "\n", 1);
    return(0);
}