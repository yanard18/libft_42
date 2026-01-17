#include "libft.h"
#include <stdio.h>
#include <stdlib.h> // atoi() için

/*
    atoi() fonksiyonu nptr'nin işaret ettiği char dizisinin 

    - The string may begin with an arbitrary amount of white space (strtol()) 
        (isspace yasakmış kendimiz yazıcaz)
    - followed by a single optional '+' or '-' sign (strtol())
    - digit ile karşılaşıldığında atoi uygulanır, 
        non-digit bir karakterde döngüden çıkar ve result returnlenir
    - atoi overflow ya da underflow handle etmez

*/

int ft_atoi(const char *nptr)
{
    int i;
    int result;
    int sign;

    i = 0;
    result = 0;
    sign = 1; 

    // ignore whitespaces and space
    while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
    {
        i++;
    }

    // check for signs
    if (nptr[i] == '+' || nptr[i] == '-') // sadece ilk işareti kontrol ediyor
    {
        if(nptr[i] == '-')
        {
            sign *= -1;
        }
        i++;
    }

    // atoi
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        result = result * 10 + (nptr[i] - '0');
        i++;
    }
    
    return (result * sign);
}

void test(char *s)
{
    printf("input: %s\t --> ft_atoi: %d  |  atoi = %d\n", s, ft_atoi(s), atoi(s));
}

int main()
{
    test("60");
    test("-80");
    test("+80");
    test("---80");
    test("+++--+---3462");
    test("    +++--+-+--+--8095");
    test("   -042");
    test("    a-42");
    test("1337c0d3");
    test("words and 987");
    test("     49375");
    test("\n42");
    test("\t\n\v\f\r ---++-+-  72834");
    test("-2147483648");
    test("2147483647");
    test("-2147483649");
    test("2147483649");
    test("9999999999");
    test("-9999999999");

    return (0);
}
