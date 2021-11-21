#include <fdf.h>

void	init_structs(void)
{
	t_fdf *fdf;
	t_map *map;
	t_xyz *xyz;

	fdf = NULL;
	map = NULL;
	xyz = NULL;
	init_fdf(fdf);
	init_map(map);
	init_xyz(xyz);
}

void	init_fdf(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1920, 1080, "FdF By Vsavilov");
	fdf->image = mlx_new_image(fdf->mlx,1920, 1080);
	fdf->map = &map;
	fdf->xyz = &xyz;
}

void	init_map(t_map *map)
{
	map->width = 1920;
	map->height = 1080;
	map->colors = 0;
}

void	init_xyz(t_xyz *xyz)
{
	xyz->x = 0;
	xyz->y = 0;
	xyz->z = 0;
	xyz->color = 0;
}
