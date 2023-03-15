/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ammo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:04:44 by shoffman          #+#    #+#             */
/*   Updated: 2023/03/15 09:51:10 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/raycast_bonus.h"

void ft_load_img_ammo_full(t_info *info, char *img)
{
	info->game.ammo_full.img = mlx_xpm_file_to_image(info->mlx, img,
			&info->game.ammo_full.dimensions.sprite_width, &info->game.ammo_full.dimensions.sprite_height);
	info->game.ammo_full.data = mlx_get_data_addr(info->game.ammo_full.img,
			&info->game.ammo_full.dimensions.s_bpp, &info->game.ammo_full.size_l,
			&info->game.ammo_full.endian);
	info->game.ammo_full.dimensions.x_off = 108;
	info->game.ammo_full.dimensions.y_off = 570;
}

void ft_load_img_ammo_empty(t_info *info, char *img)
{
	info->game.ammo_empty.img = mlx_xpm_file_to_image(info->mlx, img,
			&info->game.ammo_empty.dimensions.sprite_width, &info->game.ammo_empty.dimensions.sprite_height);
	info->game.ammo_empty.data = mlx_get_data_addr(info->game.ammo_empty.img,
			&info->game.ammo_empty.dimensions.s_bpp, &info->game.ammo_empty.size_l,
			&info->game.ammo_empty.endian);
	info->game.ammo_empty.dimensions.x_off = 108;
	info->game.ammo_empty.dimensions.y_off = 570;
}

void ft_draw_ammo(t_info *info)
{
	int i;
	int tmp;

	i = 0;
	tmp = info->shots_left;
	while (i < 5)
	{
		if(tmp > 0)
			ft_draw_sprite(info, info->game.ammo_full.data, info->game.ammo_full.size_l,
				&info->game.ammo_full.dimensions);
		else
			ft_draw_sprite(info, info->game.ammo_empty.data, info->game.ammo_empty.size_l,
				&info->game.ammo_empty.dimensions);
		info->game.ammo_full.dimensions.x_off += 30;
		info->game.ammo_empty.dimensions.x_off += 30;
		i++;
		tmp--;
	}
	info->game.ammo_full.dimensions.x_off = 108;
	info->game.ammo_empty.dimensions.x_off = 108;
	//if R shots_left = 0
}