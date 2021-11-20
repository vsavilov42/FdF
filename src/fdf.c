#include <fdf.h>

int main()
{
	t_map *map;
	t_fdf *fdf;	

	map = NULL;
	fdf = NULL;
	mlx = mlx_init();
	win  = mlx_new_window(mlx, 1920, 1080, "fdf");
	image = mlx_new_image(mlx, 1920, 1080);
	mlx_loop(mlx);
//init stuct
//read file
//save map, and color of every pixel
//bresenham algorithm

	//init_struct(&fdf);
	//readfile();

	return (0);
}
