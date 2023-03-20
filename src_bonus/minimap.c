/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:57:42 by shoffman          #+#    #+#             */
/*   Updated: 2023/03/14 16:57:43 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/raycast_bonus.h"

static void	ft_draw_border(t_info *info)
{
	int	i;
	int	j;

	i = 20;
	while (i <= 134)
	{
		j = 20;
		while (j <= 134)
		{
			if (((j == 21 || j == 22 || j == 133 || j == 134)
					&& (i != 20 && i != 134))
				|| ((i == 21 || i == 22 || i == 133 || i == 134)
					&& (j != 20 && j != 134)))
				ft_my_mlx_pixel_put(info, i, j, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

static void	ft_draw_square(int x, int y, int color, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			ft_my_mlx_pixel_put(info, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

static int	ft_check_is_outside(t_info *info, int x_off, int y_off)
{
	if ((int)info->ray.posx + x_off < 0
		|| (int)info->ray.posx + x_off > (int)info->map->height - 1
		|| (int)info->ray.posy + y_off < 0
		|| (int)info->ray.posy + y_off
		> (int)ft_strlen(info->map->grid[(int)info->ray.posx + x_off])
		|| info->map->grid[(int)info->ray.posx + x_off]
		[(int)info->ray.posy + y_off] == ' '
		|| info->map->grid[(int)info->ray.posx + x_off]
		[(int)info->ray.posy + y_off] == '\0')
		return (1);
	return (0);
}

static void	ft_draw_current_map(t_info *info)
{
	int	x_offset;
	int	y_offset;
	int	next_square_x;
	int	next_square_y;

	y_offset = -6;
	next_square_y = 23;
	while (++y_offset < 6)
	{
		x_offset = -6;
		next_square_x = 23;
		while (++x_offset < 6)
		{
			if (ft_check_is_outside(info, x_offset, y_offset))
				ft_draw_square(next_square_y, next_square_x, 0x000000, info);
			else if (info->map->grid[(int)info->ray.posx + x_offset]
				[(int)info->ray.posy + y_offset] == '1')
				ft_draw_square(next_square_y, next_square_x, 0x8a8a8a, info);
			else
				ft_draw_square(next_square_y, next_square_x, 0xd3d3d3, info);
			next_square_x += 10;
		}
		next_square_y += 10;
	}
}

void	ft_draw_minimap(t_info *info)
{
	ft_draw_border(info);
	ft_draw_current_map(info);
    ft_draw_square(73, 73, 0xFF0000, info);
}
