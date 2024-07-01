/*
Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$>
*/

#include <unistd.h>

void write_number(int num)
{
    char str[10] = "0123456789";
    
    if (num > 9)
		write_number(num / 10);
	write (1, &str[num % 10], 1);
}

void fizzbuzz (void)
{
    int i;
    int len;
    char c;
    
    i = 1;
    len = 0;
    while (i < 101)
    {
        if (i % 15 == 0)
            write (1, "fizzbuzz\n", 9);
        else if ( i % 3 == 0)
            write (1, "fizz\n", 5);
        else if ( i % 5 == 0)
            write (1, "buzz\n", 5);
        else
        {
            write_number (i);
            write (1, "\n", 1);
        }
        i++;
    }
}

int main (void)
{
    fizzbuzz();
    return (0);
}