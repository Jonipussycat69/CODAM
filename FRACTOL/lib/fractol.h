#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "../libft/libft.h"
#include "MLX42/MLX42.h"

# define WIDTH_A 900
# define HEIGHT_A 600
# define WIDTH_B 600
# define HEIGHT_B 400
# define WIDTH_C 900
# define HEIGHT_C 900

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
	size_t		iterations;
	short		set;
	double		inp;
	double		zoom;
	double		scale_min_x;
	double		scale_max_x;
	double		scale_min_y;
	double		scale_max_y;
	int			x;
	int			y;
}	t_fractal;

void		ft_draw(int32_t width, int32_t height, t_fractal *f);
void		ft_image_resize(int32_t width, int32_t height, void* param);

void		ft_key(mlx_key_data_t keydata, void* param);
void		ft_scroll(double xdelta, double ydelta, void* param);

size_t		ft_math(t_fractal *f, t_complex c);
double		ft_scale(t_fractal *f, double val, short axis);
t_complex	sum_complex(t_complex a, t_complex b);
t_complex	square_complex(t_complex a);

void		init_fractal_struct(t_fractal *f);
void		iteration_mod(t_fractal *f, short mod);
void		ft_window_size_set(t_fractal *f, short size);
void		init_aspect_ratio(t_fractal *f);

#endif