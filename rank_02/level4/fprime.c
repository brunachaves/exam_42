/*
Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there is one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$

*/

#include <stdio.h>
#include <stdlib.h>

int is_prime(int num)
{
    int div = 2;

    if(num <= 0)
        return (0);
    if (num == 1 || num == 2)
        return(1);
    while(div * div <= num)
    {
        if (num % div == 0)
            return (0);
        div++;
    }
    return (1);
}

int find_next_prime(int num)
{
    int next_prime = num + 1;
    if(is_prime(next_prime))
        return(next_prime);
    return(find_next_prime(next_prime));
}

void fprime(char *str)
{
    int num = atoi(str);
    int prime =  2;

    while(num / prime)
    {
        if (num % prime == 0)
        {
            printf("%d", prime);
            num /= prime;
            if(num > 1)
                printf("*");
        }
        else
            prime = find_next_prime(prime);
    }
}

int main (int argc, char **argv)
{
    if(argc == 2)
        fprime(argv[1]);
    printf("\n");
}