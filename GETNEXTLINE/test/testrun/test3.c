#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t	br;
	size_t	i;
	size_t	j;
	t_list	*head;
	t_list	*temp;
	char	*out;
	char	*buffer;
	
	head = NULL;
	br = 1;
	temp = head;
	while (br > 0)
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!(buffer))
		{
			ft_lstclear(&head);
			return (NULL);
		}
		br = read(fd, buffer, BUFFER_SIZE);
		if (br <= 0)
		{
			if (br < 0)
			{
				ft_lstclear(&head);
				return (NULL);
			}
			break ;
		}
		buffer[br] = '\0';
		ft_lstadd_back(&head, ft_lstnew(buffer));
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	temp = head;
	out = (char *)malloc((ft_lstsize(head) * BUFFER_SIZE) + 1);
	if (!(out))
	{
		ft_lstclear(&head);
		return (NULL);
	}
	j = 0;
	while (temp != NULL)
	{
		i = 0;
		while (temp->buf[i])
		{
			out[j] = temp->buf[i];
			j++;
			i++;
		}
		temp = temp->next;
	}
	ft_lstclear(&head);
	out[j] = '\0';
	return (out);
}

int	main(void)
{
	char	*line;
	int	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	close(fd);
	return (0);
}