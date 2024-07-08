/*
Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or more strings and, for each argument, puts
the last character that is a letter of each word in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

A letter is a character in the set [a-zA-Z]

If there are no parameters, display \n.

Examples:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
$>
*/

#include <unistd.h>

int is_space(char c)
{
    if (c == 9 || c == 32)
        return (1);
    return (0);
}

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

void rstr_cap(char *str)
{
    int i = 0;
    char c;

    while(str[i])
    {
        if (is_lower(str[i]))
        {
            if(is_space(str[i + 1]) || !str[i + 1])
            {
                c = str[i] - 32;
                write(1, &c, 1);
            }
            else
                write(1, str + i, 1);
        }
        else if (is_upper(str[i]))
        {
            if (!is_space(str[i + 1]) && str[i + 1])
            {
                c = str[i] + 32;
                write(1, &c, 1);
            }
            else
                write(1, str + i, 1);
        }
        else
            write(1, str + i, 1);
        i++;
    }

}

int main(int argc, char **argv)
{
    int i = 1;
    if (argc == 1)
        write(1, "\n", 1);
    while(i < argc)
    {
        rstr_cap(argv[i]);
        i++;
    }
}