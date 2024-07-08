/*
Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$
*/

#include <stdio.h>
#include <stdlib.h>

int smallest(int a, int b)
{
    if (a <= b)
        return(a);
    return (b);
}

unsigned int pgcd(char *s1, char *s2)
{
    int num1 = atoi(s1);
    int num2 = atoi(s2);
    int pgcd = smallest(num1, num2);

    while(pgcd >= 1)
    {
        if((num1 % pgcd == 0) && (num2 % pgcd == 0))
            break;
        pgcd--;
    }
    return(pgcd);
    
}

int main(int argc, char **argv)
{
    unsigned int result;

    if (argc == 3)
    {
        result = pgcd(argv[1], argv[2]);
        printf("%u", result);
    }
    printf("\n");
}