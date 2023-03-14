/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_pistol_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:57:29 by shoffman          #+#    #+#             */
/*   Updated: 2023/03/14 16:57:30 by shoffman         ###   ########.fr       */
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
}

void	ft_load_img_pistol_1(t_info *info, char *img)
{
	info->game.pistol1.img = mlx_xpm_file_to_image(info->mlx, img,
			&info->game.pistol1.dimensions.sprite_height,
			&info->game.pistol1.dimensions.sprite_width);
	info->game.pistol1.data = mlx_get_data_addr(info->game.pistol1.img,
			&info->game.pistol1.dimensions.s_bpp, &info->game.pistol1.size_l,
			&info->game.pistol1.endian);
}

void	ft_load_img_pistol_2(t_info *info, char *img)
{
	info->game.pistol2.img = mlx_xpm_file_to_image(info->mlx, img,
			&info->game.pistol2.dimensions.sprite_height,
			&info->game.pistol2.dimensions.sprite_width);
	info->game.pistol2.data = mlx_get_data_addr(info->game.pistol2.img,
			&info->game.pistol2.dimensions.s_bpp, &info->game.pistol2.size_l,
			&info->game.pistol2.endian);
}

void	ft_load_img_pistol_3(t_info *info, char *img)
{
	info->game.pistol3.img = mlx_xpm_file_to_image(info->mlx, img,
			&info->game.pistol3.dimensions.sprite_height,
			&info->game.pistol3.dimensions.sprite_width);
	info->game.pistol3.data = mlx_get_data_addr(info->game.pistol3.img,
			&info->game.pistol3.dimensions.s_bpp, &info->game.pistol3.size_l,
			&info->game.pistol3.endian);
}
