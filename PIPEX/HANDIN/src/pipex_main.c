/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_main.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/23 13:58:47 by jdobos        #+#    #+#                 */
/*   Updated: 2024/06/14 14:17:41 by jdobos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	execute_command(char *cmd, char **envp)
{
	char	**split_cmd;
	char	*path;

	split_cmd = ft_split(cmd, ' ');
	if (!split_cmd)
		error_exit(errno, cmd);
	path = path_find(split_cmd[0], envp);
	if (path == NULL)
	{
		free_double_arr(split_cmd);
		error_exit(errno, cmd);
	}
	execve(path, split_cmd, envp);
	free(path);
	free_double_arr(split_cmd);
	error_exit(errno, "execve");
}

static int	first_child(char **arg, char **envp)
{
	const char	*input_file = arg[1];
	const char	*cmd = arg[2];
	pid_t		pid;
	int			pipe_fds[2];

	if (pipe(pipe_fds) == -1)
		error_exit(errno, (char *)cmd);
	set_output(pipe_fds[1]);
	pid = fork();
	if (pid == 0)
	{
		set_input(open_inputfile(input_file));
		if (close(pipe_fds[0]) == -1)
			error_exit(errno, "first child");
		execute_command((char *)cmd, envp);
	}
	return (pipe_fds[0]);
}

static pid_t	last_child(int inp_fd, char **arg, char **envp)
{
	const char	*output_file = arg[4];
	const char	*cmd = arg[3];
	pid_t		pid;

	set_input(inp_fd);
	pid = fork();
	if (pid == 0)
	{
		set_output(open_outputfile(output_file));
		execute_command((char *)cmd, envp);
	}
	if (close(STDIN_FILENO) == -1)
		error_exit(errno, "STDIN");
	if (close(STDOUT_FILENO) == -1)
		error_exit(errno, "STDOUT");
	return (pid);
}

static int	safe_waitpid(int pid)
{
	int	status;

	if (waitpid(pid, &status, 0) == -1)
		error_exit(errno, NULL);
	while (wait(NULL) != -1)
		;
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	return (errno);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		input_fd;

	if (argc != 5)
		error_exit(EINVAL, NULL);
	input_fd = first_child(argv, envp);
	pid = last_child(input_fd, argv, envp);
	return (safe_waitpid(pid));
}
