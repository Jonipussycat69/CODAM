/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:03:14 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/31 14:52:21 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*clean_all(t_list **head, char *buffer)
{
	t_list	*temp;
	t_list	*temp2;

	if (buffer)
		free(buffer);
	if (head == NULL)
		return (NULL);
	temp = *head;
	while (temp != NULL)
	{
		if (temp->buf)
			free(temp->buf);
		temp2 = temp;
		temp = temp->next;
		free(temp2);
	}
	*head = NULL;
	return (NULL);
}

t_list	*ft_read(t_list **head, int fd)
{
	t_list	*newnode;
	ssize_t	readbytes;
	char	*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!(buffer))
		return (clean_all(head, buffer));
	buffer[BUFFER_SIZE] = '\0';
	while (readbytes > 0)
	{
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes <= 0)
		{
			if (readbytes < 0)
				return (clean_all(head, buffer));
			break ;
		}
		ft_lstadd_back(head, ft_lstnew(buffer));
	}
	return (newnode);
}

static void	ft_write(t_list **head)
{

}

char	*get_next_line(int fd)
{
	t_list	*head;
	t_list	*temp;

	head = NULL;
	temp = ft_read(&head, fd);
	if (temp = NULL)
		return (NULL);
	
}