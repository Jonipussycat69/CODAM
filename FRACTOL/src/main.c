#include "../lib/fractol.h"

static void	init_null(t_fractal *f)
{
	f->mlx = NULL;
	f->img = NULL;
	f->img_j = NULL;
	f->palette_m = NULL;
	f->palette_j = NULL;
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
static void	create_mlx_split(t_fractal *f)
{
	mlx_set_setting(MLX_MAXIMIZED, false);
	f->mlx = mlx_init(S_WIDTH, S_HEIGHT, "~ Split Screen ~", false);
	if (!f->mlx)
		ft_error(f, "MLX init error");
	f->img = mlx_new_image(f->mlx, M_WIDTH, M_HEIGHT);// mand
	if (!f->img || (mlx_image_to_window(f->mlx, f->img, 0, 0) < 0))
		ft_error(f, "MLX image error");
	f->img_j = mlx_new_image(f->mlx, J_WIDTH, J_HEIGHT);// julia
	if (!f->img || (mlx_image_to_window(f->mlx, f->img_j, M_WIDTH, 0) < 0))
		ft_error(f, "MLX image error");
	printf("test 1\n");// TEST
	// HOW DO I PLACE THE IMAGES INSIDE WINDOW??
}

void	fractol(char *name, t_fractal *f)
{
	f->color_inf = BLACK;
	f->c_low = hex_to_rgba(BLACK);
	f->c_high = hex_to_rgba(WHITE);
	f->c_a = hex_to_rgba(BLACK);
	f->c_b = hex_to_rgba(BLACK);
	f->c_c = hex_to_rgba(ORANGE);
	f->c_d = hex_to_rgba(WATER);
	f->palette = normal;
	if (f->split == true)
	{
		create_mlx_split(f);
		assign_hooks_split(f);
		init_split_struct(f);
		init_color_palette_j(f, f->iterations_j);
	}
	else
	{
		create_mlx_basic(f, name);
		assign_hooks_basic(f);
		init_basic_struct(f);
	}
	init_color_palette_m(f, f->iterations);
	mlx_loop(f->mlx);
	close_all(f);
}

int32_t	main(int argc, char **argv)
{
	t_fractal	f;

	init_null(&f);
	if (argc != 2 && argc != 3)
		ft_error(&f, "Instructions...1");
	f.split = false;
	f.set = mandel;
	if (!(ft_strncmp(argv[1], "mandelbrot", 10)))
		f.set = mandel;
	else if (!(ft_strncmp(argv[1], "julia", 5)))
		f.set = julia;
	else if (!(ft_strncmp(argv[1], "split", 6)))
		f.split = true;
	else
		ft_error(&f, "Instructions...2");
	f.julia_x = -1.2;
	f.julia_y = 0.0;
	if (argc == 3 && arg_check(&f, argv[2]))
		assign_jul_c(&f, argv[2]);
	fractol(argv[1], &f);
	return (EXIT_SUCCESS);
}
