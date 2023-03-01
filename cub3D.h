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
#define ALLOCATION	99


typedef struct s_map
{
	char			**grid;
	unsigned int	width;
	unsigned int	height;
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	char			*floor_color;
	char			*ceiling_color;
}	t_map;

//error/exit/free
void throwError(int code);

//file
void checkFile(t_map *map, char *filename);

//info
void checkAndSaveInfo(t_map *map, char *str);

//map_utils
void printGrid(char **grid);
int checkIfEmpty(char *str);

#endif