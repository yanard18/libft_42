#include "libft.h"
#include <stdio.h>

void	upper(unsigned int i, char *s)
{
	if (s[i] >= 97 && s[i] <= 122)
		s[i] -= 32;
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int i;

	i = 0;
	while (s[i])
		f(i++, s);
}



int	main(void)
{
	char	s[] = "abcde";
	ft_striteri(s, &upper);
	printf("%s\n", s);
	return (0);
}
