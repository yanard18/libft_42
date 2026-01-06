void	ft_bzero(void *b, size_t len)
{
	size_t		i;
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	if (len == 0)
		return ;
	i = 0;
	while (i < len)
	{
		*(ptr+i) = 0;
		i++;
	}
}
