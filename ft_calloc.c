#include "libft.h"
#include <stdlib.h> // malloc
#include <stddef.h> // size_t
#include <stdio.h>

/*

    The calloc() function contiguously allocates enough space for count
    objects that are size bytes of memory each and returns a pointer to the
    allocated memory.  The allocated memory is filled with bytes of value
    zero.

    returns a pointer to allocated memory

    amaç: belirtilen boyutta malloc ile bir bellek bloğu tahsis edip sıfırlamak

    - malloc kullanılacak
    - tüm bytelar sıfırlanacak (ft_bzero kullanılabilir)
    - malloc başarısız olursa return null

    1. toplam byte miktarını hesapla (total)
    2. malloc(total)
    3. malloc başarısız olursa return null
    4. total byte'lık alanı sıfırla
    5. pointerı returnle
    
*/

void *ft_calloc(size_t count, size_t size)
{
    void    *ptr;
    size_t  total;

    total = count * size;

    ptr = malloc(total);
    if (!ptr)
        return (NULL);

    ft_bzero(ptr, total);

    return (ptr);
}

int main(void)
{
    int *arr;
    size_t n = 5;
    size_t i;

    arr = ft_calloc(n, sizeof(int));
    if (!arr)
        return (1);

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]); 
    printf("\n");

    free(arr);
    return (0);
}

// void *ft_calloc(size_t count, size_t size)
// {
//     void *ptr = malloc(count * size);
//     if (!ptr)
//         return (NULL);
//     memset(ptr, 0, count * size);
//     return (ptr);
// }
