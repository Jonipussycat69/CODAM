/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:17 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/23 12:18:18 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (c > 127)
		return (str);
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	if (str[i] == '\0' && c == '\0')
		return (str + i);
	return (NULL);
}

// int	main(void)
// {
// 	char	s[] = "String";
// 	char	c = 'i';
// 	printf("mine: %s\n", ft_strchr(s, c));
// 	printf("original: %s\n", strchr(s, c));
// 	return (0);
// }