#include "cub3D.h"

static int isRGB(char **str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (0);
			j++;
		}
		if (j > 3 || (ft_atoi(str[i]) > 255 || ft_atoi(str[i]) < 0))
			return (0);
		i++;
	}
	return (1);
}

void checkAndSaveColor(int *array, char *str)
{
	int i;
	char **temp;

	i = 0;
	temp = ft_split(str, ',');
	while (temp[i])
	{
		temp[i] = ft_strtrim(temp[i], " ");
		temp[i] = ft_strtrim(temp[i], "\n");
		i++;
	}
	if(isRGB(temp) && i == 3)
	{
		i = -1;
		while(temp[++i])
			array[i] = ft_atoi(temp[i]);
	}
	else
	{
		freeSplit(temp);
		throwError(COLOR);
	}
	freeSplit(temp);
}

void checkAndSaveInfo(t_map *map, char *str)
{
	char **temp;

	temp = ft_split(str, ' ');
	if(strcmp(temp[0], "NO") == 0)
		map->north_texture = ft_strdup(temp[1]);
	else if(strcmp(temp[0], "SO") == 0)
		map->south_texture = ft_strdup(temp[1]);
	else if(strcmp(temp[0], "WE") == 0)
		map->west_texture = ft_strdup(temp[1]);
	else if(strcmp(temp[0], "EA") == 0)
		map->east_texture = ft_strdup(temp[1]);
	else if(strcmp(temp[0], "F") == 0)
		map->tmp_floor_color = ft_strdup(temp[1]);
	else if(strcmp(temp[0], "C") == 0)
		map->tmp_ceiling_color = ft_strdup(temp[1]);
	else
	{
		freeSplit(temp);
		throwError(MAP_INFO);
	}
	freeSplit(temp);
}

