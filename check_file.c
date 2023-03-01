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
					throwError(UNDEFINED);
				}
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
				throwError(EMPTY_LINE);
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
		throwError(ALLOCATION);
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
		throwError(CANNOT_OPEN);
	first_map_line = getMapInfo(map, fd);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		throwError(CANNOT_OPEN);
	measureMap(map, fd, first_map_line);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		throwError(CANNOT_OPEN);
	fillGrid(map, fd, first_map_line);
	close(fd);
}

void checkFile(t_map *map, char *filename)
{
	map->floor_rgb[0] = 444;
	map->ceiling_rgb[0] = 444;
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->west_texture = NULL;
	map->east_texture = NULL;

	if (ft_strcmp(&filename[ft_strlen(filename) - 4], ".cub"))
		throwError(FILE_ENDING);
	disectFile(map, filename);
	parseGrid(map);
}