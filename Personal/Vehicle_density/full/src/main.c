#include "../vdensity.h"

static int	terminal_input_loop(t_data *data, char *inp_buffer)
{
	int	loop_count = 0;

	while (1)
	{
		if (!parse_line_to_buffer(data->inp_file, inp_buffer))
			return (1);
		if (strncmp(inp_buffer, "exit", strlen(inp_buffer)) || strncmp(inp_buffer, "", 1))
			return (0);
		if (parse_input(&data, inp_buffer))
		{
			if (!calc_density(data))
				return (free(data->pos_arr), 1);
			print_results(data, loop_count);
			free(data->pos_arr);
			loop_count++;
		}
		else
			printf("Invalid input\n");
	}
	return (0);
}

static int	file_input(t_data *data, char *inp_buffer)
{
	while (!inp_buffer)
	{
		if (!parse_line_to_buffer(data->inp_file, inp_buffer))
			return (free(data->pos_arr), 1);
		// LEFTOFF
	}
}

int	main(int argc, char **argv)
{
	char	inp_buffer[BUFFER_SIZE];
	t_data	data;

	if (argc == 1)
	{
		data.inp_file = stdin;
		return (terminal_input_loop(&data, inp_buffer));
	}
	else
	{
		data.inp_file = fopen(argv[1], "r");
		if (argc > 2 || !data.inp_file)
			return (1);
		return (file_input(&data, inp_buffer));
	}
	return (0);
}
