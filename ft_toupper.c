#include "libft.h"
#include <stdio.h>

int ft_toupper(int c)
{
    if (c >= 97 && c <= 122)
    {
        return (c - 32);
    }

    return (c);
}

void test(int c)
{
    printf("(%d) %c --> %c\n", c, c, ft_toupper(c));
}

int main()
{
   int c;

    // c = -1;
    c = 0;

    while(c >= 97 && c <= 122)
    {
        test(c);
    }

    // while(c++ < 128)
    // {
    //     test(c);
    // }
}