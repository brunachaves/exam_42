/*
Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"
*/

#include <unistd.h>

void	print_bits(unsigned char octet)
{
    int num = (int)octet;
    char result[9] = "00000000";
    int i = 7;

    if (num == 0)
    {
        write(1, "00000000", 8);
        return ;
    }
    else if (num == 1)
    {
        write(1, "00000001", 8);
        return ;
    }
    while(num/2 > 0)
    {
        if(num%2 == 0)
            result[i] = '0';
        else
            result[i] = '1';
        i--;
        num /= 2;
    }
    result[i] = '1';
    write(1, result, 8);
}

/* int main(){
    unsigned char c = 5;
    print_bits(c);
} */