/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:03:50 by shoffman          #+#    #+#             */
/*   Updated: 2023/03/14 17:03:51 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../inc/input.h"

static void	ft_set_player(t_map *map, int i, int j)
{
	if (map->player_dir == 0)
	{
		map->player_dir = map->grid[i][j];
		map->player_pos[0] = j;
		map->player_pos[1] = i;
	}
	else
		map->error = PLAYER;
}

static void	ft_check_walls(t_map *map, int x, int y)
{
	if ((map->grid[x + 1][y] == ' ' || !map->grid[x + 1][y])
	|| (map->grid[x - 1][y] == ' ' || !map->grid[x - 1][y])
	|| (map->grid[x][y + 1] == ' ' || !map->grid[x][y + 1])
	|| (map->grid[x][y - 1] == ' ' || !map->grid[x][y - 1]))
		map->error = WALLS;
}

void	ft_parse_grid(t_map *map)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	map->player_dir = 0;
	while (map->grid[i])
	{
		j = 0;
		while (CURR_P)
		{
			if (CURR_P == '0' || CURR_P == 'N'
				|| CURR_P == 'S' || CURR_P == 'E' || CURR_P == 'W')
				ft_check_walls(map, i, j);
			if (CURR_P == 'N' || CURR_P == 'S'
				|| CURR_P == 'E' || CURR_P == 'W')
				ft_set_player(map, i, j);
			if (CURR_P != '0' && CURR_P != '1' && CURR_P != 'N' && CURR_P != ' '
				&& CURR_P != 'S' && CURR_P != 'E' && CURR_P != 'W')
				map->error = CHARACTER;
			j++;
		}
		i++;
	}
	if (map->player_dir == 0)
		map->error = PLAYER;
}

void	ft_check_first_and_last_row(t_map *map)
{
	unsigned int	i;

	i = 0;
	while (map->grid[0][i])
	{
		if (map->grid[0][i] != ' ' && map->grid[0][i] != '1')
			map->error = WALLS;
		i++;
	}
	i = 0;
	while (map->grid[map->height - 1][i])
	{
		if (map->grid[map->height - 1][i] != ' ' && map->grid[map->height
			- 1][i] != '1')
			map->error = WALLS;
		i++;
	}
}

void	ft_print_grid(char **grid)
{
	int	i;

	i = 0;
	while (grid[i])
		printf("%s\n", grid[i++]);
}
