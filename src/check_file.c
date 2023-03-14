/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:03:43 by shoffman          #+#    #+#             */
/*   Updated: 2023/03/14 17:03:44 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../inc/input.h"

static int	ft_get_map_info(t_map *map, int fd)
{
	char	*line;
	int		line_count;
	int		return_count;

	line = "";
	line_count = 1;
	return_count = 0;
	while (line != NULL && line_count++)
	{
		line = get_next_line(fd);
		if (!ft_check_if_empty(line) && return_count == 0)
		{
			if (ft_map_info_full(map))
			{
				if (!ft_is_first_line(line))
					map->error = UNDEFINED;
				return_count = line_count;
			}
			if (return_count == 0)
				ft_check_and_save_info(map, line);
		}
		free(line);
	}
	return (return_count - 2);
}

static void	ft_measure_map(t_map *map, int fd, int first_line)
{
	char	*line;

	line = "";
	map->height = 0;
	map->width = 0;
	while (first_line-- != 0)
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
			if (ft_check_if_empty(line))
			{
				map->error = EMPTY_LINE;
			}
		}
		free(line);
	}
}

static void	ft_fill_grid(t_map *map, int fd, int first_line)
{
	int		i;
	char	*line;

	i = 0;
	line = "";
	map->grid = (char **)ft_calloc(map->height + 1, sizeof(char *));
	if (!map->grid)
		map->error = ALLOCATION;
	while (first_line-- != 0)
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

static void	ft_disect_file(t_map *map, char *filename)
{
	int	fd;
	int	first_map_line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_throw_error(map, CANNOT_OPEN);
	first_map_line = ft_get_map_info(map, fd);
	close(fd);
	if (map->error != 0)
		ft_throw_error(map, map->error);
	fd = open(filename, O_RDONLY);
	if (map->error != 0)
		ft_throw_error(map, map->error);
	ft_measure_map(map, fd, first_map_line);
	close(fd);
	if (map->error != 0)
		ft_throw_error(map, map->error);
	fd = open(filename, O_RDONLY);
	ft_fill_grid(map, fd, first_map_line);
	close(fd);
}

void	ft_check_file(t_map *map, char *filename)
{
	map->floor_rgb[0] = 444;
	map->ceiling_rgb[0] = 444;
	if (ft_strcmp(&filename[ft_strlen(filename) - 4], ".cub"))
		ft_throw_error(map, ENDING);
	ft_disect_file(map, filename);
	if (map->error != 0)
		ft_throw_error(map, map->error);
	ft_check_texture_files(map);
	if (map->error != 0)
		ft_throw_error(map, map->error);
	ft_check_first_and_last_row(map);
	if (map->error != 0)
		ft_throw_error(map, map->error);
	ft_parse_grid(map);
	if (map->error != 0)
		ft_throw_error(map, map->error);
}
