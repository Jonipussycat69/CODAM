/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:32:47 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/12 18:32:57 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;
	int	i;

	if (!(r = (char *) malloc(len)))
		return (NULL);
	i = 0;
	while (len-- && s[start])
		r[i++] = s[start++];
	return (r);
}

int	main(void)
{
	char s[] = "hello there";
	printf("%s\n", ft_substr(s, 9, 3));
	return (0);
}