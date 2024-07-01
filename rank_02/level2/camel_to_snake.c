/*
Assignment name  : camel_to_snake
Expected files   : camel_to_snake.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in lowerCamelCase format
and converts it into a string in snake_case format.

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$
*/

#include <unistd.h>
#include <stdlib.h>

int is_upper(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

void camel_to_snake(char *str)
{
    char c;

    if(*str)
    {
        write (1, str, 1);
        str++;
    }
    while (*str)
    {
        if (is_upper(*str))
        {
            write (1, "_", 1);
            c = *str +32;
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
        camel_to_snake(argv[1]);
    write (1, "\n", 1);
    return (0);
}