#include "cub3D.h"

// static void splitInfo(t_map *map, char **strs)
// {

// }

void checkAndSaveInfo(t_map *map, char *str)
{
	char **temp;
	static int function_call = 1;

	temp = ft_split(str, " ");
	if(strcmp(temp[0], "NO") == 0 && function_call == 1)
		map->north_texture = ft_strdup(temp[1]);
	else if(strcmp(temp[0], "SO") == 0 && function_call == 2)
		map->south_texture = ft_strdup(temp[1]);
	else if(strcmp(temp[0], "WE") == 0 && function_call == 3)
		map->west_texture = ft_strdup(temp[1]);
	else if(strcmp(temp[0], "EA") == 0 && function_call == 4)
		map->east_texture = ft_strdup(temp[1]);
	else if(strcmp(temp[0], "F") == 0 && function_call == 5)
		map->floor_color = ft_strdup(temp[1]);
	else if(strcmp(temp[0], "C") == 0 && function_call == 6)
		map->ceiling_color = ft_strdup(temp[1]);
	function_call++;
}

