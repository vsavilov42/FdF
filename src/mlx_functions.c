#include <fdf.h>

void	mlx_start_img(t_fdf *fdf)
{
	t_ang *ang;

	ang = (t_ang *)ft_calloc(1, (sizeof(t_ang)));
		if (!ang)
			exit(eang());
	init_ang(fdf, ang);
	mlx_managment(fdf);
	fdf->ang = *ang;
	draw_bresenham(fdf);
	mlx_control_keys(fdf);
	mlx_loop(fdf->mlx);
	free(ang);
}

void	mlx_managment(t_fdf *fdf)
{
	fdf->img.addrs = mlx_get_data_addr(fdf->img.img, &fdf->img.bpp,
			&fdf->img.ln_len, &fdf->img.endian);

}

void	my_mlx_put_pixel(t_img img, int x, int y, int color)
{
	int pixel;

	if (y >= WIN_H || x >= WIN_H || x < 0 || y < 0)
		return ;
	pixel = y * img.ln_len + x * (img.bpp / 8);
	if (img.endian == 0)
	{
		img.addrs[pixel + 0] = (color) & 0xFF;
		img.addrs[pixel + 1] = (color >> 8) & 0xFF;
		img.addrs[pixel + 2] = (color >> 16) & 0xFF;
		img.addrs[pixel + 3] = (color >> 24);	
	}
	else if (img.endian == 1)
	{
		img.addrs[pixel + 0] = (color >> 24);
		img.addrs[pixel + 1] = (color >> 16) & 0xFF;
		img.addrs[pixel + 2] = (color >> 8) & 0xFF;
		img.addrs[pixel + 3] = (color) & 0xFF;	
	}
}

void	mlx_control_keys(t_fdf *fdf)
{
	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_hook(fdf->win, 17, 1L<<17, x_close, fdf);
}
