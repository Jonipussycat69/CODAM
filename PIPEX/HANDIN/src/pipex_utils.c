/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/07 17:04:30 by jdobos        #+#    #+#                 */
/*   Updated: 2024/06/07 18:23:17 by jdobos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error_exit(int no, char *param)
{
	const char	*nill = "\0";

	if (param == NULL)
		param = (char *)nill;
	dup2(STDERR_FILENO, STDOUT_FILENO);
	if (no == 127)
		ft_printf("pipex: command not found: %s\n", param);
	else
		ft_printf("pipex: %s: %s\n", strerror(no), param);
	exit(no);
}

void	set_input(int input_fd)
{
	if (dup2(input_fd, STDIN_FILENO) == -1)
		error_exit(errno, NULL);
	if (close(input_fd) == -1)
		error_exit(errno, NULL);
}

void	set_output(int output_fd)
{
	if (dup2(output_fd, STDOUT_FILENO) == -1)
		error_exit(errno, NULL);
	if (close(output_fd) == -1)
		error_exit(errno, NULL);
}

int	open_infile(const char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd == -1)
		error_exit(errno, (char *)infile);
	return (fd);
}

int	open_outfile(const char *outfile)
{
	int	fd;

	fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		error_exit(errno, (char *)outfile);
	return (fd);
}
