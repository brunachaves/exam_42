/*
Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
*/
/* #include <stdio.h>
#include <stdlib.h>
#include <unistd.h> */

int	ft_atoi(const char *str)
{
    int result;
    int signal;

    signal = 1;
    result = 0;
    while(*str == ' ')
        str++;
    if (*str == '-')
    {
        signal = -1;
        str++;
    }
    else if (*str == '+')
        str++;
    while (*str)
    {
        if(*str >= '0' && *str <= '9')
        {
            result = result * 10 + (*str - 48);
            str++;
        }
        else
            break ;
    }
    return (result * signal);
}

/* int main(int argc, char **argv)
{
    int num_ft;
    int num_atoi;

    if(argc == 2)
    {
        num_ft = ft_atoi(argv[1]);
        num_atoi = atoi(argv[1]);
        printf("This is ft_atoi: %d\n", num_ft);
        printf("This is actual atoi: %d\n", num_atoi);
    }
    else
        write(1, "\n", 1);
    return (0);
} */