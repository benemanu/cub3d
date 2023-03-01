#include "cub3D.h"

static int isRGB(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i > 3 || (ft_atoi(str) > 255 || ft_atoi(str) < 0))
			return (0);
	return (1);
}

static int checkAndSaveColor(int *array, char **strs)
{
	int i;
	int j;
	int k = 0;
	char **temp;

	i = 1;
	while(strs[i])
	{
		j = 0;
		temp = ft_split(strs[i], ',');
		while(temp[j])
		{
			temp[j] = ft_strtrim(temp[j], " ");
			if(isRGB(temp[j]) && k < 3)
			{
				array[k] = ft_atoi(temp[j]);
				k++;
				j++;
			}
			else
			{
				freeSplit(temp);
				return (0);
			}
		}
		i++;
	}
	freeSplit(temp);
	return (1);
}

void checkAndSaveInfo(t_map *map, char *str)
{
	char **temp;

	str = ft_strtrim(str, "\n");
	str = ft_strtrim(str, " ");
	temp = ft_split(str, ' ');
	if(strcmp(temp[0], "NO") == 0 && !temp[2] && map->north_texture == NULL)
		map->north_texture = ft_strdup(temp[1]);
	else if(strcmp(temp[0], "SO") == 0 && !temp[2] && map->south_texture == NULL)
		map->south_texture = ft_strdup(temp[1]);
	else if(strcmp(temp[0], "WE") == 0 && !temp[2] && map->west_texture == NULL)
		map->west_texture = ft_strdup(temp[1]);
	else if(strcmp(temp[0], "EA") == 0 && !temp[2] && map->east_texture == NULL)
		map->east_texture = ft_strdup(temp[1]);
	else if(strcmp(temp[0], "F") == 0 && map->floor_rgb[0] == 444)
	{
		if (!checkAndSaveColor(map->floor_rgb, temp))
		{
			freeSplit(temp);
			throwError(COLOR);
		}
	}
	else if(strcmp(temp[0], "C") == 0 && map->ceiling_rgb[0] == 444)
	{
		if (!checkAndSaveColor(map->ceiling_rgb, temp))
		{
			freeSplit(temp);
			throwError(COLOR);
		}
	}
	else
	{
		freeSplit(temp);
		throwError(MAP_INFO);
	}
	freeSplit(temp);
}

