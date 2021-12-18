#include <fdf.h>
static int base_zoom(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	init_ang(t_fdf *fdf, t_ang *ang)
{
	ang->zoom = base_zoom((WIN_W / fdf->width / 2), (WIN_H / fdf->height / 2)); 
	ang->i_x = WIN_H / 2;
	ang->i_y = (WIN_H - fdf->height * ang->zoom) / 2;
	ang->isom = 1;
	ang->ang_x = 0;
	ang->ang_y = 0;
	ang->ang_z = 0;
}
