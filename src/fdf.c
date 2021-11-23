#include <fdf.h>

void leaks()
{
	system("leaks fdf");
}

int main(int argc, char **argv)
{
	t_fdf fdf;
	
	if (argc != 2)
	{
		write(STDOUT_FILENO, "usage: ./fdf map.fdf\n", 21);
		return (1);
	}
	atexit(leaks);
	init_structs(&fdf);
	mlx_control_keys(&fdf);
	parse_map(&fdf, argv[1]);
//	mlx_key_hook(fdf.win, key_hook, &fdf);	
	mlx_loop(fdf.mlx);
	//init stuct
	//read file
	//save map, and color of every pixel
	//bresenham algorithm
	//readfile();

	return (0);
}
