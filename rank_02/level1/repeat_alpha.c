/*
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/

#include <unistd.h>

int is_lower(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

int is_upper(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

void repeat_alpha(char *str)
{
    char *upper = "0ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *lower = "0abcdefghijklmnopqrstuvwxyz";
    int index = 0;

    while (*str)
    {
        if (is_lower(*str))
        {
            index = *str - 96;
            while (index)
            {
                write (1, str, 1);
                index --;
            }
        }
        else if (is_upper(*str))
        {
            index = *str - 64;
            while (index)
            {
                write (1, str, 1);
                index --;
            }
        }
        else
            write (1, str, 1);
        str++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        repeat_alpha(argv[1]);
    write (1, "\n", 1);
    return (0);
}