#include <stdio.h>
#include <ctype.h>

int	ft_isprintd(char c)
{
	if (c >= 32 && c<= 126)
	{
		return (1);
	}
	return (0);
}

void test(void)
{
	int	c;

	c = 0;
	while (c < 256)
	{
		if ((ft_isprintd(c) > 0 && isprint(c) == 0) || (ft_isprintd(c) == 0 && isprint(c) > 0))
		{
			printf("[ERROR] char: %d, ft_isprint: %d, isprint: %d\n", c, ft_isprintd(c), isprint(c));
			break ;
		}
		printf("[PASSED] char: %d, ft_isprint: %d, isprint: %d\n", c, ft_isprintd(c), isprint(c));
		c++;
	}
}

int	main(void)
{
	test();
	return (0);
}

