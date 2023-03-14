/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pistol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:56:20 by shoffman          #+#    #+#             */
/*   Updated: 2023/03/14 16:57:49 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/raycast_bonus.h"

void	ft_draw_pistol(t_info *info, void *img_data, int size_line,
	t_sprite *sprite)
{
	int		x;
	int		y;
	int		color;
	char	*pixel;
	char	*line;

	pixel = img_data;
	x = 0;
	y = 0;
	while (y < sprite->sprite_height)
	{
		x = 0;
		while (x < sprite->sprite_width)
		{
			color = *(int *)(pixel + (y * size_line)
					+ (x * (sprite->s_bpp / 8)));
			if (color != -16777216)
				ft_my_mlx_pixel_put(info, x + 490, y + 420, color);
			x++;
		}
		y++;
	}
}

void	ft_shoot_pistol(t_info *info)
{
	static int	i = 0;

	if (i >= 0 && i < 15)
		ft_draw_pistol(info, info->game.pistol0.data, info->game.pistol0.size_l,
			&info->game.pistol0.dimensions);
	else if (i >= 15 && i < 30)
		ft_draw_pistol(info, info->game.pistol1.data, info->game.pistol1.size_l,
			&info->game.pistol1.dimensions);
	else if (i >= 30 && i < 45)
		ft_draw_pistol(info, info->game.pistol2.data, info->game.pistol2.size_l,
			&info->game.pistol2.dimensions);
	else if (i >= 45 && i < 60)
		ft_draw_pistol(info, info->game.pistol3.data, info->game.pistol3.size_l,
			&info->game.pistol3.dimensions);
	else if (i == 60)
	{
		i = 0;
		info->key.space = 0;
	}
	i++;
}
