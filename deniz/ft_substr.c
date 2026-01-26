#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char 	*substr;

	if (s == NULL)
		return (NULL);
	s_len = 0;
	while (s[s_len])
		s_len++;
	if (start >= s_len)
	{
		substr = malloc(1);
		substr[0] = '\0';
		return (substr);
	}
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc((sizeof(char) * len) + 1);
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, (s+start), len)
	i = 0;
    while (i < len)
    {
		substr[i] = s[start + i];
		i++;
    }
	substr[i] = '\0';
	return (substr);
}       

void	run_test(char *test, char const *s, unsigned int start, size_t len, char *expected)
{
	char	*result;

	result = ft_substr(s, start, len);
	if (result == NULL)
	{
		if (expected == NULL)
			printf("[+] SUCCESS: test=%s, params=(%s, %d, %lu), result: NULL\n", test, s, start, len);
		else
			printf("[-] ERROR: test=%s, params=(%s, %d, %lu), expected: %s but got: NULL\n", test, s, start, len, expected);
	}
	else
	{
		if (strcmp(expected, result) == 0)
			printf("[+] SUCCESS: test=%s, params=(%s, %d, %lu), result: %s\n", test, s, start, len, result);
		else
			printf("[-] ERROR: test=%s, params=(%s, %d, %lu), expected: %s but got: %s\n", test, s, start, len, expected, result);
	}
	free(result);
}

int	main(void)
{
	printf("=======================================\n");
	printf("========STRUCTURAL TESTING==========\n");
	printf("=======================================\n");
	run_test("_null_string_return_null", NULL, 0, 1, NULL);
	run_test("_empty_string_return_null_terrminate", "", 0, 0, "");
	run_test("start_out_of_bound_return_null", "", 1, 0, "\0");
	run_test("_ABCD_with_len_0_return_empty", "ABCD", 0, 0, "\0");
	run_test("_standard", "ABCD", 0, 3, "ABC");

	return (0);
}

