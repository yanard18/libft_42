#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

static size_t	strcount(char const *s, char c)
{
	size_t	count;
	int	started;

	started = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && !started)
			started = 1;
		else if (*s == c && started)
		{
			count++;
			started = 0;
		}
		s++;
		if (*s == 0 && started)
			count++;
	}
	return (count);
}

void	test_strcount(char const *s, char c, size_t expected)
{
	size_t	res;

	res = strcount(s, c);
	if (res == expected)
		printf("[+] str: %s, count: %zu\n", s, res);
	else
		printf("[-] str: %s, count: %zu\n", s, res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	long	len;
	size_t 	count;

	res = (char **)malloc(sizeof(char *) * (strcount(s, c) + 1));
	if (!res)
		return (NULL);
	count = 0;
	while (*s)
	{
		len = 0;
		while (*s == c)
			s++;
		while (s[len] != c && s[len] != 0)
			len++;
		if (len > 0)
			res[count++] = ft_substr(s, 0, len);
		s += len;
	}
	res[count] = NULL;
	return (res);
}

int	main(void)
{
	/*
	test_strcount("***Hello**World*!***", '*', 3);
	test_strcount("Hello**World*!***", '*', 3);
	test_strcount("Hello*World*!***", '*', 3);
	test_strcount("Hello*World*!", '*', 3);
	test_strcount("HelloWorld!", '*', 1);
	test_strcount("", '*', 0);
	test_strcount("*****", '*', 0);
	test_strcount("a**", '*', 1);
	test_strcount("**a", '*', 1);
	test_strcount("*a*a", '*', 2);
	test_strcount("Hello!", '\0', 1);
	*/

	char **res = ft_split("//path/to/file//.exe///", '/');
	for (int i = 0; res[i] != NULL; i++)
	{
		printf("%s\n", res[i]);
		free(res[i]);
	}
	free(res);
	return (0);
}
