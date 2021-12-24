#include <fdf.h>

int	sign_bres(int delta)
{
	if (delta < 0)
		return (-(delta));
	return (delta);
}

void	rotatex(t_ang *ang, int *y, int *z)
{
	float last_y;

	last_y = *y;
	*y = (last_y * cos(ang->ang_x)) + (*z * sin(ang->ang_x));
	*z = (-last_y * sin(ang->ang_x)) + (*z * cos(ang->ang_x));
}

void	rotatey(t_ang *ang, int *x, int *z)
{
	float last_x;

	last_x = *x;
	*x = (last_x * cos(ang->ang_y)) + (*z * sin(ang->ang_y));
	*z = (-last_x * sin(ang->ang_y)) + (*z * cos(ang->ang_y));
}

void	rotatez(t_ang *ang, int *x, int *y)
{
	float last_x;

	last_x = *x;
	*x = (*x * cos(ang->ang_z)) - (*y * sin(ang->ang_z));
	*y = (last_x * sin(ang->ang_z)) + (*y * cos(ang->ang_z));
}

void	pov_iso(t_ang *ang, int *x, int *y, int *z)
{
	int last_x;
	int last_y;

	if (ang->isom)
		return ;
	last_x = *x;
	last_y = *y;
	*x = (last_x - last_y) * cos(0.523599);
	*y = -(*z) + (last_x - last_y) * sin(0.523599);
}
