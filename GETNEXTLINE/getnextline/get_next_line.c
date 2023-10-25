/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: joni <joni@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/24 19:43:24 by joni          #+#    #+#                 */
/*   Updated: 2023/10/25 14:14:08 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*read_line(int fd, t_list **head)
{
	static t_list	*lst;
	char			*buffer;
	ssize_t			bytesread;

	buffer = (char *)ft_calloc(sizeof(BUFFER_SIZE), 1);
	if (!(buffer))
	{
		ft_lstclear(head);
		return(NULL);
	}
	lst = ft_lstnew(buffer);
	if (!(lst))
	{
		free(buffer);
		ft_lstclear(head);
		return (NULL);
	}
	bytesread = read(fd, lst->buf, BUFFER_SIZE);
	if (bytesread < 0)
	{
		free(buffer);
		ft_lstclear(head);
		return (NULL);
	}
	return (lst);
}

char	*get_next_line(int fd)
{
	t_list			*head;

	head = NULL;
	read_line(fd, head);
	clean_line();
	
}

int	main(void)
{
	char	*line;
	int	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("next line: %s\n", line);
		free(line);
	}
	return (0);
}