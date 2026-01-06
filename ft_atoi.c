#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int ft_atoi(const char *nptr)
{
    int i;
    int result;
    int sign;

    i = 0;
    result = 0;
    sign = 1; 

    while(nptr[i] != '\0')
    {
        if(nptr[i] == '-')
        {
            sign = -sign;
        }

        if(nptr[i] >= '0' && nptr[i] <= '9')
        {
            result = result * 10 + (nptr[i] - '0');
        }
        i++;
    }

    return (result * sign);
}

void test(char *s)
{
    printf("string = %s, ft_atoi: %d, atoi = %d\n", s, ft_atoi(s), atoi(s));
}

int main()
{
    test("60");
    test("---80");
    test("---+++--+---7034632");
    test("++++3354654");
}
