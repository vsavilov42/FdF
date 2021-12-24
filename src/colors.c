#include <fdf.h>

static int bright(int first, int last, int perc)
{
	return ((int)(1 - perc) * first + perc * last);
}

static double get_percent(int now, int first, int last)
{
	double f_pix;
	double lt_pix;

	f_pix = now - first;
	lt_pix = last - first;
	if (!lt_pix)
		return (1);
	return (f_pix / lt_pix);
}

int colorxy(t_xyz now, t_xyz first, t_xyz last, t_xyz tmp)
{
	int r;
	int g;
	int b;	
	double perc;

	if (now.color == last.color)
		return (now.color);
	if (tmp.x > tmp.y)
		perc = get_percent(now.x, first.x, last.x);
	else
		perc = get_percent(now.y, first.y, last.y);
	r = bright((first.color >> 16) & 0xFF, (last.color >> 16) & 0xFF, perc);
	g = bright((first.color >> 8) & 0xFF, (last.color >> 8) & 0xFF, perc);
	b = bright(first.color & 0xFF, last.color & 0xFF, perc);
	return ((r << 16) | (g << 8) | b);
}

int colorz(t_fdf *fdf, int z)
{
	double perc;

	perc = get_percent(z, fdf->map.min_z, fdf->map.max_z);
	if (perc < 0.2)
		return (LIGHT_BLUE);
	else if (perc < 0.4)
		return (AQUAMARINE);
	else if (perc < 0.6)
		return (BLUE);
	else if (perc < 0.8)
		return (BLUE_GREEN);
	else
		return (DARK_BLUE);
}
