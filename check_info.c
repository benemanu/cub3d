#include "cub3D.h"

static int	ft_is_rgb(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (i > 3 || (ft_atoi(str) > 255 || ft_atoi(str) < 0))
		return (0);
	return (1);
}

static void	ft_check_and_save_color(t_map *map, int *array, char **strs)
{
	int		i;
	int		j;
	int		k;
	char	**temp;
	char	*temp_str;

	i = 0;
	k = 0;
	while (strs[++i])
	{
		j = -1;
		temp = ft_split(strs[i], ',');
		while (temp[++j])
		{
			temp_str = ft_strtrim(temp[j], " ");
			if (ft_is_rgb(temp_str) && k < 3)
				array[k++] = ft_atoi(temp_str);
			else
				map->error = COLOR;
			free(temp_str);
		}
		ft_free_split(temp);
	}
}

void	ft_check_and_save_info(t_map *map, char *str)
{
	char	**temp;
	char	*temp_str;

	temp_str = ft_strtrim(str, "\n");
	str = ft_strtrim(temp_str, " ");
	free(temp_str);
	temp = ft_split(str, ' ');
	free(str);
	if (strcmp(temp[0], "NO") == 0 && !temp[2] && map->north_t == NULL)
		map->north_t = ft_strdup(temp[1]);
	else if (strcmp(temp[0], "SO") == 0 && !temp[2] && map->south_t == NULL)
		map->south_t = ft_strdup(temp[1]);
	else if (strcmp(temp[0], "WE") == 0 && !temp[2] && map->west_t == NULL)
		map->west_t = ft_strdup(temp[1]);
	else if (strcmp(temp[0], "EA") == 0 && !temp[2] && map->east_t == NULL)
		map->east_t = ft_strdup(temp[1]);
	else if (strcmp(temp[0], "F") == 0 && map->floor_rgb[0] == 444)
		ft_check_and_save_color(map, map->floor_rgb, temp);
	else if (strcmp(temp[0], "C") == 0 && map->ceiling_rgb[0] == 444)
		ft_check_and_save_color(map, map->ceiling_rgb, temp);
	else if (map->error == 0)
		map->error = MAP_INFO;
	ft_free_split(temp);
}

int ft_check_texture_files(t_map *map)
{
	int fd;

	fd = open(map->north_t, O_RDONLY);
	if(fd >= 0)	
		close(fd);
	else
		return(map->error = TEXTURE);
	fd = open(map->south_t, O_RDONLY);
	if(fd >= 0)	
		close(fd);
	else
		return(map->error = TEXTURE);
	fd = open(map->west_t, O_RDONLY);
	if(fd >= 0)	
		close(fd);
	else
		return(map->error = TEXTURE);
	fd = open(map->east_t, O_RDONLY);
	if(fd >= 0)	
		close(fd);
	else
		return(map->error = TEXTURE);
	return (0);
}