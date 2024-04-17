#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "../libft/libft.h"
#include "MLX42/MLX42.h"

# define WIDTH 900
# define HEIGHT 600

enum	axis{x_ax, y_ax};
enum	sets
{
	mandel = 1,
	julia = 2
};

typedef struct complex_s
{
	double	real;
	double	imag;
}	c_t;

typedef struct fractol_s
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	size_t		iterations;
	short		set;
	double		inp;
	double		scale_min_x;
	double		scale_max_x;
	double		scale_min_y;
	double		scale_max_y;
	int			x;
	int			y;
}	fra_t;

void	draw(int32_t width, int32_t height, fra_t *f);

size_t	ft_math(fra_t *f, c_t c);
double	ft_scale(fra_t *f, double val, short axis);

#endif