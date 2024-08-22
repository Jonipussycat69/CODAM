#include "../vdensity.h"

void	print_results(t_data *data, int loop_count)
{
	int	i = 0;

	printf("<RESULT %i>\n", loop_count);
	printf("Input positions:\n");
	while (i < data->pos_arr_len)
	{
		printf(" [%i] %f\n", i, data->pos_arr[i]);
		i++;
	}
	i = 0;
	printf("\nDensity results:\n");
	while (i < data->iterations)
	{
		printf(" [%i] %f\n", i, data->dens_arr[i]);
		i++;
	}
	printf("\nCompiled density: %f\n\n", data->dens_result);
}
