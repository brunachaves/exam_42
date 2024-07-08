/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/

#include <unistd.h>
#include <stdio.h>

int atoi(char *str)
{
    int result;

    result = 0;
    while (*str)
    {
        result = result * 10 + (*str - 48);
        str++;
    }
    return (result);
}

void ft_putnbr(int num)
{
    if (num >= 10)
		ft_putnbr(num / 10);
	char digit = num % 10 + '0';
	write(1, &digit, 1);
}

int is_prime(int num)
{
    int div = 2;

    if (num <= 0)
        return (0);
    else if( num == 1 || num == 2)
        return(1);
    while (div < num)
    {
        if (num % div == 0)
            return (0);
        div++;
    }
    return (1);
}

int find_previous_prime(int num)
{
    int previous;

    previous = num - 1;
    while(previous > 0)
    {
        if(is_prime(previous))
            return(previous);
        previous--;
    }
    return (0);
}


void    add_prime_sum(char *str)
{
    int num = atoi(str);
    int flag_prime = is_prime(num);
    int sum = 0;
    int previous = 0;


    if(flag_prime)
        sum += num;
    previous = find_previous_prime(num);
    while(previous >= 1)
    {
        sum += previous;
        if (previous ==  1)
            break;
        previous = find_previous_prime(previous);
    }
    ft_putnbr(sum);
    write (1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc == 2 && (argv[1][0] >= '0' && argv[1][0] <= '9'))
        add_prime_sum(argv[1]);
    else
        write(1, "0\n", 2);
    return (0);
}