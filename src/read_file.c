#include <fdf.h>

void	parse_map(t_fdf *fdf, char *cmap)
{
	init_map(fdf->map);
	//save_map(fdf, cmap);
	//printf("%s\n", fdf->map.cmap[4]);
	//save_num_color(fdf);
	//printf("%s\n", fdf->map.cmap[0]);
}

/*void	save_map(char *map)
{
	int fd;
	char *ln;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit(invmap());
	ln = get_next_line(fd);
	fdf->map.width = count_nums(fdf, ln);
	while (ln)
	{
		if (count_nums(fdf, ln) != fdf->map.width && fdf->map.width != 0)
			exit(invmap());
		fdf->map.height++;
		free(ln);
		ln = get_next_line(fd);
	}
	free(ln);
}

int	count_nums(t_fdf *fdf, char *ln)
{
	int num;
	char **split;

	if (!ln)
		exit(emap);
	split = ft_split(ln, ' ');
	num = 0;
	while (split[num])
		num++;
	free_split(split);
	return (num);
}

void	save_num_color(t_fdf *fdf)
{
	int x;
	int y;
	char **line;

	x = 0;
	y = 0;
	fdf->cord = malloc(sizeof(int *) *);
	while(fdf->map.cmap)
	{
		line = malloc(sizeof(char) * ft_strlen(fdf->map.cmap[x]));
		line = ft_split(fdf->map.cmap[x], ' ');
		while (line)
		{
			fdf->cord[x][y] = ft_atoi(line[y]);
			y++;
		}
		x++;
	}
}

char	**save_map(char *map)
{
	int i;
	int fd;
	char **cmap;

	cmap = ft_calloc(1, sizeof(char *) * (count_lines(map) + 1));
	if (!cmap)
		return (NULL);
	fd = open(map, O_RDONLY);
	i = 0;
	map = get_next_line(fd);
	while (map)
	{
		cmap[i] = ft_strdup(map);
		free (map);
		map = get_next_line(fd);
		i++;
	}
	close(fd);
	free(map);
	return (cmap);
}

int	count_lines(char *map)
{
	int lines;
	int fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit(invmap());
	lines = 0;
	map = get_next_line(fd);
	while(map && ++lines)
	{
		free(map);
		map = get_next_line(fd);
	}
	free(map);
	close(fd);
	return (lines);
}*/
