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
	inverse
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