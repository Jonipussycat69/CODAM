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

	if (head == NULL || *head == NULL)
		return (NULL);
	temp = *head;
	while (temp != NULL)
	{
		temp2 = temp;
		temp = temp->next;
		if (temp2->buf)
			free(temp->buf);
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
	char	*tempstr;

	str = (char *)cal(sizeof(char), BUFFER_SIZE + 1);
	if (!(str))
		return (NULL);
	tempstr = str;
	while (*buffer)
		*(str++) = *(buffer++);
	printf("GNL >> node new str >> %s <<\n", tempstr);
	new_node = (t_list *)malloc(sizeof(t_list));
	if (!(new_node))
	{
		free(tempstr);
		return (NULL);
	}
	new_node->buf = tempstr;
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

	printf("GNL >> Running read loop\n");//CHECK
	bytesread = 1;
	while (bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		printf("GNL >> Running read loop >>\n");//CHECK
		printf("GNL >> Running read loop >> btsr: %zu\n", bytesread);//CHECK
		if (bytesread <= 0)
		{
			if (bytesread < 0)
				return (-1);
			break ;
		}
		buffer[bytesread] = '\0';
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

	i = 0;
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
	size_t		il;
	static char	remainder[BUFFER_SIZE];
	
	line = (char *)cal(((llen(*head) - 1) * BUFFER_SIZE)
	 + lblen + slen(remainder) - 1, 1);
	if (!line)
		return (NULL);
	temp = *head;
	ib = 0;
	il = 0;
	line = remain_cpy(line, remainder);
	printf("GNL >> Running make loop\n");//CHECK
	while (temp != NULL)
	{
		printf("GNL >> Running make loop >>\n");//CHECK
		while ((temp->buf)[ib] && (temp->buf)[ib] != '\n')
			line[il++] = (temp->buf)[ib++];
		ib = 0;
		if (temp->next == NULL)
		{
			remain_cpy(remainder, temp->buf);
			line[il] = '\n';
		}
		printf("GNL >> make line >> %s\n", line);//CHECK
		printf("GNL >> make temp->buf >> %s\n", temp->buf);//CHECK
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
	printf("GNL >> Running read\n");//CHECK
	last_buf_len = read_line(fd, &head);
	if (last_buf_len < 0)
		return (lst_free(&head));
	printf("GNL >> head->buf >> %s\n", head->buf);//CHECK
	printf("GNL >> Running make\n");//CHECK
	line = make_str(&head, last_buf_len);
	printf("line = %s", line);
	printf("line = %s", head->buf);
	lst_free(&head);
	return (line);
}
