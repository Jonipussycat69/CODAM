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
# include <sys/time.h>
# include <pthread.h>
# include <ncurses.h>
# include <termios.h>
# include <poll.h>

# define STARTING_LEN 4
# define STARTING_LIVES 3
# define INP_BUFFER_SIZE 128
# define TICK_TIME_US 100000
# define POLL_TIME_MS 10

# define C_RESET "\033[0m"
# define C_BOLD "\033[1m"
# define C_GREEN "\033[32m"
# define C_RED "\033[31m"

enum	e_error
{
	SUCC = 0,
	FAIL = 1,
	RUNNING = 2
};

enum	e_input
{
	NON = 0,
	UP = 1,
	LEFT = 2,
	DOWN = 3,
	RIGHT = 4,
	PAUSE = 5,
	QUIT = 6
};

typedef struct s_body
{
	uint_fast16_t		pos[2];
	bool				head;
	struct s_body		*next;
}	t_body;

typedef struct s_data
{
	__uint32_t		snake_len;
	__uint16_t		candy_pos[2];
	__uint16_t		new_body_pos[2];
	t_body			*snake;
	char			*print_buffer;
	uint_fast16_t	rows;
	uint_fast16_t	cols;
	uint_fast16_t	last_direction;
	char			input;
	short			level;
	short			score;
	short			lives;
	bool			game_over;
	pthread_mutex_t	input_lock;
	pthread_t		input_thread;
	uint_fast32_t	tick_time_us;
}	t_data;

// game_loop.c

void	game_loop(t_data *data);

// input_loop.c

void	*input_loop(void *arg);

// game_print.c

void	clear_screen(void);
void	print_buffered_image(t_data *data, char *buffer);
void	print_to_terminal(t_data *data, char *buffer);
void	game_over_message(t_data *data);
void	pause_screen(t_data *data);

// termios.c

void	disableRawMode(void);
void	enableRawMode(void);

// loop_utils.c

void	candy_pos_generate(t_data *data);
void	check_candy(t_data *data);
char	get_pos_char(t_data *data, __uint16_t x, __uint16_t y);
char	*malloc_buffer(t_data *data);

// list.c

t_body	*new_body(const t_body *data);
void	node_back(t_body **body, t_body *node);
void	free_list(t_body **body);
bool	body_add_back(t_body **body, const t_body *data);
int		body_len(t_body *body);
t_body	*last_node(t_body *body);

// init.c

void	init_data(t_data *data);

// game_utils.c

void	create_snake(t_data *data);
void	snake_pos_reset(t_data *data);

// utils.c

__uint16_t		get_terminal_rows(void);
__uint16_t		get_terminal_cols(void);
__uint64_t		get_time_us(void);
uint_fast64_t	delta_time(__uint64_t prev_time_ms);
void			clean_up(t_data *data);
void			exit_clean(t_data *data, bool error, char *message);
void			wait_for_unpause(t_data *data);
uint_fast64_t	get_random(uint_fast64_t seed, uint_fast64_t max);

#endif