#ifndef CONQUEST_H
# define CONQUEST_H
# include "conq_def.h"

// Function parameters

// utils_clean.c

void	exit_clean(t_main *m, int err_num, char *message, FILE *output_file);

// utils_error.c

void	error_write_out(FILE *file, int err_num, const char *message, bool writetime);

// utils_time.c

char	*update_time_str(void);

#endif