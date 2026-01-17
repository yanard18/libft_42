#include "libft.h"
#include <string.h>
#include <stdio.h>

/*
    - memset() fonksiyonu s void dizisinin başından başlayarak n byte kadar c yazdırılır
    - returns a pointer to the memory area s 
    - memory'yi set etmekten geliyor. Yeni bir dizi returnlemiyoruz, var olanı set ediyoruz.
*/

void *ft_memset(void *b, int c, size_t n)
{
    // bu fonksiyon kendi yolcuğunda 15 satır kilo verdi belirtmek isterim
    while(n--)
    {
         ((unsigned char *)b)[n] = (unsigned char)c; 
    }
    return (b); 
}

// int main()
// {
//     char s[] = "merhaba";
//     ft_memset(s, 'x', 3);
//     printf("%s", s);

//     return (0);
// }
