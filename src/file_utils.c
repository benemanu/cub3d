/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:03:56 by shoffman          #+#    #+#             */
/*   Updated: 2023/03/14 17:03:57 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../inc/input.h"

int	ft_map_info_full(t_map *map)
{
	if (map->north_t && map->south_t && map->west_t && map->east_t
		&& map->floor_rgb[0] != 444 && map->ceiling_rgb[0] != 444)
		return (1);
	return (0);
}

int	ft_is_first_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_if_empty(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] != ' ' && str[i] != '\n')
				return (0);
			i++;
		}
	}
	return (1);
}

void	ft_free_split(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}
