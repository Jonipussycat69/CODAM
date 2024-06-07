/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/06 13:32:11 by jdobos        #+#    #+#                 */
/*   Updated: 2024/06/07 15:26:26 by jdobos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ps_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ps_strjoin(char *add, char *line, size_t i, size_t j)
{
	const size_t	l_len = ps_strlen(line);
	const size_t	a_len = ps_strlen(add);
	char			*new_line;
	char			*temp_line;

	if (a_len == 0)
		return (line);
	temp_line = line;
	new_line = (char *)malloc(l_len + a_len + 1);
	if (!new_line)
		return (free(line), NULL);
	while (i < l_len)
		new_line[i++] = *(temp_line++);
	while (j < a_len)
		new_line[i++] = add[j++];
	new_line[i] = '\0';
	free(line);
	return (new_line);
}

void	wr_a(char *action)
{
	write(STDOUT_FILENO, action, ps_strlen(action));
	write(STDOUT_FILENO, "\n", 1);
	return ;
}

void	wr_err(char *message)
{
	write(STDERR_FILENO, message, ps_strlen(message));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

int	list_len(t_list **head)
{
	t_list	*tmp;
	int		i;

	if (!*head)
		return (0);
	i = 0;
	tmp = *head;
	while (tmp != NULL && ++i)
		tmp = tmp->next;
	return (i);
}
