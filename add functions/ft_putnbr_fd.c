/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 18:24:12 by jdobos        #+#    #+#                 */
/*   Updated: 2023/10/12 11:27:41 by joni          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	writemin(int n, int fd)
{
	unsigned int	t;
	write(fd, "-", 1);
	t = n * -1;
	write(fd, &t, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	if (n == -2147483648)
		writemin(n, fd);
	if (n < 0)
		n = n * -1;
	if (n > 10)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + 48;
	write(fd, &c, 1);
}

int	main(void)
{
	ft_putnbr_fd(-2147483648, 1);
	return (0);
}