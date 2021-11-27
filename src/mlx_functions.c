#include <fdf.h>

void	mlx_start_img(t_fdf *fdf)
{
	mlx_control_keys(fdf);
	fdf->img.addrs = mlx_get_data_addr(fdf->img.img, &fdf->img.bpp, &fdf->img.ln_len, &fdf->img.endian);	
	my_mlx_put_pixel(fdf->img, fdf->xyz);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, fdf->xyz.x, fdf->xyz.y);
}

void	my_mlx_put_pixel(t_img img, t_xyz xyz)
{
	int pixel;

	if (xyz.y >= WIN_H || xyz.x >= WIN_H || xyz.y < 0 || xyz.z < 0)
		return ;
	pixel = xyz.y * img.ln_len + xyz.x * (img.bpp / 8);
	if (img.endian == 0)
	{
		img.addrs[pixel + 0] = (xyz.color) & 0xFF;
		img.addrs[pixel + 1] = (xyz.color >> 8) & 0xFF;
		img.addrs[pixel + 2] = (xyz.color >> 16) & 0xFF;
		img.addrs[pixel + 3] = (xyz.color >> 24);	
	}
	else if (img.endian == 1)
	{
		img.addrs[pixel + 0] = (xyz.color >> 24);
		img.addrs[pixel + 1] = (xyz.color >> 16) & 0xFF;
		img.addrs[pixel + 2] = (xyz.color >> 8) & 0xFF;
		img.addrs[pixel + 3] = (xyz.color) & 0xFF;	
	}
}

void	mlx_control_keys(t_fdf *fdf)
{
	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_hook(fdf->win, 17, 1L<<17, x_close, fdf);
}
