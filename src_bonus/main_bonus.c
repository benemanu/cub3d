/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:57:32 by shoffman          #+#    #+#             */
/*   Updated: 2023/03/16 14:14:10 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../inc_bonus/input_bonus.h"

void static	ft_init_struct(t_map *map)
{
	map->grid = NULL;
	map->north_t = NULL;
	map->south_t = NULL;
	map->west_t = NULL;
	map->east_t = NULL;
	map->error = 0;
	map->player_dir = 0;
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
		ft_main_raycast(&map);
	}
	return (0);
}
// ft_print_grid(map.grid);
