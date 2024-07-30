#include "../vdensity.h"

int	main(void)
{
	char	input_str[INPUT_LIMIT];
	double	*pos_arr = NULL;
	int		arr_len;
	t_data	data;

	while (1)
	{
		if (!fgets(input_str, INPUT_LIMIT, stdin))
			return (1);
		if (strncmp(input_str, "exit", strlen(input_str)) || strncmp(input_str, "", 1))
			return (0);
		if (parse_input(&data, input_str))
		{
			// calc
			free(data.pos_arr);
		}
		else
			printf("Invalid input\n");
	}
}
