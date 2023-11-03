#include "get_next_line.h"

void	*cal(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	t;

	t = nmemb * size;
	if (nmemb != 0 && size != 0 && t / nmemb != size)
		return (NULL);
	ptr = (void *)malloc(t);
	if (ptr)
	{
		while (t > 0)
		{
			*(unsigned char *)ptr = '\0';
			ptr++;
			t--;
		}
	}
	return (ptr);
}

void	*lst_free(t_list **head)
{
	t_list	*temp;
	t_list	*temp2;

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

size_t	llen(t_list *lst)
{
	size_t	c;

	c = 0;
	while (lst != NULL)
	{
		c++;
		lst = lst->next;
	}
	return (c);
}

size_t	slen(char *str)
{
	size_t	c;

	c = 0;
	while (str[c] && str[c] != '\n')
		c++;
	if (str[c] == '\n')
		return (c + 1);
	if (c == BUFFER_SIZE && str[c] == '\0')
		return (BUFFER_SIZE + 1);
	return (c + 1);
}

t_list	*node_new(char *buffer)
{
	t_list	*new_node;
	char	*str;

	str = (char *)cal(sizeof(char), BUFFER_SIZE + 1);
	if (!(str))
		return (NULL);
	while (*buffer)
		*(str++) = *(buffer++);
	new_node = (t_list *)malloc(sizeof(t_list));
	if (!(new_node))
	{
		free(str);
		return (NULL);
	}
	new_node->buf = str;
	new_node->next = NULL;
	return (new_node);
}

int	node_add_back(t_list **head, t_list *new)
{
	t_list	*temp;

	if (new == NULL)
		return (0);
	if (*head == NULL)
		*head = new;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	return (1);
}

int	read_line(int fd, t_list **head)
{
	char	buffer[BUFFER_SIZE + 1];
	t_list	*new_node;
	ssize_t	bytesread;
	int		newline;

	newline = 0;
	while (bytesread > 0 && newline == 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread <= 0)
		{
			if (bytesread < 0)
				return (-1);
			break ;
		}
		buffer[BUFFER_SIZE] = '\0';
		if (node_add_back(head, node_new(buffer)) == 0)
			return (-1);
		if (slen(buffer) != BUFFER_SIZE + 1)
			break ;
	}
	return (slen(buffer));
}

char	*remain_cpy(char *dest, char *src)
{
	size_t	i;

	while (dest[i])
		dest[i++] = '\0';
	if (slen(src) < BUFFER_SIZE + 1)
		src += slen(src) - 1;
	while (*src && --i)
		*(dest++) = *(src++);
	return (dest);
}

char	*make_str(t_list **head, int lblen)
{
	char		*line;
	t_list		*temp;
	size_t		ib;
	static char	remainder[BUFFER_SIZE];
	
	line = (char *)cal(((llen(*head) - 1) * BUFFER_SIZE)
	 + lblen + slen(remainder) - 1, 1);
	if (!line)
		return (NULL);
	temp = *head;
	ib = 0;
	line = remain_cpy(line, remainder);
	while (temp != NULL)
	{
		while ((temp->buf)[ib] && (temp->buf)[ib] != '\n')
			*(line++) = (temp->buf)[ib++];
		ib = 0;
		if (temp->next == NULL)
			remain_cpy(temp->buf, remainder);
		temp = temp->next;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	t_list	*head;
	int		last_buf_len;
	char	*line;
	
	head = NULL;
	last_buf_len = read_line(fd, &head);
	if (last_buf_len < 0)
		return (lst_free(&head));
	line = make_str(&head, last_buf_len);
	printf("line = %s", line);
	printf("line = %s", head->buf);
	lst_free(&head);
	return (line);
}
