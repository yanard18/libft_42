#include <stdio.h>
#include <ctype.h>

int	ft_isprint(char c)
{
	return (c >= 32 && c <= 126);
}

void	test(char c)
{
	printf("char: %c(%d), ft_isprint: %d, isprint: %d\n", c,c, ft_isprint(c), isprint(c));
}

int	main(void)
{
	test(31);
	test(32);
	test(33);
	test(126);
	test(127);
	return (0);
}

