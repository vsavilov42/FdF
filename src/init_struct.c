#include <fdf.h>

void	init_structs(t_fdf *fdf)
{	
	init_xyz(fdf->xyz);
	init_img(fdf->img);
	init_fdf(fdf);
	
}

void	init_fdf(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_W, WIN_H, "FdF");
	fdf->img.img = mlx_new_image(fdf->mlx, WIN_W, WIN_H);
}

void	init_img(t_img img)
{
	img.addrs = NULL;
	img.bpp = 0;
	img.ln_len = 0;
}

void	init_map(t_map map)
{
	map.width = WIN_W;
	map.height = WIN_H;
	map.colors = 0;
}

void	init_xyz(t_xyz xyz)
{
	xyz.x = 100;
	xyz.y = 100;
	xyz.z = 0;
	xyz.color = 0xFFFFFF;
}
