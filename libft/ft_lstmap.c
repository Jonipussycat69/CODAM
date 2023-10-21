/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: joni <joni@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/20 11:54:46 by joni          #+#    #+#                 */
/*   Updated: 2023/10/21 12:20:03 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*temp;

	if (lst == NULL)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	if (head == NULL)
		return (NULL);
	temp = head;
	while (lst->next != NULL)
	{
		lst = lst->next;
		temp->next = ft_lstnew(f(lst->content));
		if (temp->next == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		temp = temp->next;
	}
	return (head);
}

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	**head;
// 	t_list	*temp;

// 	*head = NULL;
// 	temp = *head;
// 	if (lst == NULL)
// 		return (NULL);
// 	temp = ft_lstnew(lst->content);
// 	f(temp->content);
// 	*head = temp;
// 	while (lst->next != NULL)
// 	{
// 		lst = lst->next;
// 		ft_lstadd_back(head, ft_lstnew(lst->content));
// 		temp = temp->next;
// 		f(temp->content);
// 	}
// 	return (*head);
// }

/*TEST IT*/
//ASK!!! WHAT TO DO