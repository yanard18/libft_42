#include "libft.h"
#include <stdio.h>

int ft_isalnum(int c)
{
    if ((c >= 48 && c <= 57) || (c >= 65 && c <= 99) || (c >= 97 && c <= 122))
    {
        return (c);
    }

    return (0);
}

int main()
{
    printf("%d", ft_isalnum('5'));
}