#include "libft.h"
#include <stdio.h> 
#include <string.h> // strlen() için

size_t ft_strlen(const char *s)
{
    size_t i;
    
    i = 0;
    while(s[i] != '\0')
        i++;
    return (i);
}
