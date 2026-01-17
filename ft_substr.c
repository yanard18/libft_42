#include "libft.h"
#include <stdio.h>

/*
    
    - start string’in uzunluğunu aşarsa → boş string döndürülmeli.
    - len string’i aşarsa kalan kısmı returnle
    - malloc kullanılacak 

    amaç: verilen char dizisinden ten yeni bir substring oluşturur
    
    1. s stringinin uzunluğunu bul (strlen(s)).
    2. if start >= strlen(s) boş string oluştur
    3. if len > strlen(s) - start 
        len = strlen(s) - start
    4. malloc (len + 1)
    5. malloc başarısız olursa return null 
    6. s'in start indexinden başlayarak len char kopyala
    7. substinrgi \0 ile sonlandır
    8. pointerı return et


    ft_substr: verilen string'den substring oluşturur
    s: orijinal string
    start: substring başlangıç indeksi
    len: substring maximum uzunluğu
    return: malloc ile ayrılmış substring veya NULL

*/


char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *substr;
    size_t  i;
    size_t  s_len;

    if (!s)
        return (NULL);

    s_len = 0;
    while (s[s_len])
        s_len++;

    if (start >= s_len)
        len = 0;
    else if (len > s_len - start)
        len = s_len - start;

    substr = (char *)malloc(sizeof(char) * (len + 1));
    if (!substr)
        return (NULL);

    i = 0;
    while (i < len)
    {
        substr[i] = s[start + i];
        i++;
    }
    substr[i] = '\0';

    return (substr);
}

void test(char *s, unsigned int start, size_t len)
{
    char *ft_result;
    char *org_result;

    ft_result = ft_substr(s, start, len);

    printf("ft_substr(s=\"%s\", start=%u, len=%zu) -> \"%s\"\n",
           s, start, len, ft_result);

    free(ft_result);
}

int main(void)
{
    test("Hello, World!", 7, 5);
    test("libft_test", 0, 4);
    test("OpenAI", 10, 3);
    test("Zehraa", 3, 10);
    test("", 0, 5);

    return (0);
}