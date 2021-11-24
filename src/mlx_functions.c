#include <fdf.h>

void	mlx_start_img(t_fdf *fdf)
{
	printf("->%p\n", fdf);
	mlx_control_keys(fdf);
	printf("-->%p\n", fdf->img);
	printf("->%p\n", &fdf->img->addrs);
	
	fdf->img->addrs = mlx_get_data_addr(&fdf->img->img, &fdf->img->bpp, &fdf->img->ln_len, &fdf->img->endian);
	
	//printf("->%s\n", fdf->img->addrs);
	//my_mlx_put_pixel(fdf->img, fdf->xyz);
	//mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
}

void	my_mlx_put_pixel(t_img *img, t_xyz *xyz)
{
	char *dst;

	dst = img->addrs + (xyz->y * img->ln_len + xyz->x * (img->bpp / 8));
	*(unsigned int*)dst = xyz->color;
}

void	mlx_control_keys(t_fdf *fdf)
{
	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_hook(fdf->win, 17, 1L<<17, x_close, fdf);
}
