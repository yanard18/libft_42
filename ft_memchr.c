#include "libft.h"
#include <stdio.h>
#include <string.h>

/*

    The memchr() function locates the first occurrence of c (converted to an
    unsigned char) in string s.

    Returns a pointer to the byte located, 
    or NULL if no such byte exists within n bytes.

*/

void *ft_memchr(const void *s, int c, size_t n)
{
    const unsigned char *ptr;

    ptr = (const unsigned char *)s;
    while (n--)
    {
        if (*ptr == (unsigned char)c)
            return ((void *)ptr);
        ptr++;
    }
    return (NULL);
}

void test(const void *s, int c, size_t n)
{
    void *ft_return;
    void *org_return;

    ft_return = ft_memchr(s, c, n);
    org_return = memchr(s, c, n);

    printf("memchr test (c = %d, n = %zu)\n", c, n);
    printf("ft_memchr: %p\n", ft_return);
    printf("memchr: %p\n", org_return);

    printf("ft_memchr: %p\nExpected: %p", ft_memchr(s, c, 10), memchr(s, c, 10));
}

int main()
{
    char str[] = "zehraa";

    test(str, 'z', 7);
    test(str, 'x', 7);
    test(str, '\0', 8);

    unsigned char data[] = {10, 20, 0, 30, 40};

    test(data, 0, 5);
    test(data, 30, 5);
    test(data, 50, 5);

    return (0);
}
