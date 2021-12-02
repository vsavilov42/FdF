#include <fdf.h>

//hacer atoi base

int	hex_color(char *clr)
{
	int color;
	int i;

	i = -1;
	while (clr[++i])
		clr[i] = ft_tolower(clr[i]);
	color = ft_atoi_base(clr);
	//printf("%d\n", color);

	return (color);
}

void	free_split(char **split)
{
	int i;

	i = -1;
	while(split[++i])
		free(split[i]);
	free(split);
}

int	count_nums(char *ln)
{
	int num;
	char **split;

	if (!ln)
		exit(emap());
	split = ft_split(ln, ' ');
	num = 0;
	while (split[num])
		num++;
	free_split(split);
	return (num);
}
