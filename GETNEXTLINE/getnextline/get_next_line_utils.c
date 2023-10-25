/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: joni <joni@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/24 19:43:20 by joni          #+#    #+#                 */
/*   Updated: 2023/10/25 13:52:18 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(void *buf)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!(new_node))
		return (NULL);
	new_node->buf = buf;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;
	t_list	*temp2;

	if (lst == NULL)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		free(temp->buf);
		temp2 = temp;
		temp = temp->next;
		free(temp2);
	}
	*lst = NULL;
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->buf);
	free(lst);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*r;
	size_t	t;

	t = nmemb * size;
	if (nmemb != 0 && size != 0 && t / nmemb != size)
		return (NULL);
	r = (void *) malloc(t);
	if (r)
		ft_memset(r, 0, t);
	return (r);
}
