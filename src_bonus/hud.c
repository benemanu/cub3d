/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:43:44 by shoffman          #+#    #+#             */
/*   Updated: 2023/03/14 19:20:25 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/raycast_bonus.h"

void ft_load_img_healthbar(t_info *info, char *img)
{
	info->game.healthbar.img = mlx_xpm_file_to_image(info->mlx, img,
			&info->game.healthbar.dimensions.sprite_width, &info->game.healthbar.dimensions.sprite_height);
	info->game.healthbar.data = mlx_get_data_addr(info->game.healthbar.img,
			&info->game.healthbar.dimensions.s_bpp, &info->game.healthbar.size_l,
			&info->game.healthbar.endian);
	info->game.healthbar.dimensions.x_off = 20;
	info->game.healthbar.dimensions.y_off = 641;
}

void ft_load_img_hud_pistol(t_info *info, char *img)
{
	info->game.hud_pistol.img = mlx_xpm_file_to_image(info->mlx, img,
			&info->game.hud_pistol.dimensions.sprite_width, &info->game.hud_pistol.dimensions.sprite_height);
	info->game.hud_pistol.data = mlx_get_data_addr(info->game.hud_pistol.img,
			&info->game.hud_pistol.dimensions.s_bpp, &info->game.hud_pistol.size_l,
			&info->game.hud_pistol.endian);
	info->game.hud_pistol.dimensions.x_off = 20;
	info->game.hud_pistol.dimensions.y_off = 570;
}

void ft_draw_hud(t_info *info)
{
	ft_draw_sprite(info, info->game.healthbar.data, info->game.healthbar.size_l,
			&info->game.healthbar.dimensions);
	ft_draw_sprite(info, info->game.hud_pistol.data, info->game.hud_pistol.size_l,
			&info->game.hud_pistol.dimensions);
	ft_draw_ammo(info);
}