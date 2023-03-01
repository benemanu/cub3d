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
#define MAP_INFO	2
#define UNDEFINED	3
#define COLOR		4
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
	char			*tmp_floor_color;
	char			*tmp_ceiling_color;
	int				floor_rgb[3];
	int				ceiling_rgb[3];
}	t_map;

//error/exit/free
void throwError(int code);

//file
void checkFile(t_map *map, char *filename);

//info
void checkAndSaveInfo(t_map *map, char *str);
void checkAndSaveColor(int *array, char *str);

//file_utils
int checkIfEmpty(char *str);
int isFirstLine(char *str);
void freeSplit(char **strs);
int mapInfoFull(t_map *map);

//grid_utils
void printGrid(char **grid);

#endif