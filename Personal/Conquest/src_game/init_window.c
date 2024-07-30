#include "../conquest.h"

bool	init_mlx_instance(
	mlx_t *mlx, uint32_t width, uint32_t height, char *title, bool resize)
{
	mlx = mlx_init(width, height, title, resize);
	if (!mlx)
		return (false);
	return (true);
}

bool	init_mlx_img(
	mlx_t *mlx, mlx_image_t *img, uint32_t width, uint32_t height)
{
	img = mlx_new_image(mlx, width, height);
	if (!img)
		return (false);
	return (true);
}
