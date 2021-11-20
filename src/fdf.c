#include <fdf.h>

int main()
{
	t_map *map;
	t_fdf *fdf;	

	map = NULL;
	fdf = NULL;
	fdf->mlx = mlx_init();
	fdf->win  = mlx_new_window(fdf->mlx, 1920, 1080, "fdf");
	fdf->image = mlx_new_image(fdf->mlx, 1920, 1080);
	mlx_loop(fdf->mlx);
//init stuct
//read file
//save map, and color of every pixel
//bresenham algorithm

	//init_struct(&fdf);
	//readfile();

	return (0);
}
