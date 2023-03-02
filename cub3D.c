#include "cub3D.h"

void static initStruct(t_map *map)
{
	map->grid = NULL;
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->west_texture = NULL;
	map->east_texture = NULL;
	map->error = -1;
}

static void printError(t_map *map, int code)
{
	if(code == FILE_ENDING)
		printf("\033[1;31mProvided argument, needs to be a .cub file.\033[0m\n");
	if(code == CANNOT_OPEN)
		printf("\033[1;31mFile provided can't be opened.\033[0m\n");
	if(code == ALLOCATION)
		printf("\033[1;31mAllocation failed.\033[0m\n");
	if(code == MAP_INFO)
		printf("\033[1;31mThe map information is not correct.\033[0m\n");
	if(code == UNDEFINED)
		printf("\033[1;31mThe map information or the map itself is not correct.\033[0m\n");
	if(code == COLOR)
		printf("\033[1;31mThe RGB information is not correct.\033[0m\n");
	if(code == PLAYER)	
		printf("\033[1;31mPlayer is missing or too many players.\033[0m\n");
	if(code == CHARACTER)
		printf("\033[1;31mThe map contains an invalid character.\033[0m\n");
	if(code == EMPTY_LINE)
		printf("\033[1;31mThe map contains an empy line.\033[0m\n");
	if(code == WALLS)
		printf("\033[1;31mThe map is not surrounded by walls.\033[0m\n");
	freeMapStruct(map);
	exit (1);
}

int main (int ac, char *argv[])
{
	t_map	map;

	if (ac != 2)
		return (printf("\033[1;31mError.\nInvalid amount of arguments.\033[0m\n"));
	else
	{
		initStruct(&map);
		checkFile(&map, argv[1]);
		if(map.error != -1)
			printError(&map, map.error);
		printGrid(map.grid);
	}
	freeMapStruct(&map);
	return (0);
}

