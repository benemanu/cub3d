#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

#define MAP_INFO	1
#define UNDEFINED	2
#define COLOR		3
#define PLAYER		4
#define CHARACTER	5
#define EMPTY_LINE	6
#define WALLS		7
#define ALLOCATION	99

typedef struct s_map
{
	char			**grid;
	unsigned int	width;
	unsigned int	height;
	int 			error;
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	int				floor_rgb[3];
	int				ceiling_rgb[3];
	int				player_pos[2];
	char			player_dir;
}	t_map;

//error/exit/free
void freeMapStruct(t_map *map);

//file
void checkFile(t_map *map, char *filename);

//info
void checkAndSaveInfo(t_map *map, char *str);

//file_utils
int checkIfEmpty(char *str);
int isFirstLine(char *str);
void freeSplit(char **strs);
int mapInfoFull(t_map *map);

//grid
void parseGrid(t_map *map);
void checkFirstAndLastRow(t_map *map);

//grid_utils
void printGrid(char **grid);

#endif