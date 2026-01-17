#include "libft.h"
#include <stdio.h>
#include <string.h>

/* 
s1 ve s2 char dizilerinin ilk n byte kadarını karşılaştırıyoruz.
ilk farklı byte'da bu iki farklı karakterin ascii değerlerinin farkı returnlenir.
*/

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    while (n > 0)
    {
        if (*s1 != *s2)
            return ((unsigned char)*s1 - (unsigned char)*s2);
        if (*s1 == '\0')
            return (0);
        s1++;
        s2++;
        n--;
    }
    return (0);

    /*
    adres arttırarak değil de değişkenle de yapılabilirdi ama pointerlar daha havalı
    
    size_t i;

    i = 0;
    while((s1[i] != '\0' || s2[i] != '\0') && i < n)
    {
        if (s1[i] != s2[i])
        {
            return (s1[i] - s2[i]);
        }
        i++;
    }
    return (0);
    */
}

void test(size_t n)
{
    char s1[] = "zehra";
    char s2[] = "zebra";

    printf("for %ld: (%s - %s)  --> ft_strncmp: %d, strncmp: %d\n", n, s1, s2, ft_strncmp(s1, s2, n), strncmp(s1, s2, n));
    // size_t long unsigned int olduğu için format specifier'ı %lu (unsigned long) ya da %ld (long)
    // return value negatif olabileceği için %ld daha garanti 
    char s3[] = "mer habaa";
    char s4[] = "merhabaa";

    printf("for %ld: (%s - %s)  --> ft_strncmp: %d, strncmp: %d\n", n, s3, s4, ft_strncmp(s3, s4, n), strncmp(s3, s4, n));
    
    char s5[] = "4";
    char s6[] = "9";

    printf("for %ld: (%s - %s) --> ft_strncmp: %d, strncmp: %d\n", n, s5, s6, ft_strncmp(s5, s6, n), strncmp(s5, s6, n));

    printf("\n");
}

int main()
{
    test(4);
    test(3);
    test(2);

    return (0);
}