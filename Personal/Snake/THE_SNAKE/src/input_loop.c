#include "../term_snake.h"

void	check_resize(t_data *data)
{
	struct winsize	w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	if (data->rows != w.ws_row || data->cols != w.ws_col)
		data->resized = true;
	data->rows = w.ws_row;
	data->cols = w.ws_col;
}

void	*input_loop(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	wait_for_start(data);
	while (1)
	{
		pthread_mutex_lock(&data->data_lock);
		check_resize(data);
		pthread_mutex_unlock(&data->data_lock);
		pthread_mutex_lock(&data->input_lock);
		data->input = getch();
		pthread_mutex_unlock(&data->input_lock);
		while (data->tick)
			;
		data->tick = false;
	}
	return (NULL);
}
