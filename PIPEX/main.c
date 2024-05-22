#include "pipex.h"

void	open_files(t_pipex *p)
{
	p->fd_in = open(p->file_a, O_RDONLY);
	if (p->fd_in < 0)
		error_exit("Error opening input file");
	p->fd_out = open(p->file_b, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (p->fd_out < 0)
	{
		close(p->fd_in);
		error_exit("Error opening output file");
	}
}

void	create_pipe(t_pipex *p, int *pipe_fd)
{
	if (pipe(pipe_fd) == -1)
	{
		close(p->fd_in);
		close(p->fd_out);
		error_exit("Error creating pipe");
	}
}

void	exec_cmd_a(t_pipex *p, int *pipe_fd)
{
	p->pid_a = fork();
	if (p->pid_a < 0)
	{
		close(p->fd_in);
		close(p->fd_out);
		error_exit("Error forking");
	}
	else if (p->pid_a == 0)
	{
		dup2(p->fd_in, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(p->fd_in);
		close(p->fd_out);
		execlp("sh", "sh", "-c", p->cmd_a, NULL);
		error_exit("Error executing cmd_a");
	}
}

void	exec_cmd_b(t_pipex *p, int *pipe_fd)
{
	p->pid_b = fork();
	if (p->pid_b < 0)
	{
		close(p->fd_in);
		close(p->fd_out);
		error_exit("Error forking");
	}
	else if (p->pid_b == 0)
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		dup2(p->fd_out, STDOUT_FILENO);
		close(pipe_fd[1]);
		close(p->fd_in);
		close(p->fd_out);
		execlp("sh", "sh", "-c", p->cmd_b, NULL);
		error_exit("Error executing cmd_b");
	}
}

int	main(int argc, char *argv[])
{
	t_pipex	p;
	int		pipe_fd[2];

	if (argc != 5)
		error_exit("Usage: ./pipex file1 cmd1 cmd2 file2");
	p.file_a = argv[1];
	p.cmd_a = argv[2];
	p.cmd_b = argv[3];
	p.file_b = argv[4];
	open_files(&p);
	create_pipe(&p, pipe_fd);
	exec_cmd_a(&p, pipe_fd);
	exec_cmd_b(&p, pipe_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(p.fd_in);
	close(p.fd_out);
	waitpid(p.pid_a, NULL, 0);
	waitpid(p.pid_b, NULL, 0);
	return (0);
}



// BULK

// int main(int argc, char *argv[]) {
// 	if (argc != 5) {
// 	    error_exit("Usage: ./pipex file1 cmd1 cmd2 file2");
// 	}

// 	char *file1 = argv[1];
// 	char *cmd1 = argv[2];
// 	char *cmd2 = argv[3];
// 	char *file2 = argv[4];

// 	int p->fd_in = open(file1, O_RDONLY);
// 	if (p->fd_in < 0) {
// 	    error_exit("Error opening input file");
// 	}

// 	int outfile = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);// ?
// 	if (outfile < 0) {
// 	    close(p->fd_in);
// 	    error_exit("Error opening output file");
// 	}

// 	int pipefd[2];
// 	if (pipe(pipefd) == -1) {
// 	    close(p->fd_in);
// 	    close(outfile);
// 	    error_exit("Error creating pipe");
// 	}

// 	pid_t pid1 = fork();
// 	if (pid1 < 0) {
// 	    close(p->fd_in);
// 	    close(outfile);
// 	    error_exit("Error forking");
// 	} else if (pid1 == 0) {
// 	    dup2(p->fd_in, STDIN_FILENO);
// 	    dup2(pipefd[1], STDOUT_FILENO);
// 	    close(pipefd[0]);
// 	    close(p->fd_in);
// 	    close(outfile);
// 	    execlp("sh", "sh", "-c", cmd1, NULL);
// 	    error_exit("Error executing cmd1");
// 	}

// 	pid_t pid2 = fork();
// 	if (pid2 < 0) {
// 	    close(p->fd_in);
// 	    close(outfile);
// 	    error_exit("Error forking");
// 	} else if (pid2 == 0) {
// 	    dup2(pipefd[0], STDIN_FILENO);
// 	    dup2(outfile, STDOUT_FILENO);
// 	    close(pipefd[1]);
// 	    close(p->fd_in);
// 	    close(outfile);
// 	    execlp("sh", "sh", "-c", cmd2, NULL);
// 	    error_exit("Error executing cmd2");
// 	}

// 	close(pipefd[0]);
// 	close(pipefd[1]);
// 	close(p->fd_in);
// 	close(outfile);

// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, NULL, 0);

// 	return 0;
// }
