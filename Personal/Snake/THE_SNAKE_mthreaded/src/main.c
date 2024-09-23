#include "../term_snake.h"

int	main(void)
{
	t_data	data;

	enableRawMode();
	init_data(&data);
	if (data.rows <= 5 || data.cols <= 5)
		return (printf("Terminal too small\n"), clean_up(&data), FAIL);
	if (pthread_create(&data.input_thread, NULL, input_loop, &data))
		return (perror("pthread_create"), clean_up(&data), FAIL);
	pthread_detach(data.input_thread);
	game_loop(&data);
	exit_clean(&data, false, NULL);
	return (SUCC);
}
