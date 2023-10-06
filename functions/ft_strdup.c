/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 18:04:19 by jdobos        #+#    #+#                 */
/*   Updated: 2023/10/06 12:22:00 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	char	*temp;
	
	ptr = (char *) malloc (ft_strlen(s) * sizeof(char));
	temp = ptr;
	while (*s)
	{
		*ptr = *s;
		s++;
		ptr++;
	}
	return (temp);
}