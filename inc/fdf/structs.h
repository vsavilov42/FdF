#ifndef STRUCTS_H
# define STRUCTS_H

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

#endif
