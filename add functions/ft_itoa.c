/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:10:56 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/12 18:32:03 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static size_t	counter(int n)
{
	size_t	i;

	i = 2;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	mystrrev(char *str)
{
	char	temp;
	int	b;
	int	e;

	b = 0;
	e = ft_strlen(str) - 1;
	if (str[b] == '-')
		b++;
	while (b < e)
	{
		temp = str[b];
		str[b] = str[e];
		str[e] = temp;
		b++;
		e--;
	}
	return ;
}

char	*ft_itoa(int n)
{
	char	*ascii;
	size_t	i;

	i = 0;
	if (!(ascii = (char *) malloc(counter(n) * sizeof(char))))
		return (NULL);
	if (n < 0)
	{
		ascii[i++] = '-';
		n = n * -1;
	}
	while (n > 10)
	{
		ascii[i++] = n % 10 + 48;
		n = n / 10;
	}
	ascii[i++] = n + 48;
	ascii[i] = '\0';
	mystrrev(ascii);
	return (ascii);
}

/* int	main(void)
{
	printf("out: %s\n", ft_itoa(76243123));
	return (0);
} */