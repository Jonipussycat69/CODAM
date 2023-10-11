/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdobos <jdobos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:24:12 by jdobos            #+#    #+#             */
/*   Updated: 2023/10/11 18:37:27 by jdobos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	if (n < 0)
		n = n * -1;
	if (n > 10)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + 48;
	write(fd, &c, 1);
}

int	main(void)
{
	ft_putnbr_fd(1234, 1);
	return (0);
}