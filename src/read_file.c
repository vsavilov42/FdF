#include <fdf.h>

void	parse_map(t_fdf *fdf, char *cmap)
{
	open_map(fdf, cmap);
	memory_map(fdf);
	cord_colors(fdf, cmap);
	min_max_z(fdf);
}

int	get_color(char *clr)
{
	while ((*clr && ft_isdigit(*clr)) || *clr == '+'|| *clr == '-' || *clr == ',')
		clr++;
	if (*clr && (*clr == 'x'))
		return (hex_color(clr + 1));
	else
		return (WHITE);
	return (0);
}

void	cord_colors(t_fdf *fdf, char *cmap)
{
	int fd;
	int x;
	int y;
	char *ln;
	char **split;

	x = 0;
	fd = open(cmap, O_RDONLY);
	while (++x < fdf->height)
	{
		ln = get_next_line(fd);
		split = ft_split(ln, ' ');
		y = -1;
		while (++y < fdf->width)
		{
			printf("%d\n", fdf->cord[x][y]);
			fdf->cord[x][y] = ft_atoi(split[y]);
			fdf->colors[x][y] = get_color(split[y]);
		}
		free_split(split);
		free(ln);
	}
	close(fd);
}

void	memory_map(t_fdf *fdf)
{
	int i;

	i = -1;
	fdf->cord = (int **)malloc(sizeof(int *) * fdf->height);
	fdf->colors = (int **)malloc(sizeof(int *) * fdf->height);
	while (++i < fdf->height)
	{
		fdf->cord[i] = (int *)malloc(sizeof(int) * fdf->width);
		fdf->colors[i] = (int *)malloc(sizeof(int) * fdf->width);
	}
}

void	open_map(t_fdf *fdf, char *map)
{
	int fd;
	char *ln;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit(invmap());
	ln = get_next_line(fd);
	fdf->width = count_nums(ln);
	while (ln)
	{
		if (count_nums(ln) != fdf->width && fdf->width != 0)
			exit(invmap());
		fdf->height++;
		free(ln);
		ln = get_next_line(fd);
	}
	free(ln);
	close(fd);
}
