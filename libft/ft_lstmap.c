/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: joni <joni@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/20 11:54:46 by joni          #+#    #+#                 */
/*   Updated: 2023/10/20 19:20:30 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**head;
	t_list	*temp;

	temp = *head;
	if (lst == NULL)
		return (NULL);
	temp = ft_lstnew(lst->content);
	f(temp->content);
	while (lst->next != NULL)
	{
		lst = lst->next;
		ft_lstadd_back(head, ft_lstnew(lst->content));
		temp = temp->next;
		f(temp->content);
	}
	return (*head);
}

/*TEST IT*/
//ASK!!! WHAT TO DO