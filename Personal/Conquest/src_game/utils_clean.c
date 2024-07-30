#include "../conquest.h"

void	exit_clean(
	t_main *m, int err_num, char *message, FILE *output_file)
{
	// cleaning
	if (err_num == 0)
		exit(err_num);
	if (err_num != errno)
		errno = err_num;
	error_write_out(output_file, err_num, message, true);
	exit(err_num);
}
