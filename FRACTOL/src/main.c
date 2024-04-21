#include "../lib/fractol.h"

// Input error | format: ./name "[type/ set]"(mandelbrot/ julia/ divine) "[optional julia z val]"
int	num_check(t_fractal *f, char *arg, int i)
{
	int	c;
	
	c = 0;
	if (arg[i] == '-')
		i++;
	if (!(ft_isdigit(arg[i])))
		ft_error(f, "Instr...2");
	while (arg[i] && (ft_isdigit(arg[i]) || arg[i] == '.'))
	{
		if (arg[i] == '.')
			c++;
		i++;
	}
	if (c > 1)
		ft_error(f, "Instr...3");
	return (i);
}

bool	arg_check(t_fractal *f, char *arg)
{
	int	i;

	if (!arg || ft_strlen(arg) > 1000 || ft_strlen(arg) < 4)
		ft_error(f, "Instr...1");
	i = 0;
	i = num_check(f, arg, i);
	if (arg[i] != ',' || arg[i + 1] != ' ' || !ft_isdigit(arg[i + 2]))
		ft_error(f, "Instr...4");
	i += 2;
	i = num_check(f, arg, i);
	if (ft_strlen(arg) != i)
		ft_error(f, "Instr...5");
	return (true);
}

double	ft_atof(char *arg)
{
	double	num;
	int		i;
	int		mult;
	int		c;
	
	i = 0;
	mult = 1;
	num = 0;
	if (arg[i] == '-')
		mult = -1;
	while (arg[i] && ft_isdigit(arg[i]))
	{
		num = num * 10 + (arg[i] - '0');
		i++;
	}
	c = i;
	if (arg[i] != '.')
		return (num * mult);
	i++;
	while (arg[i] && ft_isdigit(arg[i]))
	{
		num += (double)(arg[i] - '0') / pow(10, (double)(i - c));
		i++;
	}
	return (num * mult);
}

void	assign_jul_c(t_fractal *f, char *arg)
{
	f->julia_x = ft_atof(arg);
	while (*arg != ' ')
		arg++;
	f->julia_y = ft_atof(++arg);
}

void	move_hook(void *param)
{
	t_fractal	*f;
	
	f = param;
	if (mlx_is_key_down(f->mlx, MLX_KEY_UP))
	{
		f->offset_y += 0.02;
		f->draw = true;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_DOWN))
	{
		f->offset_y -= 0.02;
		f->draw = true;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_LEFT))
	{
		f->offset_x -= 0.02;
		f->draw = true;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_RIGHT))
	{
		f->offset_x += 0.02;
		f->draw = true;
	}
}

void	draw_hook(void *param)
{
	t_fractal	*f;
	
	f = param;
	if (f->draw && f->set == mandel)
	{
		printf(">> DRAW MAND\n");// TEST
		ft_draw_mandel(f);
	}
	else if (f->draw && f->set == julia)
	{
		printf(">> DRAW JUL\n");// TEST
		ft_draw_julia(f);
	}
	if (f->color_shift == true)
		color_shift(f);
}

void	draw_hook_divine(void *param)
{
	t_fractal	*f;
	t_complex	z;
	
	f = param;
	if (f->draw)
	{
		z.x = 0.0;
		z.y = 0.0;
		printf(">> DRAW MAND D\n");// TEST
		ft_draw_mandel_div(f, z);
	}
	if (f->draw_j)
	{
		printf(">> DRAW JUL D\n");// TEST
		ft_draw_julia_div(f);
	}
}

static void	assign_hooks_universal(t_fractal *f)
{
	mlx_scroll_hook(f->mlx, ft_scroll, f);
	mlx_loop_hook(f->mlx, move_hook, f);
	mlx_close_hook(f->mlx, close_all, f);
}

static void	assign_hooks_basic(t_fractal *f)
{
	mlx_key_hook(f->mlx, ft_key_basic, f);// DOES THIS WORK??
	mlx_resize_hook(f->mlx, ft_image_resize, f);
	mlx_loop_hook(f->mlx, draw_hook, f);
}

static void	assign_hooks_divine(t_fractal *f)
{
	mlx_key_hook(f->mlx, ft_key_divine, f);
	mlx_loop_hook(f->mlx, draw_hook_divine, f);
	mlx_loop_hook(f->mlx, ft_cursor_to_julia, f);
}

static void	create_mlx_basic(t_fractal *f, char *name)
{
	mlx_set_setting(MLX_MAXIMIZED, false);
	f->mlx = mlx_init(WIDTH_A, HEIGHT_A, name, true);
	if (!f->mlx)
		ft_error(f, "MLX init error");
	f->img = mlx_new_image(f->mlx, WIDTH_A, HEIGHT_A);
	if (!f->img || (mlx_image_to_window(f->mlx, f->img, 0, 0) < 0))
		ft_error(f, "MLX image error");
}

// Creates an mlx window with two images:
// one on the upper 2/3 (mandelbrot) (1:1)ratio
// one on the lower 1/3 (julia) (1:2)ratio
static void	create_mlx_divine(t_fractal *f)
{
	mlx_set_setting(MLX_MAXIMIZED, false);
	f->mlx = mlx_init(D_WIDTH, D_HEIGHT, "~ Divine View ~", false);
	if (!f->mlx)
		ft_error(f, "MLX init error");
	f->img = mlx_new_image(f->mlx, M_WIDTH, M_HEIGHT);// mand
	if (!f->img || (mlx_image_to_window(f->mlx, f->img, 0, 0) < 0))
		ft_error(f, "MLX image error");
	f->img_div_j = mlx_new_image(f->mlx, J_WIDTH, J_HEIGHT);// julia
	if (!f->img || (mlx_image_to_window(f->mlx, f->img_div_j, 0, 600) < 0))
		ft_error(f, "MLX image error");
	printf("test 1\n");// TEST
	// HOW DO I PLACE THE IMAGES INSIDE WINDOW??
}

void	fractol(char *name, t_fractal *f)
{
	if (f->divine == true)
	{
		create_mlx_divine(f);
		assign_hooks_divine(f);
	}
	else
	{
		create_mlx_basic(f, name);
		assign_hooks_basic(f);
	}
	init_fractal_struct(f);
	assign_hooks_universal(f);
	mlx_loop(f->mlx);
	mlx_terminate(f->mlx);
}

int32_t	main(int argc, char **argv)
{
	t_fractal	f;

	f.mlx = NULL;
	if (argc != 2 && argc != 3)
		ft_error(&f, "Instructions...1");
	f.divine = false;
	if (!(ft_strncmp(argv[1], "mandelbrot", 10)))
		f.set = mandel;
	else if (!(ft_strncmp(argv[1], "julia", 5)))
		f.set = julia;
	else if (!(ft_strncmp(argv[1], "divine", 6)))
		f.divine = true;
	else
		ft_error(&f, "Instructions...2");
	f.julia_x = -1.2;
	f.julia_y = 0.0;
	if (argc == 3 && arg_check(&f, argv[2]))
		assign_jul_c(&f, argv[2]);
	fractol(argv[1], &f);
	return (EXIT_SUCCESS);
}
