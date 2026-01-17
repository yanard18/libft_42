#include "libft.h"
#include <stdio.h> 

int ft_tolower(int c)
{
    if (c >= 65 && c <= 90)
    {
        return (c + 32);
    }
    return (c);
}

void test(int c)
{
    printf("(%d) %c --> %c\n", c, c, ft_tolower(c));
}

int main()
{
    /*
      int i;

        while((i >= 65 && i <= 90) || (i >= 97 && i <= 122))
        {
            test(i);
            i++;
        }
    */

    // printable karakterleri test etmek için
    unsigned int t;
    
    t = 31;
    while(++t < 127)
    {
        test(t);
    }

}