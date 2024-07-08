/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/

#include <stdio.h>

int convert_to_int(char c)
{
    int num;

    if (c >= '0' && c <= '9')
        num = c - 48;
    else if (c >= 'a' && c <= 'f')
        num = c - 87;
    else 
        num = c - 55;   
    return (num);
}

int	ft_atoi_base(const char *str, int str_base)
{
    int i = 0;
    int signal = 1;
    int result = 0;
    int aux;

    if (str[i] == '-')
    {
        signal = -1;
        i++;
    }
    while(str[i + 1] != '\0')
    {
        aux = convert_to_int(str[i]);
        result += aux * str_base;
        i++;
    }
    aux = convert_to_int(str[i]);
    result += aux;
    return (result * signal);
}
