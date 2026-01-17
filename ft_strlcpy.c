#include "libft.h"
#include <stdio.h>
#include <string.h>

/*

    - src string'ini dst'ye kopyalar
    - en fazla size - 1 karakter kopyalar
    - eğer size > 0 ise dst her zaman '\0' ile sonlanır
    - src'in uzunluğunu return eder

    - size == 0 ise hiçbir şey kopyalanmaz
    - bu durumda size == 0 olursa return
    - fonksiyon string kopyalar ama overflow yapmaz


    - return edilen değer dst'nin yeterli olup olmadığını anlamamızı sağlar
    - eğer return >= size ise dst yetersiz demektir


    1. src'in uzunluğunu hesapla (src_len)
    2. eğer size == 0 ise:
        src_len'i return et
    3. size > 0 ise:
        en fazla size - 1 karakter kopyala
        dst'nin sonuna null terminator koy
    4) src_len'i return et


*/

size_t ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;

	if (dstsize == 0) // yer yok dst'ye dokunamayız o yüzden direkt return srclen
		return (src_len);

	i = 0;
	while (src[i] && i < dstsize - 1) // dstsize - 1 kadar kopyalanır son byte \0 karakteri için
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';

	return (src_len);
}

void test()
{
    /* 
        dst > src (tüm char dizsi kopyalanacak)
        return edilen değer src uzunluğu olacak
    */
    char dst1[20];
    size_t return1;

    return1 = ft_strlcpy(dst1, "Hello", sizeof(dst1));

    printf("dst: %s\n", dst1);
    printf("return: %zu\n\n", return1);
    // %zu size_t tipindeki değerleri yazdırmak için kullanılan format specifier. sizeof()'um return tipi size_t olduğu için %zu kullanıyoruz.
    // %lu da kullanılabilirdi ama farklı platformlarda hata verebilir ama 42'de çalışıyorsa kullanmakta sorun yok


    /*
    dst < src (size - 1 karakter kopyalanır)
    src uzunluğu returnlenicek
    */
    char dst2[5];
    size_t return2;

    return2 = ft_strlcpy(dst2, "HelloWorld", sizeof(dst2));
    printf("dst: %s\n", dst2);
    printf("return: %zu\n", return2);

    if (return2 >= sizeof(dst2))
        printf("dst yetersiz\n\n");


    /*
    size == 0
    hiçbir şey kopyalanmıyor 
    return src olucak
    */
    char dst3[5] = "xxx";
    size_t return3;

    return3 = ft_strlcpy(dst3, "helloworld", 0);
    printf("dst: %s\n", dst3);
    printf("return: %zu\n\n", return3);


    // orijinal strlcpy

    char dst_ft[10];
    char dst_org[10];
    size_t return_ft;
    size_t return_org;

    return_ft = ft_strlcpy(dst_ft, "libft_test", sizeof(dst_ft));
    return_org = strlcpy(dst_org, "libft_test", sizeof(dst_org));

    printf("ft_strlcpy dst: %s, return: %zu\n", dst_ft, return_ft);
    printf("strlcpy dst: %s, return: %zu\n\n", dst_org, return_org);

}

int main()
{
    test();
    return (0);
}