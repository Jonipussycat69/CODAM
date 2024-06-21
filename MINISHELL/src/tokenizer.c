#include "../minish_param.h"

char* expand_env_vars(const char* input) {
    char* result = strdup(input);
    char* dollar = strchr(result, '$');

    while (dollar != NULL) {
        // Find the end of the variable name
        char* end = dollar + 1;
        while (*end != '\0' && (isalnum(*end) || *end == '_')) {
            end++;
        }

        // Extract the variable name
        char var_name[256];
        strncpy(var_name, dollar + 1, end - dollar - 1);
        var_name[end - dollar - 1] = '\0';

        // Get the value of the variable
        char* value = getenv(var_name);

        if (value != NULL) {
            // Replace the variable with its value
            size_t new_len = strlen(result) + strlen(value) - (end - dollar);
            char* new_result = malloc(new_len + 1);

            strncpy(new_result, result, dollar - result);
            new_result[dollar - result] = '\0';
            strcat(new_result, value);
            strcat(new_result, end);

            free(result);
            result = new_result;
        }

        // Look for the next variable
        dollar = strchr(dollar + 1, '$');
    }

    return result;
}

size_t	env_variable_check(t_dad *d, size_t i)
{
	size_t	start;
	char 	*extracted_str;

	if (d->line[i] != '$')
		return (i);
	start = i;
	while (d->line[i] && (d->line[i] == '_' || ft_isalnum(d->line[i])))
		++i;
	extracted_str = strdup_index(d->line, start, i);
	if (!extracted_str)
		exit_clean(d, errno, NULL);
	
}


// Assigns tokens to each argument.
// Tokens:
// CMD
void	tokenizer(t_dad *d)
{
	size_t	i;
	
	i = 0;
	while (d->line[i])
	{
		if (d->line[i] == ' ')
			++i;
		i = env_variable_check(d, i);
	}
}
