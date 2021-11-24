#include <fdf.h>

int	key_hook(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int	x_close(int keycode, t_fdf *fdf)
{
	(void)keycode;
	(void)fdf;
	//mlx_destroy_window(fdf->mlx, fdf->win);
	//mlx_destroy_image(fdf->mlx, fdf->img->img);
	exit(0);
	return (0);
}
