#include <stdlib.h>
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char 	*substr;

	s_len = 0;
	while (s[s_len])
		s_len++;
	if (s_len == 0)
		return (NULL);
	if (start + len > s_len)
		len = s_len - start;
	substr = (char *)malloc((sizeof(char) * len) + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
    while (i < len)
    {
		substr[i] = s[start + i];
		i++;
    }
	substr[i] = '\0';
	return (substr);
}       

int	main(void)
{
	char	*result;

	printf("--- Applying Structural Testing --- \n");

	// TEST 1: Branch coverage (IF = true)
	// Concept: We need to hit the path where (start + len > s_len)
	result = ft_substr("ABCD", 1, 100);
	printf("Test 1 (If True): Expected 'BCD' -> Got '%s'\n", result);
	free(result);

	// TEST 2: Branch coverage (IF = false)
	// Concept: (start + len <= s_len)
	result = ft_substr("ABCD", 1, 3);
	printf("Test 2 (If false): Expected 'BCD' -> Got '%s'\n", result);
	free(result);

	// TEST 3: Loop Boundary Adequacy (0 Iterations)
    // Concept: Does the loop handle running 0 times?
    result = ft_substr("ABCD", 0, 0);
    printf("Test 3 (Loop 0):   Expected ''     -> Got '%s'\n", result);
    free(result);

	// TEST 4: Loop Boundary Adequacy (1 Iteration)
    // Concept: Does the loop handle running exactly 1 time?
    result = ft_substr("ABCD", 0, 1);
    printf("Test 4 (Loop 1):   Expected 'A'    -> Got '%s'\n", result);
    free(result);

	printf("--- STARTING STRESS TESTS ---\n");

    // CASE 1: The Underflow Crash
    // Goal: Test if code handles (s_len - start) when start > s_len
    // Hypothesis: (0 - 1) will wrap to SIZE_MAX and cause massive malloc
    printf("\n[TEST 1] Testing s='', start=1 (The Underflow)\n");
    result = ft_substr("", 1, 1);
    if (result == NULL)
        printf("PASS: Correctly returned NULL (or handled gracefully)\n");
    else
    {
        printf("FAIL: Returned pointer %p (likely allocated HUGE memory)\n", result);
        free(result);
    }
	
}