#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // malloc içim

/*
    1. The strdup() function allocates sufficient memory for a copy of the
     string s1, 
    2. does the copy, and returns a pointer to it.
    3. The pointer may subsequently be used as an argument to the function free(3).

    strdup = strlen + malloc + strcpy

    amaç: verilen char dizisnin tam bir kopyasını malloc ile yer tahsis edip oluşturmak

    - malloc kullanılacak
    - null terminator
    - orijinal string değişmicek kopya oluşturucaz
    - malloc başarısız olursa return null

    1. s1 length hesapla (null terminator hariç)
    2. malloc il e len + 1 kadar yer ayır 
    3. malloc başarısız olursa return null
    4. s1'i tek tek yeni adresine kopyala
    5. \0 ile sonlandır
    6. yeni dizinin pointerını returnle 

*/

char	*ft_strdup(const char *s1)
{
    char    *dup;
    size_t  len;
    size_t  i;

    len = 0;
    while (s1[len])
        len++;

    dup = (char *)malloc(len + 1);
    if (!dup)
        return (NULL);
    i = 0;
    while (*s1)
        dup[i++] = *s1++;
    dup[i] = '\0';
    return (dup);
}

// char * ft_strdup(const char *s1)
// {
//     int str_len;
//     char * s2;

//     str_len = ft_strlen(s1);
//     s2 = (char *)malloc((str_len + 1) * sizeof(char));

//     while(s1)
//     {
//         *s2 = *s1;
//         s1++;
//         s2++;
//     }

//     *s2 = '\0';

//     return (s2);

// }

// int main()
// {
//     // ft_strdup("denizzzz");
//     strdup("original");

//     // free(s2);
//     return (0);
// }
