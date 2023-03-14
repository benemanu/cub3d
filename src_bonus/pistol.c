/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pistol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:57:29 by shoffman          #+#    #+#             */
/*   Updated: 2023/03/14 17:55:33 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/raycast_bonus.h"

void	ft_load_img_pistol_0(t_info *info, char *img)
{
	info->game.pistol0.img = mlx_xpm_file_to_image(info->mlx, img,
			&info->game.pistol0.dimensions.sprite_height,
			&info->game.pistol0.dimensions.sprite_width);
	info->game.pistol0.data = mlx_get_data_addr(info->game.pistol0.img,
			&info->game.pistol0.dimensions.s_bpp, &info->game.pistol0.size_l,
			&info->game.pistol0.endian);
	info->game.pistol0.dimensions.x_off = 490;
	info->game.pistol0.dimensions.y_off = 420;
}

void	ft_load_img_pistol_1(t_info *info, char *img)
{
	info->game.pistol1.img = mlx_xpm_file_to_image(info->mlx, img,
			&info->game.pistol1.dimensions.sprite_height,
			&info->game.pistol1.dimensions.sprite_width);
	info->game.pistol1.data = mlx_get_data_addr(info->game.pistol1.img,
			&info->game.pistol1.dimensions.s_bpp, &info->game.pistol1.size_l,
			&info->game.pistol1.endian);
	info->game.pistol1.dimensions.x_off = 490;
	info->game.pistol1.dimensions.y_off = 420;
}

void	ft_load_img_pistol_2(t_info *info, char *img)
{
	info->game.pistol2.img = mlx_xpm_file_to_image(info->mlx, img,
			&info->game.pistol2.dimensions.sprite_height,
			&info->game.pistol2.dimensions.sprite_width);
	info->game.pistol2.data = mlx_get_data_addr(info->game.pistol2.img,
			&info->game.pistol2.dimensions.s_bpp, &info->game.pistol2.size_l,
			&info->game.pistol2.endian);
	info->game.pistol2.dimensions.x_off = 490;
	info->game.pistol2.dimensions.y_off = 420;
}

void	ft_load_img_pistol_3(t_info *info, char *img)
{
	info->game.pistol3.img = mlx_xpm_file_to_image(info->mlx, img,
			&info->game.pistol3.dimensions.sprite_height,
			&info->game.pistol3.dimensions.sprite_width);
	info->game.pistol3.data = mlx_get_data_addr(info->game.pistol3.img,
			&info->game.pistol3.dimensions.s_bpp, &info->game.pistol3.size_l,
			&info->game.pistol3.endian);
	info->game.pistol3.dimensions.x_off = 490;
	info->game.pistol3.dimensions.y_off = 420;
}

void	ft_shoot_pistol(t_info *info)
{
	static int	i = 0;

	if (i >= 0 && i < 15)
		ft_draw_sprite(info, info->game.pistol0.data, info->game.pistol0.size_l,
			&info->game.pistol0.dimensions);
	else if (i >= 15 && i < 30)
		ft_draw_sprite(info, info->game.pistol1.data, info->game.pistol1.size_l,
			&info->game.pistol1.dimensions);
	else if (i >= 30 && i < 45)
		ft_draw_sprite(info, info->game.pistol2.data, info->game.pistol2.size_l,
			&info->game.pistol2.dimensions);
	else if (i >= 45 && i < 60)
		ft_draw_sprite(info, info->game.pistol3.data, info->game.pistol3.size_l,
			&info->game.pistol3.dimensions);
	else if (i == 60)
	{
		i = 0;
		info->key.space = 0;
	}
	i++;
}
