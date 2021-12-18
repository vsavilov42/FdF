#include <fdf.h>

int	tmarg(void)
{
	write(STDOUT_FILENO, "usage ./fdf map.fdf\n", 21);
	return (1);
}

int invmap(void)
{
	perror("Invalid map");
	return (1);
}

int emap(void)
{
	perror("Empty map");
	return (1);
}

int eang(void)
{
	perror("Error struct initialization");
	return (1);
}
