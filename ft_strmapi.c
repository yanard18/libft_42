#include "libft.h"
#include <stdio.h>
#include <string.h> // strlen() için (mainde kullandım)
#include <stdlib.h> // malloc için

/*

strmapi --> str + map + i (index) : string üzerinde index ile map yap 
Function            Name ft_strmapi
Prototype           char *ft_strmapi(char const *s, char (*f)(unsigned
int, char));
Parameters          s: The string to iterate over.
                    f: The function to apply to each character.
Return Value        The string created from the successive applications
                    of ’f’.
                    Returns NULL if the allocation fails.
External Function   malloc
Description         Applies the function f to each character of the
                    string s, passing its index as the first argument
                    and the character itself as the second. A new
                    string is created (using malloc(3)) to store the
                    results from the successive applications of f.



    - nihai bir görevi olmayan f fonksiyonu s char dizisindeki tüm karakterlere uygulanacak
    - bu f() fonksiyonu 
    - malloc kullanılacak
    - return f fonksiyonu uygulanmış olan yeni char dizisi
    - f fonksiyonu index ve char olarak iki parametre alacak


    kısaca strmapi() fonksiyonu verilen f() fonksiyonunu verilen s char dizisinin
    tüm karakterlerine tek tek uyguluyor ve f() uygulanan karakterler için malloc
    ile oluşturduğumuz yeni char dizisini return ediyor
*/

// c'de bir fonksiyon parametre olarak fonksiyon alamazmış 
char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int i;
    char *result;

    if (s == NULL)
    {
        return (NULL);
    }

    result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
    i = 0;

    if (result == NULL)
    {
        return (NULL);
    }

    while(s[i])
    {
        result[i] = f(i, s[i]);
        i++;
    }

    result[i] = '\0';
    return (result);
}

/*
    şimdilik sadece strmapi() yapmış olmak için basit bir
        toupper() fonksiyonu yazıyorum 
*/
char f(unsigned int index, char c)
{
    (void) index; // kullanılmayan parametreleri böyle susturmamız gerekiyormuş
    if (c >= 97 && c <= 122)
    {
        return (c - 32);
    }
    return (c);
}

int main()
{
    size_t i = 0;
    char s[] = "abcde";

    /*
        burada ilk başta ben 
        char *result;
        result[i] = ft_strmapi(s, f);
        yapmaya çalışmıştım ama result hiçbir yeri göstermiyor, result[i] de bizim malloc ile
            tahsis ettiğimiz belleğe değil derastgele bir adrese yazmaya çalışıyor. 
        Ayrıca result[i] bir char ama ben bu char'a char * (pointer) koymaya çalışmışım. 
    */
    char *result = ft_strmapi(s, f); 
    
    /*
        burada result (pointer) != '\0' (char) olarak iki farklı 
            type'ı karşılaştırmaya çalışmştım. '\0' yerine NULL yaparsak 
    */
    while((i < strlen(s)) && (result != NULL))
    {
        printf("%c", result[i]);
        i++;
    }

    return (0);
}