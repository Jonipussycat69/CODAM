#include "../lib/fractol.h"

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	ft_window_size_reset(fra_t *f)
{
	mlx_resize_image(f->img, WIDTH, HEIGHT);
	mlx_set_window_size(f->mlx, WIDTH, HEIGHT);
}

void	ft_key(mlx_key_data_t keydata, void* param)
{
	fra_t	*f;
	
	f = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(f->mlx);
		exit(EXIT_SUCCESS);
	}
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		ft_window_size_reset(f);
}

void	draw(int32_t width, int32_t height, const fra_t *f)
{
	int	w;
	int	h;
	
	w = 0;
	while (w < width)
	{
		h = 0;
		while (h < height)
		{
			if (h < height / 2)
				mlx_put_pixel(f->img, w, h, 0x0000FFFF);
			else
				mlx_put_pixel(f->img, w, h, 0xFF0000FF);
			h++;
		}
		w++;
	}
}

static void ft_image_redraw(int32_t width, int32_t height, void* param)
{
	const fra_t	*f = param;

	printf("WIDTH: %d | HEIGHT: %d\n", width, height);// TEST
	mlx_resize_image(f->img, width, height);
	draw(width, height, f);
}

void	window(char *name, fra_t *f)
{
	mlx_set_setting(MLX_MAXIMIZED, false);
	f->mlx = mlx_init(WIDTH, HEIGHT, name, true);
	if (!f->mlx)
		ft_error();
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img || (mlx_image_to_window(f->mlx, f->img, 0, 0) < 0))
		ft_error();
	draw(WIDTH, HEIGHT, f);
	mlx_key_hook(f->mlx, ft_key, f);
	mlx_resize_hook(f->mlx, ft_image_redraw, f);
	mlx_loop(f->mlx);
	mlx_terminate(f->mlx);
}

int32_t	main(int argc, char **argv)
{
	fra_t	f;

	if (argc != 2)
		ft_error();
	window(argv[1], &f);
	return (EXIT_SUCCESS);
}
