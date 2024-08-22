#include "../vdensity.h"

// calculates density on given point x, based on positions from the array
bool	calc_density(t_data *data)
{
	data->dens_arr = init_double_array(data->iterations);
	if (!data->dens_arr)
		return (false);
}
