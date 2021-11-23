#include <fdf.h>

void	init_structs(t_fdf *fdf)
{
	t_img	img;
	t_xyz	xyz;
	
	init_xyz(&xyz);
	init_img(&img);
	fdf->img = &img;
	fdf->xyz = &xyz;
	init_fdf(fdf);
	
}

void	init_img(t_img *img)
{
	img->addrs = NULL;
	img->pxlbit = 0;
	img->ln_byt = 0;
	img->endian = 0;
}

void	init_fdf(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1280, 720, "FdF");
	fdf->img->img = mlx_new_image(fdf->mlx, 1280, 720);
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
