#include "cub3D.h"

static void	ft_free_grid(t_map *map)
{
	int	i;

	i = 0;
	while (map->grid[i])
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
}

void	ft_free_map_struct(t_map *map)
{
	if (map->grid != NULL)
		ft_free_grid(map);
	if (map->north_t != NULL)
		free(map->north_t);
	if (map->south_t != NULL)
		free(map->south_t);
	if (map->west_t != NULL)
		free(map->west_t);
	if (map->east_t != NULL)
		free(map->east_t);
}

void	ft_throw_error(t_map *map, int code)
{
	if (code == ALLOCATION)
		printf("\033[1;31mError.\nAllocation failed.\033[0m\n");
	if (code == MAP_INFO)
		printf("\033[1;31mError.\nMap info is not correct.\033[0m\n");
	if (code == UNDEFINED)
		printf("\033[1;31mError.\nMap info or first line incorrect.\033[0m\n");
	if (code == COLOR)
		printf("\033[1;31mError.\nThe RGB information is not correct.\033[0m\n");
	if (code == PLAYER)
		printf("\033[1;31mError.\nPlayer is missing or too many players.\033[0m\n");
	if (code == CHARACTER)
		printf("\033[1;31mError.\nThe map contains an invalid character.\033[0m\n");
	if (code == EMPTY_LINE)
		printf("\033[1;31mError.\nThe map contains an empty line.\033[0m\n");
	if (code == WALLS)
		printf("\033[1;31mError.\nThe map is not surrounded by walls.\033[0m\n");
	if (code == ENDING)
		printf("\033[1;31mError.\nThe file does not have a .cub ending.\033[0m\n");
	if (code == CANNOT_OPEN)
		printf("\033[1;31mError.\nThe file provided cannot be opened.\033[0m\n");
	ft_free_map_struct(map);
	exit(0);
}
