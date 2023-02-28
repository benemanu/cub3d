#include "cub3D.h"

static void parseMap(t_map *map, int fd)
{

}

void checkFile(t_map *map, char *filename)
{
	int		fd;

	if (ft_strcmp(&filename[ft_strlen(filename) - 4], ".cub"))
		throwError(FILE_ENDING);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		throwError(CANNOT_OPEN);
	parseMap(map, fd);
	close(fd);
	(void)map;
}