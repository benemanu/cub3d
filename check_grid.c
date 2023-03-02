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
		map->error = PLAYER;
}

static void checkWalls(t_map *map, int x, int y) 
{
    if((map->grid[x + 1][y] == ' ' || !map->grid[x + 1][y]) 
	|| (map->grid[x - 1][y] == ' ' || !map->grid[x - 1][y])
	|| (map->grid[x][y + 1] == ' ' || !map->grid[x][y + 1]) 
	|| (map->grid[x][y - 1] == ' ' || !map->grid[x][y - 1]))
		map->error = WALLS;
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
			if (map->grid[i][j] == '0' || map->grid[i][j] == 'N' || map->grid[i][j] == 'S'
				|| map->grid[i][j] == 'E' || map->grid[i][j] == 'W')
				checkWalls(map, i, j);
			if (map->grid[i][j] == 'N' || map->grid[i][j] == 'S'
				|| map->grid[i][j] == 'E' || map->grid[i][j] == 'W')
				setPlayer(map, i, j);
			if (map->grid[i][j] != '0' && map->grid[i][j] != '1' && map->grid[i][j] != 'N' && map->grid[i][j] != ' '
				&& map->grid[i][j] != 'S' && map->grid[i][j] != 'E' && map->grid[i][j] != 'W')
				map->error = CHARACTER;
			j++;
		}
		i++;
	}
	if (map->player_dir == 0)
		map->error = PLAYER;
}

void checkFirstAndLastRow(t_map *map)
{
	unsigned int i;

	i = 0;
	while(map->grid[0][i])	
	{
		if (map->grid[0][i] != ' ' && map->grid[0][i] != '1')
			map->error = WALLS;
		i++;
	}
	i = 0;
	while(map->grid[map->height - 1][i])	
	{
		if (map->grid[map->height - 1][i] != ' ' && map->grid[map->height - 1][i] != '1')
			map->error = WALLS;
		i++;
	}
}

void printGrid(char **grid)
{
	int i;

	i = 0;
	while (grid[i])
		printf("%s\n", grid[i++]);
}