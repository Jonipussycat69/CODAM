// #include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }	t_list;

// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*new_node;

// 	new_node = (t_list *)malloc(sizeof(t_list));
// 	if (!(new_node))
// 		return (NULL);
// 	new_node->content = content;
// 	new_node->next = NULL;
// 	return (new_node);
// }

// int	main(void)
// {
// 	int		*data;
// 	int		print;
// 	t_list	*new_node;

// 	data = malloc(sizeof(int));
// 	if (!(data))
// 		return (0);
// 	*data = 42;
// 	new_node = ft_lstnew(data);

// 	print = *(int *)new_node->content;
// 	printf("%d\n", print);
// 	free(new_node);
// 	free(data);
// 	return (0);
// }

int	main(void)
{
	printf("%d\n", isascii(30));
	printf("%d\n", isalpha(100));
	printf("%d\n", isalnum(49));
	printf("%d\n", isdigit(49));
	printf("%d\n", isprint(70));
	return (0);
}