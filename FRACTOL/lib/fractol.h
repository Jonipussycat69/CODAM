#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <math.h>
# include "../libft/libft.h"
# include "MLX42/MLX42.h"

# define ERR_MESSAGE "ERROR"// change this!

# define WIDTH_A 900
# define HEIGHT_A 600
# define WIDTH_B 600
# define HEIGHT_B 400
# define WIDTH_C 900
# define HEIGHT_C 900

// starting grid position
# define X_MAX 2.0
# define X_MIN -2.0
# define Y_MAX -2.0
# define Y_MIN 2.0

// SPLIT MODE

# define S_WIDTH 1600
# define S_HEIGHT 800

// mandelbrot
# define M_WIDTH 800
# define M_HEIGHT 800

// julia
# define J_WIDTH 800
# define J_HEIGHT 800

# define X_MAX_J 2.0
# define X_MIN_J -2.0
# define Y_MAX_J -2.0
# define Y_MIN_J 2.0

// colours
# define BLACK	0x000000FF
# define WHITE	0xFFFFFFFF
# define SHORE	0xFFDD88FF
# define LAND	0x337711FF
# define WATER	0x3399FFFF
# define YELLOW	0xFFFFAAAA
# define CYAN	0x00FFFF88
# define MAGENT	0xFF00FFFF
# define GRAY	0x808080FF
# define ORANGE	0xFC9A08FF
# define RED	0xFC0845FF
# define PINK	0xFC08C3BB

# define C_WHITE     0xFFFFFFFF
# define C_BLACK     0x000000FF
# define C_RED       0xFF0000FF
# define C_GREEN     0x00FF00FF
# define C_BLUE      0x0000FFFF
# define C_YELLOW    0xFFFF00FF
# define C_CYAN      0x00FFFFFF
# define C_MAGENTA   0xFF00FFFF
# define C_ORANGE    0xFFA500FF
# define C_PURPLE    0x800080FF
# define C_PINK      0xFFC0CBFF
# define C_BROWN     0xA52A2AFF
# define C_GOLD      0xFFD700FF
# define C_SILVER    0xC0C0C0FF
# define C_GRAY      0x808080FF
# define C_LIGHT_GRAY 0xD3D3D3FF
# define C_DARK_GRAY 0xA9A9A9FF
# define C_MAROON    0x800000FF
# define C_OLIVE     0x808000FF
# define C_TEAL      0x008080FF
# define C_NAVY      0x000080FF
# define C_LIME      0x00FF00FF
# define C_INDIGO    0x4B0082FF
# define C_CRIMSON   0xDC143CFF
# define C_CORAL     0xFF7F50FF
# define C_LAVENDER  0xE6E6FAFF
# define C_TURQUOISE 0x40E0D0FF
# define C_VIOLET    0x8A2BE2FF
# define C_BEIGE     0xF5F5DCFF
# define C_IVORY     0xFFFFF0FF
# define C_KHAKI     0xF0E68CFF
# define C_SEASHELL  0xFFF5EEFF
# define C_CORNSILK  0xFFF8DCFF
# define C_PAPAYA_WHIP 0xFFEFD5FF
# define C_LINEN     0xFAF0E6FF
# define C_ANTIQUE_WHITE 0xFAEBD7FF

# define C_OLD_LACE  0xFDF5E6FF
# define C_BLANCHED_ALMOND 0xFFEBCDFF
# define C_BISQUE    0xFFE4C4FF
# define C_PEACH_PUFF 0xFFDAB9FF
# define C_NAVAJO_WHITE 0xFFDEADFF
# define C_MOCCASIN  0xFFE4B5FF
# define C_WHEAT     0xF5DEB3FF
# define C_MISTY_ROSE 0xFFE4E1FF
# define C_ROSY_BROWN 0xBC8F8FFF
# define C_SALMON    0xFA8072FF
# define C_LIGHT_SALMON 0xFFA07AFF
# define C_DARK_SALMON 0xE9967AFF
# define C_LIGHT_CORAL 0xF08080FF
# define C_INDIAN_RED 0xCD5C5CFF
# define C_LIGHT_PINK 0xFFB6C1FF
# define C_MEDIUM_VIOLET_RED 0xC71585FF
# define C_DARK_VIOLET 0x9400D3FF
# define C_DARK_ORCHID 0x9932CCFF
# define C_DARK_MAGENTA 0x8B008BFF
# define C_PURPLE     0x800080FF
# define C_INDIGO     0x4B0082FF
# define C_SLATE_BLUE 0x6A5ACDFF
# define C_MEDIUM_PURPLE 0x9370DBFF
# define C_DARK_SLATE_BLUE 0x040947FF
# define C_MEDIUM_SLATE_BLUE 0x7B68EEFF
# define C_LAVENDER_BLUSH 0xFFF0F5FF
# define C_THISTLE    0xD8BFD8FF
# define C_PLUM       0xDDA0DDFF
# define C_VIOLET_RED 0xEE82EEFF
# define C_ORCHID     0xDA70D6FF
# define C_MEDIUM_ORCHID 0xBA55D3FF
# define C_DARK_ORCHID 0x9932CCFF
# define C_DARK_VIOLET 0x9400D3FF
# define C_BLUE_VIOLET 0x8A2BE2FF
# define C_MEDIUM_VIOLET_RED 0xC71585FF
# define C_PALE_VIOLET_RED 0xDB7093FF
# define C_DEEP_PINK 0xFF1493FF
# define C_HOT_PINK  0xFF69B4FF
# define C_LIGHT_HOT_PINK 0xFFB6C1FF
# define C_MEDIUM_HOT_PINK 0xCD5C5CFF
# define C_DARK_HOT_PINK 0x8B0000FF
# define C_LIGHT_SKY_BLUE 0x87CEFAFF
# define C_SKY_BLUE   0x87CEEBFF
# define C_DEEP_SKY_BLUE 0x00BFFFFF
# define C_LIGHT_STEEL_BLUE 0xB0C4DEFF
# define C_DODGER    0x1E90FFFF


