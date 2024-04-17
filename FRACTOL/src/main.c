#include "../lib/fractol.h"

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	fractol(char *name, t_fractal *f)
{
	mlx_set_setting(MLX_MAXIMIZED, false);
	f->mlx = mlx_init(WIDTH_A, HEIGHT_A, name, true);
	if (!f->mlx)
		ft_error();
	f->img = mlx_new_image(f->mlx, WIDTH_A, HEIGHT_A);
	if (!f->img || (mlx_image_to_window(f->mlx, f->img, 0, 0) < 0))
		ft_error();
	ft_draw(WIDTH_A, HEIGHT_A, f);
	mlx_scroll_hook(f->mlx, ft_scroll, f);
	mlx_key_hook(f->mlx, ft_key, f);
	mlx_resize_hook(f->mlx, ft_image_resize, f);
	mlx_loop(f->mlx);
	mlx_terminate(f->mlx);
}

int32_t	main(int argc, char **argv)
{
	t_fractal	f;

	if (argc != 2)
		ft_error();
	init_fractal_struct(&f);
	fractol(argv[1], &f);
	return (EXIT_SUCCESS);
}
