#include <fdf.h>

void	init_structs()
{
	t_fdf	fdf;
	t_img	img;
	t_map	map;
	t_xyz	xyz;
	
	init_map(&map);
	init_xyz(&xyz);
	init_img(&img);
	fdf.img = &img;
	fdf.map = &map;
	fdf.xyz = &xyz;
	init_fdf(&fdf);
	
}

void	init_img(t_img *img)
{
	img->addrs = NULL;
	img->pxlbit = 0;
	img->ln_byt = 0;
	img->endian = 0;
}

int	key_hook(int keycode, t_fdf *fdf)
{
	(void)fdf;
	//printf("%d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

int 	x_close(int keycode, t_fdf *fdf)
{
	(void)keycode;
	(void)fdf;
	//mlx_destroy_window(fdf->mlx, fdf->win);
	//mlx_destroy_image(fdf->mlx, fdf->img->img);	
	exit(0);
	return(0);
}

void	init_fdf(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1280, 720, "FdF");
	fdf->img->img = mlx_new_image(fdf->mlx, 1280, 720);
	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_hook(fdf->win, 17, 1L<<17, x_close, fdf);
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
