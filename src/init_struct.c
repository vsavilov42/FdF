#include <fdf.h>

void	init_structs()
{
	t_fdf	*fdf;
	t_img	*img;
	t_map	*map;
	t_xyz	*xyz;

	fdf = malloc(sizeof(t_fdf));
	img = malloc(sizeof(t_img));
	map = malloc(sizeof(t_map));
	xyz = malloc(sizeof(t_xyz));
	init_fdf(fdf);
	init_map(map);
	init_xyz(xyz);
}

void	init_fdf(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1280, 720, "FdF By Vsavilov");
	fdf->img = mlx_new_image(fdf->mlx,1280, 720);
	//fdf->map = &map;
	//fdf->xyz = &xyz;
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
