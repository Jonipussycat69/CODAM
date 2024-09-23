#include "../term_snake.h"

void	add_body(t_data *data)
{
	t_body	new_b;

	new_b.pos[0] = data->new_body_pos[0];
	new_b.pos[1] = data->new_body_pos[1];
	new_b.head = false;
	new_b.next = NULL;
	body_add_back(&data->snake, &new_b);
}

void	check_candy(t_data *data)
{
	if (data->candy_pos[0] == data->snake->pos[0] 
		&& data->candy_pos[1] == data->snake->pos[1])
	{
		data->score++;
		data->snake_len++;
		add_body(data);
		candy_pos_generate(data);
	}
}

void	check_collision(t_data *data)
{
	__uint16_t	head_pos[2];
	t_body		*tmp;

	tmp = data->snake;
	head_pos[0] = tmp->pos[0];
	head_pos[1] = tmp->pos[1];
	tmp = tmp->next;
	while (tmp != NULL)
	{
		if (tmp->pos[0] == head_pos[0] && tmp->pos[1] == head_pos[1])
		{
			if (data->lives > 0)
				return (data->lives--, snake_pos_reset(data));
			else
				exit_clean(data, false, NULL);
		}
		tmp = tmp->next;
	}
}

void	move_snake(t_data *data)
{
	t_body			*s;
	uint_fast16_t	new_pos[2];
	uint_fast16_t	prev_pos[2];

	s = data->snake;
	new_pos[0] = s->pos[0];
	new_pos[1] = s->pos[1];
	switch (data->last_direction)
	{
		case UP: s->pos[1] = (int)(s->pos[1]) - 1 < 0 ? data->rows - 1 : s->pos[1] - 1; break ;
		case DOWN: s->pos[1] = (s->pos[1] + 1) % data->rows; break ;
		case LEFT: s->pos[0] = (int)(s->pos[0]) - 1 < 0 ? data->cols - 1 : s->pos[0] - 1; break ;
		case RIGHT: s->pos[0] = (s->pos[0] + 1) % data->cols; break ;
		default: break ;
	}
	s = s->next;
	while (s != NULL)
	{
		prev_pos[0] = s->pos[0];
		prev_pos[1] = s->pos[1];
		s->pos[0] = new_pos[0];
		s->pos[1] = new_pos[1];
		new_pos[0] = prev_pos[0];
		new_pos[1] = prev_pos[1];
		s = s->next;
	}
}

void	input_to_move(t_data *data)
{
	char	input;

	pthread_mutex_lock(&data->input_lock);
	input = data->input;
	pthread_mutex_unlock(&data->input_lock);
	switch (input + (((data->last_direction + input + 1) % 2) * 10))
	{
		case UP: data->last_direction = UP; break ;
		case DOWN: data->last_direction = DOWN; break ;
		case LEFT: data->last_direction = LEFT; break ;
		case RIGHT: data->last_direction = RIGHT; break ;
		default: switch(input)
		{
			case PAUSE: wait_for_unpause(data); break ;
			case QUIT: exit_clean(data, false, NULL);
			default: break ;
		}
	}
	move_snake(data);
}

void	update_game(t_data *data, char *buffer)
{
	input_to_move(data);
	check_candy(data);
	check_collision(data);
	image_to_buffer(data, buffer);
}

void	print_to_terminal(t_data *data, char *buffer, __uint16_t len)
{
	clear_screen();
	if (data->cols > 50)
	printf("TERM~SNAKE length: %d lives: %d width: %hu height: %hu\n", data->snake_len, data->lives, data->cols, data->rows);
	fflush(stdout);
	write(STDOUT_FILENO, buffer, len);
}

void	game_loop(t_data *data)
{
	__uint16_t	len;
	__uint64_t	prev_time_us;

	create_snake(data);
	candy_pos_generate(data);
	data->print_buffer = malloc_buffer(data);
	len = strlen(data->print_buffer);
	wait_for_unpause(data);
	prev_time_us = get_time_us();
	while (1)
	{
		update_game(data, data->print_buffer);
		print_to_terminal(data, data->print_buffer, len);
		while (delta_time(prev_time_us) < TICK_TIME_US)
			;
		prev_time_us = get_time_us();
	}
}
