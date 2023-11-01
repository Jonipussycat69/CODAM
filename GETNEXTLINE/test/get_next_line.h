/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:44:21 by joni              #+#    #+#             */
/*   Updated: 2023/11/01 15:35:24 by jdobos           ###   ########.fr       */
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
# define BUFFER_SIZE 5

typedef struct s_list
{
	char			*buf;
	int				position;
	struct s_list	*next;
}	t_list;

typedef struct fd_list
{
	char			**head;
	int				fd;
	struct ft_list	*next;
}	fd_l;

typedef struct variable_list
{
	char	*line;
	char	*buf;
	int		pos;
	fd_l	**head_fd;
	t_list	**head_l;
}	var;

t_list	*ft_lstnew(char *buf);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
char	*ft_strchr(const char *str, int c);
int		ft_lstsize(t_list *lst);

#endif