/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:04:30 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/12 18:34:31 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0' && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}

int	main(void)
{
	char s1[] = "Hello World";
	char s2[] = "Hello world";
	printf("mine: %d\n", ft_strncmp(s1, s2, -9));
	printf("sys: %d\n", strncmp(s1, s2, -9));
	return 0;
}