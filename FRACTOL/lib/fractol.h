#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <math.h>
# include "../libft/libft.h"
# include "MLX42/MLX42.h"

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

// DIVINE MODE

# define D_WIDTH 1400
# define D_HEIGHT 700

// mandelbrot
# define M_WIDTH 700
# define M_HEIGHT 700

// julia
# define J_WIDTH 700
# define J_HEIGHT 700

# define X_MAX_J 2.0
# define X_MIN_J -2.0
# define Y_MAX_J -2.0
# define Y_MIN_J 2.0

// colours
# define BLACK	0x000000FF
# define WHITE	0xFFFFFFFF
# define RED	0xFF0000FF
# define GREEN	0x00FF00FF
# define BLUE	0x0000FFFF
# define YELLOW	0xFFFF00FF
# define CYAN	0x00FFFFFF
# define MAGENT	0xFF00FFFF
# define GRAY	0x808080FF


enum	axis{x_ax, y_ax};
enum	sets
{
	mandel = 1,
	julia = 2
};

// complex point, x = real, y = imaginary
typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*img_div_j;// d
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
	unsigned int	c_range;
	unsigned int	color;
	bool		color_shift;
	bool		draw;
	bool		draw_j;// d
	bool		lock_j;// d
	int			x;
	int			y;
	double		julia_x;
	double		julia_y;
	bool		divine;
	bool		test;// TEST
}	t_fractal;

void	ft_draw_mandel(t_fractal *f);
void	ft_draw_julia(t_fractal *f);
void	ft_draw_mandel_div(t_fractal *f, t_complex z);
void	ft_draw_julia_div(t_fractal *f, t_complex c);
void	ft_image_resize(int32_t width, int32_t height, void* param);

void	ft_key_basic(mlx_key_data_t keydata, void* param);
void	ft_key_divine(mlx_key_data_t keydata, void* param);
void	ft_scroll(double xdelta, double ydelta, void *param);
void	ft_div_scroll(double xdelta, double ydelta, void *param);
void	div_move_hook(void *param);
bool	ft_cursor_check(t_fractal *f);

void	ft_fract_math(t_fractal *f, t_complex c, t_complex z);
void	ft_fract_math_jul(t_fractal *f, t_complex c, t_complex z);

double	ft_scale_x(t_fractal *f, double val);
double	ft_scale_y(t_fractal *f, double val);

void	color_shift(t_fractal *f);

void	ft_cursor_to_julia(void *param);

void	assign_hooks_basic(t_fractal *f);
void	assign_hooks_divine(t_fractal *f);

int		num_check(t_fractal *f, char *arg, int i);
bool	arg_check(t_fractal *f, char *arg);
void	assign_jul_c(t_fractal *f, char *arg);

void	init_basic_struct(t_fractal *f);
void	init_divine_struct(t_fractal *f);
void	iteration_mod(t_fractal *f, short mod, short set);
void	ft_window_size_set(t_fractal *f, short size);
void	close_all(void *param);
void	ft_error(t_fractal *f, char *message);

#endif