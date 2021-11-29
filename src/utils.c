#include <fdf.h>

void	free_split(char **split)
{
	int i;

	i = -1;
	while(split[++i])
		free(split[i]);
	free(split);
}
