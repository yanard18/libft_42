#include "libft.h"
#include <stdio.h>
#include <string.h>

char *ft_strchr(const char *s, int c)
{
    if(*s != '\0')
    {
        while(*s++)
        {
            if(*s == (char)c)
            {
                return ((char *)s);
            }

        }

        if((char)c == '\0')
        {
            return ((char *)s);
        }
    }
    
    return(NULL);
}

void test(char *str, int c)
{
    printf("%c(%d) in %s -> = ft_strchr: %s, strchr: %s\n", c, c, str, ft_strchr(str, c), strchr(str, c));
}

int main()
{
    test("zehraa", 'a');
    test("zehraa", '\0');
    test("zehraa", 'x');
    test("", 'a');
    test("", 'x');
}