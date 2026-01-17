#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
    {
        return (1);
    }
    return (0);
}

void test(int c)
{
	printf("tested char: [%d] %c, ft_isdigit: %d, isdigit: %d\n", c, c, ft_isdigit(c), isdigit(c));
}

int main()
{
    test('0');
    test('9');
    test('5');
    test('-');
    test('d');
    test('Z');
    test(' ');

    /*
        sadece hoşuma gittiği için yapmak istedim 

        int i = -1;
        while(i++ < 128)
        {
            test(i);
        }
    */
        
    return (0);
}
