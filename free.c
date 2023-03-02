#include "cub3D.h"

static void freeGrid(t_map *map)
{
	int i;

	i = 0;
	while(map->grid[i])
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
}

void freeMapStruct(t_map *map)
{
	if(map->grid != NULL)
		freeGrid(map);
	if(map->north_texture != NULL)
		free(map->north_texture);
	if(map->south_texture != NULL)
		free(map->south_texture);
	if(map->west_texture != NULL)
		free(map->west_texture);
	if(map->east_texture != NULL)
		free(map->east_texture);
}