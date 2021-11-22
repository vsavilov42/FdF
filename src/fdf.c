#include <fdf.h>

void leaks()
{
	system("leaks fdf");
}

int main()
{
	t_fdf fdf;

	atexit(leaks);
	init_structs();
	mlx_loop(fdf.mlx);
	//init stuct
	//read file
	//save map, and color of every pixel
	//bresenham algorithm
	//readfile();

	return (0);
}
