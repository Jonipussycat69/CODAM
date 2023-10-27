/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: joni <joni@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/24 19:43:24 by joni          #+#    #+#                 */
/*   Updated: 2023/10/26 14:26:21 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd)
{
	char			*buffer;
	ssize_t			bytesread;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!(buffer))
		return(NULL);
	bytesread = read(fd, buffer, BUFFER_SIZE);
	if (bytesread < 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytesread] = '\0';
	return (buffer);
}

t_list	*list_line(int fd, t_list **head)
{
	static t_list	*lst;

	lst = ft_lstnew(read_line(fd));
	if (!(lst))
	{
		ft_lstclear(head);
		return (NULL);
	}
	ft_lstadd_back(head, lst);
	return (lst);
}

char	*get_next_line(int fd)
{
	t_list			*head;
	t_list			*temp;
	size_t			i;
	char			*out;

	head = NULL;
	list_line(fd, &head);
	out = (char *)malloc(ft_lstsize(head) * BUFFER_SIZE + 1);
	if (!(out))
	{
		ft_lstclear(&head);
		return (NULL);
	}
	temp = head;
	i = 0;
	while (temp != NULL)
	{
		while (temp->buf[i])
		{
			out[i] = temp->buf[i];
			i++;
		}
		i = 0;
		temp = temp->next;
	}
	ft_lstclear(&head);
	// clean_line();
	return (out);
}

int	main(void)
{
	char	*line;
	int	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	if ((line = get_next_line(fd)) != NULL)
	{
		printf("next line: %s\n", line);
		printf("next line: %s\n", line);
	}
	free(line);
	close(fd);
	return (0);
}