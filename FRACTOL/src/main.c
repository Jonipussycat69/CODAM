#include "../lib/fractol.h"

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	loop_hook(void *param)
{
	t_fractal	*f;
	
	f = param;
	if (mlx_is_key_down(f->mlx, MLX_KEY_UP))
		f->offset_y += 0.01;
	if (mlx_is_key_down(f->mlx, MLX_KEY_DOWN))
		f->offset_y -= 0.01;
	if (mlx_is_key_down(f->mlx, MLX_KEY_LEFT))
		f->offset_x -= 0.01;
	if (mlx_is_key_down(f->mlx, MLX_KEY_RIGHT))
		f->offset_x += 0.01;
	ft_draw(f->mlx->width, f->mlx->height, f);// MAKE SO ID DOESNT DRAW EVERY FRAME!?
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
	init_fractal_struct(f);
	ft_draw(WIDTH_A, HEIGHT_A, f);
	mlx_scroll_hook(f->mlx, ft_scroll, f);
	mlx_key_hook(f->mlx, ft_key, f);
	mlx_resize_hook(f->mlx, ft_image_resize, f);
	mlx_loop_hook(f->mlx, loop_hook, f);
	mlx_loop(f->mlx);
	mlx_terminate(f->mlx);
}

int32_t	main(int argc, char **argv)
{
	t_fractal	f;

	if (argc != 2)
		ft_error();
	fractol(argv[1], &f);
	return (EXIT_SUCCESS);
}
