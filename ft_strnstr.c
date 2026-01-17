#include "libft.h"
#include <stdio.h>
#include <string.h>

#include <stddef.h> // size_t
#include <stdio.h>  // test
#include <string.h> // test karşılaştırması

/*
    amaç: haystack içinde needle arar, en fazla len karakter (klasik sunstring arama ama len sınırı var)
    return: needle'nin haystack içindeki ilk adresi veya null

    Amaç / Description

    - ilk len karakter içinde arama yapılır
    - bulursa needle'ın ilk karakterinin adresi 
        bulamazsa null
    - eğer needle boş stack ise return haystack
    
    1. if needle boşsa return haystack 
    2. while haystack 
        3. eğer haystack[i] == needle[0] olursa needle'ın geri kanalını kontrol et
        4. j == strlen(needle) kadar kontrol et
    5. i + j > len ise dur
    6. tüm needle haystack ile eşleşirse return haystack + i
    7. eşleşen hiçbir karakter yoksa return null

*/

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i; // haystack içinde ilerlemek için
    size_t j; // needle stringi içinde ilerlemek için

    if (!*needle) // needle boşsa
        return ((char *)haystack);

    i = 0;
    while (haystack[i] && i < len)
    {
        j = 0;
        while (needle[j] && (i + j) < len && haystack[i + j] == needle[j])
            j++;
        if (!needle[j])
            return ((char *)(haystack + i));
        i++;
    }
    return (NULL);
}

void test(const char *haystack, const char *needle, size_t len)
{
    char *ft_ret = ft_strnstr(haystack, needle, len);
    char *org_ret = strnstr(haystack, needle, len);

    printf("haystack= %s, needle=%s, len=%zu\n", haystack, needle, len);
    printf("ft_strnstr: %s\n", ft_ret);
    printf("strnstr   : %s\n", org_ret);
}

int main(void)
{
    test("hello world", "World", 12);
    test("hello world", "World", 13);
    test("libft_test", "lib", 3);
    test("libft_test", "test", 5);
    test("abcdef", "", 5);
    test("", "abc", 5);

    return (0);
}
