/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: joni <joni@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/24 19:44:21 by joni          #+#    #+#                 */
/*   Updated: 2023/10/25 13:52:26 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <string.h>
# include <fcntl.h>
# define BUFFER_SIZE 10

typedef struct s_list
{
	char			*buf;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *buf);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	*ft_calloc(size_t nmemb, size_t size);

#endif