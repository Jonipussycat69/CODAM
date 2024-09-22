#ifndef TERM_SNAKE_H
# define TERM_SNAKE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>
# include <limits.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <termios.h>
# include <math.h>
# include <time.h>
# include <pthread.h>
# include <ncurses.h>

# define STARTING_LEN 4
# define STARTING_LIVES 3
# define QUIT_KEY 27

enum	e_error
{
	SUCC = 0,
	FAIL = 1,
	GAME_OVER = 2,
	RUNNING = 3
};

enum	e_directions
{
	UP = 0,
	DOWN,
	LEFT,
	RIGHT
};

typedef struct s_turn
{
	__uint16_t		pos[2];
	uint_fast16_t	len_remain;
	__uint16_t		pre_direction;
	__uint16_t		post_direction;
	struct s_turn	*next;
}	t_turn;

typedef struct s_data
{
	uint_fast16_t	head_pos[2];
	__uint32_t		snake_len;
	__uint16_t		candy_pos[2];
	t_turn			*turns;
	uint_fast16_t	terminal_rows;
	uint_fast16_t	terminal_cols;
	char			last_inp;
	short			level;
	short			score;
	short			lives;
	bool			dead;
	bool			game_started;
	bool			game_paused;
	short			exit_code;
	pthread_mutex_t	lock;
}	t_data;

// gameplay.c

void	candy_pos_generate(t_data *data);
void	*game(void *data);

// loops.c

void	*input_loop(void *arg);
void	*print_loop(void *data);

// list.c

t_turn	*new_turn(const t_turn *data);
void	node_back(t_turn **turn, t_turn *node);
void	free_list(t_turn **turn);
void	turn_copy(t_turn *turn, const t_turn *data);
bool	turn_add_back(t_turn **turn, const t_turn *data);
int		list_len(t_turn *turn);
t_turn	*last_node(t_turn *turn);

// utils.c

__uint16_t	get_terminal_rows(void);
__uint16_t	get_terminal_cols(void);
__uint64_t	get_time_us(void);

#endif