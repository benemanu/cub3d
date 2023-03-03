#include "cub3D.h"

void static	ft_init_struct(t_map *map)
{
	map->grid = NULL;
	map->north_t = NULL;
	map->south_t = NULL;
	map->west_t = NULL;
	map->east_t = NULL;
	map->error = 0;
}

int	main(int ac, char *argv[])
{
	t_map	map;

	if (ac != 2)
		return (printf("\033[1;31mError.\nInvalid amount of arguments.\033[0m\n"));
	else
	{
		ft_init_struct(&map);
		ft_check_file(&map, argv[1]);
		ft_print_grid(map.grid);
        main_raycast(&map);
	}
	ft_free_map_struct(&map);
	return (0);
}
