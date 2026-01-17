#include "libft.h"
#include <stdio.h> 
#include <string.h> // strlen() için

size_t ft_strlen(const char *s)
{
    size_t i;
    
    i = 0;
    while(s[i] != '\0')
    {
        i++;
    }
    return (i);
}

void test(char * str)
{
    printf("[%s] --> ft_strlen(): %lu, strlen(): %lu\n", str, ft_strlen(str), strlen(str));
}

/*
int main()
{
    test("a");
    test("hello");
    test("hello world");
    test("252-015 049*1345-42 _?");
    test("\t\n\v\f\r");
    test(" ");
    test("");
}
*/