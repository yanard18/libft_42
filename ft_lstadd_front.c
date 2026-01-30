#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
int	main(void)
{
	t_list	*lst;
	int	x;

	x = 5;
	lst = ft_lstnew(&(int){42});
	ft_lstadd_front(&lst, ft_lstnew(&(int){10}), &x);
	printf("%d\n", *(int *)lst->content);
	return (0);
}
*/
