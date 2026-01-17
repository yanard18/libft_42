#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int	ft_isprint(char c)
{
    if (c >= 32 && c<= 126) // printable characters including space
	{
		return (1);
	}
	return (0);
}

void test(void)
{
    int i = 0;
    while(i < 256)
    {
        printf("[%d] %c --> ft_isprint: %d, isprint: %d\n", i, i, ft_isprint(i), isprint(i));
        i++;
    }
}

int main()
{
    test();
    return (0);
}