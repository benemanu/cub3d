#include "cub3D.h"

void printGrid(char **grid)
{
	int i;

	i = 0;
	while (grid[i])
		printf("%s\n", grid[i++]);
}