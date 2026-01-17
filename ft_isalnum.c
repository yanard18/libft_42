#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int ft_isalnum(int c)
{
    if (ft_isalpha(c) || ft_isdigit(c))
    {
        return (1);
    }

    return (0);
}

void test(int c)
{
    printf("tested char: [%d] %c, ft_isalnum: %d, isalnum: %d\n", c, c, ft_isalnum(c), isalnum(c));

}

int main()
{
    test('a');
    test('f');
    test('8');
    test('-');
    test(' ');
    test('x');
    test('\r');

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
