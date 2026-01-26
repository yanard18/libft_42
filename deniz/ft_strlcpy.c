#include <stddef.h>
#include <stdio.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int	src_len;
	int	i;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

int		main(void)
{
	char	dest[10];

	printf("==========STRUCTURAL TESTING============\n");
	printf("r: %lu, dest: %s\n", ft_strlcpy(dest, "ABCD", 0), dest);
	printf("r: %lu, dest: (%d)\n", ft_strlcpy(dest, "ABCD", 1), dest[0]);
	printf("r: %lu, dest: %s\n", ft_strlcpy(dest, "ABCD", 2), dest); 
	printf("r: %lu, dest: %s\n", ft_strlcpy(dest, "ABCD", 10), dest); 
}
