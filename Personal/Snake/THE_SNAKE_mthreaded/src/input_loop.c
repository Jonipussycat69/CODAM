#include "../term_snake.h"

void	arrow_key(t_data *data)
{
	char	seq[2];

	if (read(STDIN_FILENO, &seq[0], 1) == 0)
		return ;
	if (read(STDIN_FILENO, &seq[1], 1) == 0)
		return ;
	if (seq[0] == '[')
	{
		pthread_mutex_lock(&data->input_lock);
		switch (seq[1])
		{
			case 'A': data->input = UP; break ;
			case 'B': data->input = DOWN; break ;
			case 'C': data->input = RIGHT; break ;
			case 'D': data->input = LEFT; break ;
			default: data->input = NON; break ;
		}
		pthread_mutex_unlock(&data->input_lock);
	}
}

void	cntr_key(t_data *data, char input)
{
	pthread_mutex_lock(&data->input_lock);
	switch (input)
	{
		// case 'p': data->input = PAUSE; break ;
		case 'p': data->input = PAUSE; break ;
		case 'q': data->input = QUIT; exit(EXIT_SUCCESS);
		case 'w': data->input = UP; break ;
		case 's': data->input = DOWN; break ;
		case 'd': data->input = RIGHT; break ;
		case 'a': data->input = LEFT; break ;
		default: data->input = NON; break ;
	}
	pthread_mutex_unlock(&data->input_lock);
}

void	*input_loop(void *arg)
{
	t_data			*data;
	char			input;
	struct pollfd	fds[1];
	int				ret;

	fds[0].fd = STDIN_FILENO;
	fds[0].events = POLLIN;
	data = (t_data *)arg;
	while (1)
	{
		ret = poll(fds, 1, 10);
		if (ret > 0 && (fds[0].revents & POLLIN))
		{
			read(STDIN_FILENO, &input, 1);
			if (input == '\x1b')
				arrow_key(data);
			else
				cntr_key(data, input);
		}
		if (data->game_over == true)
			break ;
	}
	return (NULL);
}
