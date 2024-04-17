#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../libft/libft.h"
#include "MLX42/MLX42.h"

# define WIDTH 800
# define HEIGHT 600

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
	c_t			*c;
	short		set;
	double		inp;
}	fra_t;



#endif