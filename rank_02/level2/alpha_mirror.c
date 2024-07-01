/*
Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------
 
Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.
 
'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'
 
and so on.
 
Case is not changed.
 
If the number of arguments is not 1, display only a newline.
 
Examples:
 
$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
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

void alpha_mirror(char *str)
{
    char *upper = "0ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *lower = "0abcdefghijklmnopqrstuvwxyz";
    int index_orig = 0;
    int index_mirror = 0 ;
    char c = 0;

    while (*str)
    {
        if (is_lower(*str))
        {
            index_orig = *str - 96;
            index_mirror = 27 - index_orig;
            c = lower[index_mirror];
            write (1, &c, 1);
        }
        else if (is_upper(*str))
        {
            index_orig = *str - 64;
            index_mirror = 27 - index_orig;
            c = upper[index_mirror];
            write (1, &c, 1);
        }
        else
            write (1, str, 1);
        str++;
    }
}

int main (int argc, char **argv)
{

    if (argc == 2)
        alpha_mirror(argv[1]);
    write (1, "\n", 1);
    return (0);
}