#include <fdf.h>

int	hex_color(char *clr)
{
	int color;
	int i;

	i = -1;
	while (clr[++i])
		clr[i] = ft_tolower(clr[i]);
	color = ft_atoi_base(clr, HEX);
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

void	min_max_z(t_fdf *fdf)
{
	int x;
	int y;

	x = -1;
	while (++x < fdf->height)
	{
		y = -1;
		while (++y < fdf->width)
		{
			if (fdf->cord[x][y] < fdf->map.min_z)
				fdf->map.min_z = fdf->cord[x][y];
			else if (fdf->cord[x][y] > fdf->map.max_z)
				fdf->map.max_z = fdf->cord[x][y];
		}
	}
}
