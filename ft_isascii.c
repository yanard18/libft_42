#include "libft.h"
#include <stdio.h>
#include <ctype.h>

// libft projesine göre classification fonksiyonlarının return value sadece 1 ya da 0 olabilir
int ft_isascii(int c)
{
    if (c >= 0 && c <= 127)
    {
        return (1);
    }
    return (0);
}

void test(void)
{
    // printf("[%d] %c --> ft_isascii: %d, isascii: %d\n", c, c, ft_isascii(c), isascii(c));

    int i = 0;
    while(i < 256)
    {
        printf("[%d] ft_isascii: %d, isascii: %d\n", i, ft_isascii(i), isascii(i));
        i++;
    }
}

int main()
{
    // test('a');
    // test('3');
    // test(' ');
    // test('*');
    // test('-');
    // test('?');
    // test('.');
    // test('\n');
    // test('\t');
    // test('\r');

    test();

    return (0);
}