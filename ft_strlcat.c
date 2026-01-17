#include "libft.h"
#include <stdio.h>
#include <string.h>

/*

    - src string'ini dst'nin sonuna ekler
    - toplamda en fazla size - 1 karakter olacak şekilde ekleme yapar
    - eğer size > 0 ise dst her zaman '\0' ile sonlanır

    - size, dst buffer'ının toplam boyutu olacak

    - size == 0 ise:
        hiçbir şey eklenmez
        return src_len + size (yani src_len)

    - return edilen değer:
        dst'nin BAŞLANGIÇ uzunluğu + src'in uzunluğudur

    - return >= size ise:
        dst buffer yetersiz demektir (truncation olmuştur)


    1. dst ve src'nin uzunluğunu hesapla
    3. eğer size <= dst_len ise:
        hiçbir şey ekleme
        return size + src_len
    4. aksi halde:
        dst'nin sonundan başlayarak
        en fazla size - dst_len - 1 karakter src'den ekle
        dst'nin sonuna '\0' koy
    5. return dst_len + src_len

*/

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t	dst_len;
    size_t	src_len;
    size_t	i;

    dst_len = 0;
    while (dst[dst_len] && dst_len < size)
        dst_len++;

    src_len = 0;
    while (src[src_len])
        src_len++;

    if (size <= dst_len)
        return (size + src_len);

    i = 0;
    while (src[i] && (dst_len + i) < size - 1)
    {
        dst[dst_len + i] = src[i];
        i++;
    }
    dst[dst_len + i] = '\0';

    return (dst_len + src_len);
}

void test()
{
    /*
        dst boş, src tamamen eklenecek
        return = dst_len (0) + src_len
    */
    char dst1[20] = "";
    size_t return1;

    return1 = ft_strlcat(dst1, "Hello", sizeof(dst1));
    printf("dst: %s\n", dst1);
    printf("return: %zu\n\n", return1);


    /*
        dst dolu, src tamamen sığıyor
    */
    char dst2[20] = "Hello ";
    size_t return2;

    return2 = ft_strlcat(dst2, "World", sizeof(dst2));
    printf("dst: %s\n", dst2);
    printf("return: %zu\n\n", return2);


    /*
        dst + src size'ı aşıyor
        truncation olacak
    */
    char dst3[10] = "Hello";
    size_t return3;

    return3 = ft_strlcat(dst3, "World!!!", sizeof(dst3));
    printf("dst: %s\n", dst3);
    printf("return: %zu\n", return3);

    if (return3 >= sizeof(dst3))
        printf("dst yetersiz\n\n");


    /*
        size == 0
        hiçbir şey eklenmez
    */
    char dst4[10] = "Hello";
    size_t return4;

    return4 = ft_strlcat(dst4, "World", 0);
    printf("dst: %s\n", dst4);
    printf("return: %zu\n\n", return4);


    // orijinal strlcat ile karşılaştırma

    char dst_ft[10] = "libft";
    char dst_org[10] = "libft";
    size_t return_ft;
    size_t return_org;

    return_ft = ft_strlcat(dst_ft, "_test", sizeof(dst_ft));
    return_org = strlcat(dst_org, "_test", sizeof(dst_org));

    printf("ft_strlcat dst: %s, return: %zu\n", dst_ft, return_ft);
    printf("strlcat dst: %s, return: %zu\n\n", dst_org, return_org);
}

int main()
{
    test();
    return (0);
}
