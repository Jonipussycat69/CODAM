#include "../lib/fractol.h"

bool	arg_check(char *arg)
{
	int	i;

	if (!arg || ft_strlen(arg) > 1000 || ft_strlen(arg) < 4)
		ft_error("Instr...");
	i = 0;
	while (arg[i] && (ft_isdigit(arg[i]) || arg[i] == ' ' || \
			arg[i] == ',' || arg[i] == '.'))
		i++;
	if (i < ft_strlen(arg))
		ft_error("Instr...");
	return (true);
}

void	ft_atof(t_fractal *f, char *arg)// LEFTOFF !
{
	f->julia_x = -1.2;
	f->julia_y = 0.0;
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
	if (f->draw && f->set == julia)
	{
		printf(">> DRAW JUL\n");// TEST
		ft_draw_julia(f);
	}
}

static void	assign_hooks(t_fractal *f)
{
	mlx_scroll_hook(f->mlx, ft_scroll, f);
	mlx_key_hook(f->mlx, ft_key, f);
	mlx_resize_hook(f->mlx, ft_image_resize, f);
	mlx_loop_hook(f->mlx, move_hook, f);
	mlx_loop_hook(f->mlx, draw_hook, f);
}

void	fractol(char *name, t_fractal *f)
{
	mlx_set_setting(MLX_MAXIMIZED, false);
	f->mlx = mlx_init(WIDTH_A, HEIGHT_A, name, true);
	if (!f->mlx)
		ft_error("MLX init error");
	f->img = mlx_new_image(f->mlx, WIDTH_A, HEIGHT_A);
	if (!f->img || (mlx_image_to_window(f->mlx, f->img, 0, 0) < 0))
		ft_error("MLX image error");
	init_fractal_struct(f);
	assign_hooks(f);
	mlx_loop(f->mlx);
	mlx_terminate(f->mlx);
}

int32_t	main(int argc, char **argv)
{
	t_fractal	f;

	if (argc != 2 && argc != 3)
		ft_error("Instructions...");
	f.divine = false;
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
		f.set = mandel;
	else if (!ft_strncmp(argv[1], "julia", 5))
	{
		f.set = julia;
		if (argc == 3 && arg_check(argv[2]))
			ft_atof(&f, argv[2]);
		else
		{
			f.julia_x = -1.2;
			f.julia_y = 0.0;
		}
	}
	else if (!(ft_strncmp(argv[1], "divine", 6)))
		f.divine = true;
	else
		ft_error("Instructions...");
	fractol(argv[1], &f);
	return (EXIT_SUCCESS);
}
