#include "libft.h"
#include <stdio.h>

/*
    strmapi gibi ama burada yeni bir char dizisi oluşturmuyoruz
    değişiklikleri orijinal string üzerinde yapıyoruz

*/

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    int i;

    i = 0;
    while (s[i])
    {
        (*f)(i, &s[i]); // s char dizisindeki i. karakterin adresini alıyoruz çünkü
        // & kullandım çünkü amacım karakterin değerini değil bellekteki yerini değiştirmek

        /* 
            derleyici zaten fonksiyonun imzasından dolayı f'in bir fonksiyon pointerı olduğunu bildiği
            için f() olarak da kullanılabilir, (*f)() olarak yazmak şart değil ama daha havalı
        */
       i++;
    }
}

char *f(unsigned int c, char v)
{
    if (c >= 97 && c <= 122)
    {
        return (c - 32);
    }
    return (c);
}

int main()
{
    ft_striteri("eylul zehra", f);

    return (0);
}
