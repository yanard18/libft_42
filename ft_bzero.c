#include "libft.h"
#include <strings.h>
#include <stdio.h>

// memset'ten tek farkı belleği sadece null byte ile doldurabilmemiz

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
	
	
	// pointer aritmetiği type bilgisi istediği için ve void * sadece adres taşıdığı için, 
	// bellek gezmediği için, void'in bir boyutu olmadığı için cast etmemiz gerekiyor

	// unsigned char *p = s;
	// while (n--)
	// {
	// 	*p++ = 0;
	// }
	
}

void test(const char *s, size_t n)
{
	/* 
		Bu fonksiyon null byte olarak değiştirdiğimiz bir bellek alanını string olarak ekrana yazdırır
		%s formatı ile okuyamıyoruz çünkü %s \0 gördüğünde duruyor
		yani yazdığımız null byte'lar 0. index'ten başladığı için %s 0. byte'ta okumayı bırakıyor

	*/

	size_t i = 0;

	while(i < n)
	{
		if (s[i] == '\0')
		{
			printf("\\0");
		}
		else 
		{
			printf("%c", s[i]);
		}
		i++;
	}
}

int main()
{
	char b[] = "ofbisusya";
	size_t n = 4;

	ft_bzero(b, n);
	test(b, sizeof(b)); 
	// sizeof stringe değil belleğe bakar. Bu nedenle en sondaki null terminatoru de sayar.



	//bzero(b, n);
	// size_t i = 0; 

	// ft_bzero(b, n);
	// printf("ft_bzero: %s\n", b);

	// bzero(b, n);
	// printf("bzero: %s\n", b);

	// while (i < sizeof(b))
	// {
	// 	printf("%d", (unsigned char)b[i]);
	// 	i++;
	// }


	return (0);
}