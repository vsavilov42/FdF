#include <fdf.h>

void	parse_map(t_fdf *fdf, char *cmap)
{
	fdf->map = malloc(sizeof(t_map));
	init_map(fdf->map);
	fdf->map->cmap = save_map(cmap);
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
}
