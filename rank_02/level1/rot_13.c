/*
Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
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

void    rot_13(char *str)
{
    char    *upper = "0ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMN";
    char    *lower = "0abcdefghijklmnopqrstuvwxyzabcdefghijklmn";
    int index;
    char    c;

    while (*str)
    {
        index = 0;
        if (is_lower(*str))
        {
            index = *str - 96 + 13;
            c = lower[index];
            write(1, &c, 1);
            
        }
        else if (is_upper(*str))
        {
            index = *str - 64 + 13;
            c = upper[index];
            write(1, &c, 1);
        }
        else
            write (1, str, 1);
        str++;
    }
}

int main (int argc, char ** argv)
{
    if (argc == 2)
        rot_13(argv[1]);
    write (1, "\n", 1);
    return (0);
}