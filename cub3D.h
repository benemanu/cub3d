#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

#define FILE_ENDING 0
#define CANNOT_OPEN 1
#define ALLOCATION 2

typedef struct s_map
{
	char	**grid;
}			t_map;

//error/exit/free
void throwError(int code);
void    main_raycast(t_map *map);

//map
void checkFile(t_map *map, char *filename);

#endif