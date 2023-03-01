#include "cub3D.h"

static void	setPlayer(t_map *map, int i, int j)
{
	if (map->player_dir == 0)
	{
		map->player_dir = map->grid[i][j];
		map->player_pos[0] = j;
		map->player_pos[1] = i;
	}
	else
		throwError(PLAYER);
}

void	parseGrid(t_map *map)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	map->player_dir = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == 'N' || map->grid[i][j] == 'S'
				|| map->grid[i][j] == 'E' || map->grid[i][j] == 'W')
				setPlayer(map, i, j);
			if (map->grid[i][j] != '0' && map->grid[i][j] != '1' && map->grid[i][j] != 'N' && map->grid[i][j] != ' '
				&& map->grid[i][j] != 'S' && map->grid[i][j] != 'E' && map->grid[i][j] != 'W')
				throwError(CHARACTER);
			j++;
		}
		i++;
	}
	if (map->player_dir == 0)
		throwError(PLAYER);
}