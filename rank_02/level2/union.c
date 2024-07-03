/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/

#include <unistd.h>

void    check_first(char *str)
{
    int i = 0;
    int j;
    int is_repeated;

    write(1, str + i, 1);
    i++;
    while (str[i])
    {
        j = i - 1;
        is_repeated = 0;
        while(j > -1 && !is_repeated)
        {
            if(str[i] == str[j])
                is_repeated = 1;
            j--;
        }
        if (!is_repeated)
            write(1, &(str[i]), 1);
        i++;
    }
}

void    check_second(char *str1, char *str2)
{
    int is_repeated;
    int j;
    int k;
    int i = 0;

    while(str2[i])
    {
        is_repeated = 0;
        k = 0;
        while (str1[k] && !is_repeated)
        {
            if(str1[k] == str2[i])
                is_repeated = 1;
            k++;
        }
        j = i - 1;
        while (!is_repeated && j > -1)
        {
            if(str2[j] == str2[i])
                is_repeated = 1;
            j--;
        }
        if (!is_repeated)
            write(1, str2 + i, 1);
        i++;
    }
}

void ft_union(char *str1, char *str2)
{
    check_first(str1);
    check_second(str1, str2);
}

int main(int argc, char ** argv)
{
    if (argc == 3)
        ft_union(argv[1], argv[2]);
    write (1, "\n", 1);
    return (0);
}