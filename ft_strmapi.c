#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

size_t ft_strlen(const char *s);

char	upper(unsigned int idx, char c)
{
    (void)idx;
    if (c >= 97 && c <= 122)
        return (c - 32);
    return (c);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*res;
	unsigned int	i;

	res = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
		res[i++] = f(i, s[i]);
	res[i] = 0;
	return (res);
}

int main()
{
    char	*s = "lba";
    char	*res;

    res = ft_strmapi(s, &upper);
    printf("%s\n", res);
    free(res);
    return (0);
}
