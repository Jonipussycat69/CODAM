#include "../lib/fractol.h"

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void ft_hook(void* param)
{
	const mlx_t	*mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

void	window(char *name)
{
	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, name, true);
	if (!mlx)
		ft_error();
	
	mlx_image_t* img = mlx_new_image(mlx, 100, 100);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	
	mlx_put_pixel(img, 0, 0, 0xFFFFFFFF);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}

int32_t	main(int argc, char **argv)
{
	if (argc != 2)
		ft_error();
	window(argv[1]);
	return (EXIT_SUCCESS);
}
