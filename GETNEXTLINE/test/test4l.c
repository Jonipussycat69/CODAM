#include "get_next_line.h"

char	*make_list(t_list **head, char *buffer)
{
	char	*str;
	static char	remainder[BUFFER_SIZE];
	
	str = (char *)malloc(my_strlen(buffer) * sizeof(char));
	if (!str)
		return (NULL);
	
	return (remainder);
}

char	*read_line(int fd, t_list **head)
{
	char	buffer[BUFFER_SIZE + 1];
	t_list	*new_node;
	ssize_t	bytesread;
	int		newline;
	char	*remainder;
	
	newline = 0;
	while (bytesread > 0 && newline == 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread <= 0)
		{
			if (bytesread < 0)
				return (NULL);
			break ;
		}
		
	}
	return (remainder);
}

char	*make_str(t_list **head)
{
	char	*line;
	t_list	*temp;
	size_t	istr;
	size_t	ilst;
	
	line = (char *)malloc(my_lstsize(head) * BUFFER_SIZE);
	if (!line)
		return (NULL);
	temp = *head;
	istr = 0;
	while (temp != NULL)
	{
		
	}
	return (line);
}

char	*get_next_line(int fd)
{
	t_list	*head;
	char	*remainder;
	
	head = NULL;
	remainder = read_line(fd, head);
	if (remainder == NULL);
		return (freeal(head));
	
	return (make_str(head));
}