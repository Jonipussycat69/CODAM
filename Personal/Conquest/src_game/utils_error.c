#include "../conquest.h"

void	error_write_out(
	FILE *file, int err_num, const char *message, bool writetime)
{
	const char	*time = update_time_str();

	if (writetime)
	{
		if (!time)
		{
			fprintf(stderr, "time ERROR ");
			if (file)
				fprintf(file, "time ERROR ");
		}
		else
		{
			fprintf(stderr, "%s > ", time);
			if (file)
				fprintf(file, "%s > ", time);
		}
	}
	if (message == NULL)
		message = (char *)'\0';
	fprintf(stderr, "%s; %s\n", strerror(err_num), message);
	if (file)
		fprintf(file, "%s; %s\n", strerror(err_num), message);
}
