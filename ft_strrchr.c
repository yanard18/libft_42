#include "libft.h"
#include <stdio.h>

// strchr aranan karakteri ilk bulduğu yerden sonrasını returnler
// strrchr aranan karakteri son bulduğu yerden sonrasını returnler




/* char dizisinin sonuna gidiyorum, 
geri gelirken ilk bulduğum karakter aslında son bulduğumuz karakter oluyor
ama bu yöntemle stringi (neredeyse) 2 kere taradığımız için sağlıklı olmuyor
*/


char *ft_strrchr(const char *s, int c)
{
    const char  *last;

    last = NULL;

    while (*s)
    {
        if (*s == (char)c)
            last = s;
        s++;
    }

    /*
        Eğer aranan karakter '\0' ise:
        string'in sonundaki null terminator'un adresi döndürülür
    */
    if ((char)c == '\0')
        return ((char *)s);

    return ((char *)last);
}

void test(char *str, int c)
{
    printf("%c(%d) in %s -> ft_strrchr: %s, strrchr: %s\n", c, c, str, ft_strrchr(str, c), strrchr(str, c));
}

int main()
{
    test("zehraa", 'a');
    test("zehraa", '\0'); 
    test("zehraa", 'x'); 
    test("", 'a');  
    test("", '\0');  

    return (0);
}



// char * ft_strrchr(const char *s, int c)
// {
//     int len;

//     len = ft_strlen(s);

//     while(len-- >= 0)
//     {
//         if(s[len] == (char)c)
//         {
//             return ((char *)(s + len));
//         }
//     }
//     return (NULL);
// }

// int main()
// {
//     char str[] = "merhabaaaskimm";
//     printf("%s", ft_strrchr(str, 'a'));
// }
