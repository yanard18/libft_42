#ifndef LIBFT_H
#define LIBFT_H 

#include <stddef.h>
#include <unistd.h>

// libc functions
int	ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int	ft_isprint(char c);
size_t ft_strlen(const char *s);

void	ft_bzero(void *s, size_t n);
void *ft_memset(void *b, int c, size_t n);

int ft_toupper(int c);
int ft_tolower(int c);

char *ft_strchr(const char *s, int c);
char * ft_strrchr(const char *s, int c);
int ft_atoi(const char *nptr);
int ft_strncmp(const char *s1, const char *s2, size_t n);

// additional functions
char *ft_substr(char const *s, unsigned int start, size_t len);
void ft_putstr_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);
void ft_putendl_fd(char *s, int fd);
void ft_putchar_fd(int c, int fd);

void ft_striteri(char *s, void (*f)(unsigned int, char*));
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

#endif