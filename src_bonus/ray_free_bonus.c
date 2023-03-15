/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_free_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:57:51 by shoffman          #+#    #+#             */
/*   Updated: 2023/03/15 10:22:14 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/raycast_bonus.h"

static void	ft_free_images(t_info *info)
{
	if (info->game.game.img)
		mlx_destroy_image(info->mlx, info->game.game.img);
	if (info->game.north.img)
		mlx_destroy_image(info->mlx, info->game.north.img);
	if (info->game.south.img)
		mlx_destroy_image(info->mlx, info->game.south.img);
	if (info->game.west.img)
		mlx_destroy_image(info->mlx, info->game.west.img);
	if (info->game.east.img)
		mlx_destroy_image(info->mlx, info->game.east.img);
	if (info->game.pistol0.img)
		mlx_destroy_image(info->mlx, info->game.pistol0.img);
	if (info->game.pistol1.img)
		mlx_destroy_image(info->mlx, info->game.pistol1.img);
	if (info->game.pistol2.img)
		mlx_destroy_image(info->mlx, info->game.pistol2.img);
	if (info->game.pistol3.img)
		mlx_destroy_image(info->mlx, info->game.pistol3.img);
	if (info->game.healthbar.img)
		mlx_destroy_image(info->mlx, info->game.healthbar.img);
	if (info->game.hud_pistol.img)
		mlx_destroy_image(info->mlx, info->game.hud_pistol.img);
	if (info->game.ammo_empty.img)
		mlx_destroy_image(info->mlx, info->game.ammo_empty.img);
	if (info->game.ammo_full.img)
		mlx_destroy_image(info->mlx, info->game.ammo_full.img);
	if (info->game.reload.img)
		mlx_destroy_image(info->mlx, info->game.reload.img);
	if (info->win && info->mlx)
		mlx_destroy_window(info->mlx, info->win);
	if (info->mlx)
		mlx_destroy_display(info->mlx);
	if (info->mlx)
		free(info->mlx);
}

void	ft_ray_free(t_info *info, t_map *map)
{
	ft_free_map_struct(map);
	ft_free_images(info);
	exit(0);
}
