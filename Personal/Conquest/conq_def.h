#ifndef CONQ_DEF_H
# define CONQ_DEF_H
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <termios.h>
# include <math.h>
# include <time.h>
# include "libft/libft.h"
# include "MLX42/MLX42.h"

// DEFINES

// STRUCTS
typedef unsigned char	t_uchar;

typedef struct s_pixel
{
	int				x;
	int				y;
	uint_fast32_t	color;
}	t_pix;

typedef struct s_image
{
	mlx_image_t	*img_map;
	mlx_image_t	*img_ui_stats;
	mlx_image_t	*img_ui_controlls;
	mlx_image_t	*img_ui_menu;
	mlx_image_t	*img_ui_button;
	mlx_image_t	**img_text;
}	t_img;

typedef struct s_player
{
	uint16_t		id;// >= 1, basically an index
	char			*name;
	bool			alive;
	bool			ai;
	t_territory		**territories_current;
	uint_fast32_t	color;
	uint_fast64_t	troops_total;
	uint_fast16_t	territories_owned;
	uint_fast32_t	wins;
	uint_fast32_t	losses;
	struct s_player	*next;
}	t_player;

typedef struct s_territory
{
	uint32_t			id;
	uint16_t			continent_id;
	t_player			*owner;// NULL = not occupied
	char				*name;// ?
	uint_fast16_t		troops;
	uint16_t			value;// amount of troops it gives
	struct s_territory	**adjacent;
	uint16_t			adjacent_count;
}	t_territory;

typedef struct s_controlls
{
	// idk
}	t_controlls;

typedef struct s_history
{
	// idk
}	t_history;

typedef struct s_mainvar
{
	mlx_t		*mlx;
	t_img		*img;
	t_controlls	*ctrls;
	t_player	*players;
	t_territory	**territories;
	uint16_t	territory_count;
	uint16_t	round;
	short		game_stage;
	FILE		*error_file;
}	t_main;

#endif