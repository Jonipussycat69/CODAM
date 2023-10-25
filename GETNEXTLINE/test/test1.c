#include "get_next_line.h"

size_t	nl(char	*buff)
{
	size_t	i;

	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

void	clean_line(t_list **head)
{
	//RESUME HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

char	*write_line(t_list *head)
{
	char	*line;
	size_t	i;
	size_t	temp;
	
	temp = ft_lstsize(head) * BUFFER_SIZE;
	line = (char *)malloc(temp + 1);
	if (!(line))
		return (NULL);
	while (head->next != NULL)
	{
		i = 0;
		while (head->buf[i])
		{
			line[i] = head->buf[i];
			i++;
		}
		head = head->next;
	}
	line[temp] = '\0';
	return (line);
}

t_list	*read_line(int fd, t_list **head)
{
	char	*buffer;
	t_list	*temp;
	ssize_t	bytesr;

	while (bytesr != 0)
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		if (!(buffer))
		{
			cleaner(head);
			return (NULL);
		}
		bytesr = read(fd, buffer, BUFFER_SIZE);
		if (bytesr < 0)
			return (NULL);
		buffer[bytesr] = '\0';
		temp = ft_lstnew(buffer);
		ft_lstadd_back(head, temp);
		if (nl(temp->buf) != 0)
			break;
		printf("buf: %s\n", buffer);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	char			*out;
	static t_list	*head;
	t_list			*temp;

	head = NULL;
	temp = read_line(fd, &head);
	write_line(head);
	clean_line(&head);
	head = temp;
	return (out);
}

int	main(void)
{
	char	*line;
	int	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	get_next_line(fd);
	// if ((line = get_next_line(fd)) != NULL)
	// {
	// 	printf("next line: %s\n", line);
	// 	printf("next line: %s\n", line);
	// }
	// free(line);
	close(fd);
	return (0);
}