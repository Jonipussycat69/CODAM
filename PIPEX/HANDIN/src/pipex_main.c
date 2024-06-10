/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_main.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jdobos <jdobos@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/23 13:58:47 by jdobos        #+#    #+#                 */
/*   Updated: 2024/06/10 15:01:08 by jdobos        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	execute_command(char *cmd, char *path, char **envp)
{
	char	**split_cmd;

	split_cmd = split_command(cmd);
	if (path_find(split_cmd[0], path, envp) == NULL)
		error_exit(127, NULL);
	execve(path, split_cmd, envp);
	free_double_arr(split_cmd);
	error_exit(errno, "execve");
}

static int	first_child(char **arg, char *path, char **envp)
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
			error_exit(errno, "close first child");
		execute_command((char *)cmd, path, envp);
	}
	return (pipe_fds[0]);
}

// output to specific fd instead a new pipe
static pid_t	last_child(int inp_fd, char **arg, char *path, char **envp)
{
	const char	*output_file = arg[4];
	const char	*cmd = arg[3];
	pid_t		pid;

	set_input(inp_fd);
	pid = fork();
	if (pid == 0)
	{
		set_output(open_outputfile(output_file));
		execute_command((char *)cmd, path, envp);
	}
	if (close(STDIN_FILENO) == -1)
		error_exit(errno, "close STDIN");
	if (close(STDOUT_FILENO) == -1)
		error_exit(errno, "close STDOUT");
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
	char	path[4097];

	if (argc < 5 || argc > 5)
		error_exit(EINVAL, NULL);
	path[0] = '\0';
	input_fd = first_child(argv, path, envp);
	pid = last_child(input_fd, argv, path, envp);
	return (safe_waitpid(pid));
}
