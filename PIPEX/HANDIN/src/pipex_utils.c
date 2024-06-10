/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/07 17:04:30 by jdobos        #+#    #+#                 */
/*   Updated: 2024/06/10 12:49:52 by jdobos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error_exit(int errornum, char *message)
{
	const char	*nill = "\0";

	if (message == NULL)
		message = (char *)nill;
	dup2(STDERR_FILENO, STDOUT_FILENO);
	if (errornum == 127)
		ft_printf("pipex: command not found: %s\n", message);
	else
		ft_printf("pipex: %s: %s\n", strerror(errornum), message);
	exit(errornum);
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

int	open_inputfile(const char *inputfile)
{
	int	fd;

	fd = open(inputfile, O_RDONLY);
	if (fd == -1)
		error_exit(errno, (char *)inputfile);
	return (fd);
}

int	open_outputfile(const char *outputfile)
{
	int	fd;

	fd = open(outputfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		error_exit(errno, (char *)outputfile);
	return (fd);
}
