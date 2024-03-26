#include "ch_planner.h"

void	read_txt(const char *filename)
{
	FILE *file = fopen(filename, "r"); // Open file in read mode
	if (file == NULL) {
		printf("Error opening file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	char line[256]; // Buffer to store each line read from the file
	while (fgets(line, sizeof(line), file) != NULL) { // Read each line until end of file
		printf("%s", line); // Print the line
	}
	fclose(file); // Close the file
}

void	parse_time()
{

}

void	parse_member()
{

}

void	parse_chore()
{

}
