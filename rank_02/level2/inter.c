/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/

#include <unistd.h>

void inter(char *str1, char *str2)
{
    int i;
    int j;
    int k;
    int flag;

    i = 0;
    while (str1[i])
    {
        flag = 0;
        k = i - 1;
        j = 0;
        while(k >= 0)
        {
            if (str1[i] == str1[k])
            {
                flag = 1;
                break ;
            }
            k--;
        }
        while(str2[j] && !flag)
        {
            if(str1[i] == str2[j])
            {
                flag = 1;
                write(1, str1 + i, 1);
            }
            j++;
        }
        i++;
    }
}

int main(int argc, char ** argv)
{
    if (argc == 3)
        inter(argv[1], argv[2]);
    write (1, "\n", 1);
    return (0);
}