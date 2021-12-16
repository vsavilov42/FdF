#include <fdf.h>

void leaks()
{
	system("leaks fdf");
}

int main(int argc, char **argv)
{
	t_fdf *fdf;

	if (argc != 2)
		return (tmarg());
	fdf = (t_fdf *)ft_calloc(1, (sizeof(t_fdf)));
	//atexit(leaks);
	init_structs(fdf);
	parse_map(fdf, argv[1]);
	mlx_start_img(fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
