#include <fdf.h>

void	parse_map(t_fdf *fdf, char *cmap)
{
	int i = 0;

	init_map(fdf->map);
	fdf->map->cmap = save_map(cmap);
	while (fdf->map->cmap[i])
	{
		printf("%s\n", fdf->map->cmap[i]);
		free(fdf->map->cmap[i++]);
	}
	free(fdf->map->cmap);
}

char	**save_map(char *map)
{
	int i;
	int fd;
	char **cmap;

	cmap = malloc(sizeof(char) * ft_strlen(map));
	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit(1);
	i = 0;
	map = get_next_line(fd);
	while (map)
	{
		//printf("%s\n", map);
		cmap[i++] = ft_strdup(map);
		free (map);
		map = get_next_line(fd);	
	}
	free (map);
	return (cmap);
}
