#include "cub3D.h"

int	mapInfoFull(t_map *map)
{
	if (map->north_texture && map->south_texture && map->west_texture &&
		map->east_texture && map->tmp_floor_color && map->tmp_ceiling_color)
		return (1);
	return (0);
}

int	isFirstLine(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	checkIfEmpty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	freeSplit(char **strs)
{
	int i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}