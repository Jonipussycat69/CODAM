/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/23 13:58:47 by jdobos        #+#    #+#                 */
/*   Updated: 2024/06/07 16:59:42 by jdobos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	open_files(t_pipex *p)
{
	p->fd_in = open(p->file_a, O_RDONLY);
	if (p->fd_in < 0)
		error_exit(p, "Error opening input file", EXIT_FAILURE);
	p->fd_out = open(p->file_b, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (p->fd_out < 0)
	{
		close(p->fd_in);
		error_exit(p, "Error opening output file", EXIT_FAILURE);
	}
}

void	create_pipe(t_pipex *p, int *pipe_fd)
{
	if (pipe(pipe_fd) == -1)
	{
		close(p->fd_in);
		close(p->fd_out);
		error_exit(p, "Error creating pipe", EXIT_FAILURE);
	}
}

void	exec_cmd_a(t_pipex *p, int *pipe_fd, char **envp)
{
	p->pid_a = fork();
	if (p->pid_a < 0)
	{
		close(p->fd_in);
		close(p->fd_out);
		error_exit(p, "Error forking", EXIT_FAILURE);
	}
	else if (p->pid_a == 0)
	{
		dup2(p->fd_in, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(p->fd_in);
		close(p->fd_out);
		p->path_a = path_find(p->cmd_a[0], envp);
		if (!p->path_a)
			error_exit(p, "", EXIT_FAILURE);
		execve(p->path_a, p->cmd_a, envp);
		error_exit(p, "Error executing cmd_a", EXIT_FAILURE);
	}
}

void	exec_cmd_b(t_pipex *p, int *pipe_fd, char **envp)
{
	p->pid_b = fork();
	if (p->pid_b < 0)
	{
		close(p->fd_in);
		close(p->fd_out);
		error_exit(p, "Error forking", EXIT_FAILURE);
	}
	else if (p->pid_b == 0)
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		dup2(p->fd_out, STDOUT_FILENO);
		close(pipe_fd[1]);
		close(p->fd_in);
		close(p->fd_out);
		p->path_b = path_find(p->cmd_b[0], envp);
		if (!p->path_b)
			error_exit(p, "", EXIT_FAILURE);
		execve(p->path_b, p->cmd_b, envp);
		error_exit(p, "Error executing cmd_b", EXIT_FAILURE);
	}
}

// find PATH=etc. in envp with strcmp and then split with ":" delimiter, and find the working path with access!
// Also split the command from its flags ! Look at execve parameters !
// ! if path is not found skip execve and do the correct error handling !
int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	p;
	int		pipe_fd[2];

	init_null(&p);
	if (argc != 5)
		error_exit(&p, "Usage: ./pipex file1 cmd1 cmd2 file2", EXIT_FAILURE);
	p.file_a = argv[1];
	p.cmd_a = ft_split(argv[2], ' ');
	p.cmd_b = ft_split(argv[3], ' ');
	p.file_b = argv[4];
	open_files(&p);
	create_pipe(&p, pipe_fd);
	exec_cmd_a(&p, pipe_fd, envp);
	exec_cmd_b(&p, pipe_fd, envp);
	free_struct(&p);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(p.fd_in);
	close(p.fd_out);
	wait_secure(&p, p.pid_a);
	return (0);
}
