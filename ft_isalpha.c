#include <stdio.h>
#include <ctype.h>

int	ft_isalpha(int c)
{
	// return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));

	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}

void test(int c)
{
	printf("tested char: [%d] %c, ft_isalpha: %d, isalpha: %d\n", c, c, ft_isalpha(c), isalpha(c));
}

int	main(void)
{
	// test(1);
	// test('a');
	// test('A');
	// test('z');
	// test('Z');
	// test('1');
	// test(18);

	int i = -1;
	while(i++ < 128)
	{
		test(i);
	}

	return (0);
}