#include <stdio.h>
#include <ctype.h>

int	ft_isprint(char c)
{
	return (c >= 32 && c <= 126);
}

void	test(void)
{
	int	c;

	c = 0;
	while (c < 256)
	{
		if ((ft_isprint(c) > 0 && isprint(c) == 0) || ft_isprint(c) == 0 && isprint(c) > 0)
		{
			printf("[ERROR] char: %d, ft_isprint: %d, isprint: %d\n", c, ft_isprint(c), isprint(c));
			break ;
		}
		printf("[PASSED] char: %d, ft_isprint: %d, isprint: %d\n", c, ft_isprint(c), isprint(c));
		c++;
	}
}

int	main(void)
{
	test();
	return (0);
}

