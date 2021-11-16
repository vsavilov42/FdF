#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_fdf
{

	t_xyz	*xyz;
}	t_fdf;

typedef struct s_map
{
	int	width;
	int	height;
	int *colors;
}	t_map;

typedef struct s_xyz
{
	int x;
	int y;
	int z;
	int color;
}	t_xyz;

//init structs

t_fdf	*init_fdf(t_fdf *fdf)

#endif
