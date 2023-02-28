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
	//free
	exit (0);
}
