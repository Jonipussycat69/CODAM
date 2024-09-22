#include "../vdensity.h"

int	main(void)
{
	char	input_str[INPUT_LIMIT];
	double	*pos_arr = NULL;
	int		loop_count = 0;;
	t_data	data;

	while (1)
	{
		if (!fgets(input_str, INPUT_LIMIT, stdin))
			return (EXIT_FAILURE);
		if (strncmp(input_str, "exit", strlen(input_str)) || strncmp(input_str, "", 1))
			return (EXIT_SUCCESS);
		if (parse_input(&data, input_str))
		{
			if (!calc_density(&data))
				return (free(data.pos_arr), 1);
			print_results(&data, loop_count);
			free(data.pos_arr);
			free(data.dens_arr);
			loop_count++;
		}
		else
			printf("Invalid input\n");
	}
	return (EXIT_SUCCESS);
}
