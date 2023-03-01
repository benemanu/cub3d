#include "cub3D.h"

int main (int ac, char *argv[])
{
	t_map	map;

	if (ac != 2)
		printf("\033[1;31mInvalid amount of arguments.\033[0m\n");
	else
	{
		checkFile(&map, argv[1]);
		printGrid(map.grid);
	}
	return (0);
}

void throwError(int code)
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
	//free
	exit (0);
}