enum	axis{x_ax, y_ax};
enum	sets
{
	mandel = 1,
	julia = 2
};

enum	palettes
{
	normal,
	zebra,
	inverse,
	multi
};

// complex point, x = real, y = imaginary
typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_color_char
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}	t_color;

typedef struct s_color_double
{
	double	r;
	double	g;
	double	b;
	double	a;
}	t_color_d;

typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*img_j;// d
	unsigned int	*palette_m;
	unsigned int	*palette_j;
	t_color		c_low;
	t_color		c_high;
	unsigned int	color_inf;
	t_color		c_a;
	t_color		c_b;
	t_color		c_c;
	t_color		c_d;
	size_t		iterations;
	size_t		iterations_j;// d
	short		set;
	double		inp;
	double		zoom;
	double		zoom_j;
	double		ratio;
	double		offset_x;
	double		offset_y;
	double		offset_x_j;
	double		offset_y_j;
	bool		draw;
	bool		draw_j;// d
	bool		lock_j;// d
	int			x;
	int			y;
	double		julia_x;
	double		julia_y;
	bool		split;
	short		palette;
}	t_fractal;


void	ft_draw_mandel(t_fractal *f);
void	ft_draw_julia(t_fractal *f);
void	ft_draw_mandel_split(t_fractal *f, t_complex z);
void	ft_draw_julia_split(t_fractal *f, t_complex c);
void	ft_image_resize(int32_t width, int32_t height, void* param);

void	ft_key_basic(mlx_key_data_t keydata, void* param);
void	ft_key_split(mlx_key_data_t keydata, void* param);
void	ft_scroll(double xdelta, double ydelta, void *param);
void	ft_split_scroll(double xdelta, double ydelta, void *param);
void	split_move_hook(void *param);
bool	ft_cursor_check(t_fractal *f);

void	ft_fract_math(t_fractal *f, t_complex c, t_complex z);
void	ft_fract_math_jul(t_fractal *f, t_complex c, t_complex z);

double	ft_scale_x(t_fractal *f, double val);
double	ft_scale_y(t_fractal *f, double val);

unsigned int	round_to_uint(double n);
unsigned int	rgba_to_hex(t_color c);
t_color	hex_to_rgba(unsigned int hex);

void	init_color_palette_m(t_fractal *f, unsigned int size);
void	init_color_palette_j(t_fractal *f, unsigned int size);
void	z_init_color_palette_m(t_fractal *f, unsigned int size);
void	z_init_color_palette_j(t_fractal *f, unsigned int size);
void	re_init_palette(t_fractal *f, short set);

void	ft_cursor_to_julia(void *param);
void	ft_cursor_to_julia_basic(void *param);

void	assign_hooks_basic(t_fractal *f);
void	assign_hooks_split(t_fractal *f);

int		num_check(t_fractal *f, char *arg, int i);
bool	arg_check(t_fractal *f, char *arg);
void	assign_jul_c(t_fractal *f, char *arg);

void	init_basic_struct(t_fractal *f);
void	init_split_struct(t_fractal *f);
void	iteration_mod(t_fractal *f, short mod);
void	ft_window_size_set(t_fractal *f, short size);
void	close_all(void *param);
void	ft_error(t_fractal *f, char *message);

#endif