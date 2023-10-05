/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:35 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/05 19:06:18 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

const char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	while (i > 0 && str[i] != c)
	{
		i--;
	}
	if (str[i] == c)
		return (&str[i]);
	return (NULL);
}

int	main(void)
{
	char	str[] = "Hello World";
	printf("mibne: %s", ft_strrchr(str, 'o'));
	return 0;
}