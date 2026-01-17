#include "libft.h"
#include <string.h>
#include <stdio.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *p1;
    const unsigned char *p2;

    p1 = (const unsigned char *)s1;
    p2 = (const unsigned char *)s2;

    while (n > 0)
    {
        if (*p1 != *p2)
            return (*p1 - *p2);
        p1++;
        p2++;
        n--;
    }
    return (0);
}

void test(const void *s1, const void *s2, size_t n)
{
    int ft_return;
    int org_return;

    ft_return = ft_memcmp(s1, s2, n);
    org_return = memcmp(s1, s2, n);

    printf("memcmp test (n = %zu)\n", n);
    printf("ft_memcmp: %d\n", ft_return);
    printf("memcmp: %d\n", org_return);
}

int main()
{
    char c1[] = "zehra";
    char c2[] = "zebra";

    test(c1, c2, 2);  
    test(c1, c2, 4);   
    test(c1, c2, 0);

    unsigned char b1[] = {1, 2, 0, 3};
    unsigned char b2[] = {1, 2, 0, 4};

    test(b1, b2, 4);  

    return (0);
}