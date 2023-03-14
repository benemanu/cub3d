/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:56:20 by shoffman          #+#    #+#             */
/*   Updated: 2023/03/14 17:58:43 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/raycast_bonus.h"

void	ft_draw_sprite(t_info *info, void *img_data, int size_line,
	t_sprite *sprite)
{
	int		x;
	int		y;
	int		color;
	char	*pixel;

	pixel = img_data;
	y = 0;
	while (y < sprite->sprite_height)
	{
		x = 0;
		while (x < sprite->sprite_width)
		{
			color = *(int *)(pixel + (y * size_line)
					+ (x * (sprite->s_bpp / 8)));
			if (color != -16777216)
				ft_my_mlx_pixel_put(info, x + sprite->x_off, y + sprite->y_off, color);
			x++;
		}
		y++;
	}
}
