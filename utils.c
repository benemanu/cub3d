#include "cub3D.h"

void printGrid(char **grid)
{
	int i;

	i = 0;
	while (grid[i])
		printf("%s\n", grid[i++]);
}

int checkIfEmpty(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] != ' ' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}