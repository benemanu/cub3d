#include "cub3D.h"

static int getMapInfo(t_map *map, int fd)
{
	char *line;
	int line_count;

	line = "";
	line_count = 1;
	while(line != NULL && line_count++)
	{
		line = get_next_line(fd);
		if(!checkIfEmpty(line))
		{
			if (mapInfoFull(map))
			{
				if(!isFirstLine(line))
				{
					free(line);
					while(line != NULL)
					{
						line = get_next_line(fd);
						free(line);
					}
					map->error = UNDEFINED;
				}
				free(line);
				while(line != NULL)
				{
					line = get_next_line(fd);
					free(line);
				}
				break;
			}
			checkAndSaveInfo(map, line);
		}
		free(line);
	}
	return (line_count - 2);
}

static void measureMap(t_map *map, int fd, int first_line)
{
	char	*line;

	line = "";
	map->height = 0;
	map->width = 0;
	while(first_line-- != 0)
	{
		line = get_next_line(fd);
		free(line);
	}
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			if (ft_strlen(line) > map->width)
				map->width = ft_strlen(line) - 1;
			map->height++;
			if(checkIfEmpty(line))
			{
				free(line);
				map->error = UNDEFINED;
			}
		}
		free(line);
	}
}

static void fillGrid(t_map *map, int fd, int first_line)
{
	int		i;
	char	*line;

	i = 0;
	line = "";
	map->grid = (char **)ft_calloc(map->height + 1, sizeof(char *));
	if (!map->grid)
		map->error = ALLOCATION;
	while(first_line-- != 0)
	{
		line = get_next_line(fd);
		free(line);
	}
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
			map->grid[i++] = ft_strtrim(line, "\n");
		free(line);
	}
}

static void disectFile(t_map *map, char *filename)
{	
	int fd;
	int first_map_line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(printf("\033[1;31mError.\nFile provided can't be opened.\033[0m\n"));
	first_map_line = getMapInfo(map, fd);
	close(fd);
	fd = open(filename, O_RDONLY);
	measureMap(map, fd, first_map_line);
	close(fd);
	fd = open(filename, O_RDONLY);
	fillGrid(map, fd, first_map_line);
	close(fd);
}

void checkFile(t_map *map, char *filename)
{
	map->floor_rgb[0] = 444;
	map->ceiling_rgb[0] = 444;
	if (ft_strcmp(&filename[ft_strlen(filename) - 4], ".cub"))
		exit(printf("\033[1;31mError.\nProvided argument, needs to be a .cub file.\033[0m\n"));
	disectFile(map, filename);
	checkFirstAndLastRow(map);
	parseGrid(map);
}