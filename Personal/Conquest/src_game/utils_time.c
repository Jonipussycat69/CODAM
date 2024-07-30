#include "../conquest.h"

#include <stdio.h>
#include <time.h>

// Returns pointer to static str with current date and time
char	*update_time_str(void)
{
	static char	time_str[100];
	struct tm	*local;

	local = get_local_time();
	if (!local)
		return (NULL);
	// Format the time as a string
	if (strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", local) == 0)
	{
		fprintf(stderr, "strftime returned 0");
		return (NULL);
	}
	return (time_str);
}

struct tm	*get_local_time(void)
{
	time_t		now;
	struct tm	*local;

	// Get the current time as a time_t object
	now = time(NULL);
	if (now == (time_t)-1)
	{
		perror("time");
		return (NULL);
	}
	// Convert to local time format
	local = localtime(&now);
	// Check if localtime() returned an error
	if (local == NULL)
	{
		perror("localtime");
		return (NULL);
	}
	return (local);
}
