/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:35 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/23 12:42:02 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

const char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	if (c > 127)
		return (str);
	while (i > 0 && str[i] != c)
	{
		i--;
	}
	if (str[i] == c)
		return (&str[i]);
	return (NULL);
}

// int	main(void)
// {
// 	char	s[] = "String String";
// 	char	c = 'i';
// 	printf("mine: %s\n", ft_strrchr(s, c));
// 	printf("original: %s\n", strrchr(s, c));
// 	return (0);
// }