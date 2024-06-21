#include "../minish_param.h"

// Frees *ptr if != NULL, then sets it to NULL
void	ifnotnull_free_setnull(void **ptr)
{
	if (ptr && *ptr)
		free(ptr);
	*ptr = NULL;
}
