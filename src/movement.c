/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:04:09 by shoffman          #+#    #+#             */
/*   Updated: 2023/03/14 17:04:10 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/raycast.h"

void	ft_move_forth_back(t_info *info)
{
	if (info->key.w == 1)
	{
		if (!(info->map->grid[(int)(info->ray.posx + (info->ray.dirx
						* info->ray.mov_speed * 2))]
			[(int)(info->ray.posy)] == '1'))
			info->ray.posx += info->ray.dirx * info->ray.mov_speed;
		if (!(info->map->grid[(int)(info->ray.posx)][(int)(info->ray.posy
			+ (info->ray.diry * info->ray.mov_speed * 2))] == '1'))
			info->ray.posy += info->ray.diry * info->ray.mov_speed;
	}
	if (info->key.s == 1)
	{
		if (!(info->map->grid[(int)(info->ray.posx - (info->ray.dirx
						* info->ray.mov_speed
						* 2))][(int)(info->ray.posy)] == '1'))
			info->ray.posx -= info->ray.dirx * info->ray.mov_speed;
		if (!(info->map->grid[(int)(info->ray.posx)][(int)(info->ray.posy
			- (info->ray.diry * info->ray.mov_speed * 2))] == '1'))
			info->ray.posy -= info->ray.diry * info->ray.mov_speed;
	}
}

void	ft_move_left_right(t_info *info)
{
	if (info->key.a == 1)
	{
		if (!(info->map->grid[(int)(info->ray.posx - info->ray.diry
					* (info->ray.horz_speed
						* 2))][(int)(info->ray.posy)] == '1'))
			info->ray.posx -= info->ray.diry * info->ray.horz_speed;
		if (!(info->map->grid[(int)(info->ray.posx)][(int)(info->ray.posy
			+ info->ray.dirx * (info->ray.horz_speed * 2))] == '1'))
			info->ray.posy += info->ray.dirx * info->ray.horz_speed;
	}
	if (info->key.d == 1)
	{
		if (!(info->map->grid[(int)(info->ray.posx + info->ray.diry
					* (info->ray.horz_speed
						* 2))][(int)(info->ray.posy)] == '1'))
			info->ray.posx += info->ray.diry * info->ray.horz_speed;
		if (!(info->map->grid[(int)(info->ray.posx)][(int)(info->ray.posy
			- info->ray.dirx * (info->ray.horz_speed * 2))] == '1'))
			info->ray.posy -= info->ray.dirx * info->ray.horz_speed;
	}
}

static void	ft_rotate_right(t_info *info)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = info->ray.dirx;
	old_planex = info->ray.planex;
	info->ray.dirx = info->ray.dirx * cos(-info->ray.rot_speed / 2)
		- info->ray.diry * sin(-info->ray.rot_speed / 2);
	info->ray.diry = old_dirx * sin(-info->ray.rot_speed / 2) + info->ray.diry
		* cos(-info->ray.rot_speed / 2);
	info->ray.planex = info->ray.planex * cos(-info->ray.rot_speed / 2)
		- info->ray.planey * sin(-info->ray.rot_speed / 2);
	info->ray.planey = old_planex * sin(-info->ray.rot_speed / 2)
		+ info->ray.planey * cos(-info->ray.rot_speed / 2);
}

void	ft_rotate(t_info *info)
{
	double	old_dirx;
	double	old_planex;

	if (info->key.left == 1)
	{
		old_dirx = info->ray.dirx;
		old_planex = info->ray.planex;
		info->ray.dirx = info->ray.dirx * cos(info->ray.rot_speed / 2)
			- info->ray.diry * sin(info->ray.rot_speed / 2);
		info->ray.diry = old_dirx * sin(info->ray.rot_speed / 2)
			+ info->ray.diry * cos(info->ray.rot_speed / 2);
		info->ray.planex = info->ray.planex * cos(info->ray.rot_speed / 2)
			- info->ray.planey * sin(info->ray.rot_speed / 2);
		info->ray.planey = old_planex * sin(info->ray.rot_speed / 2)
			+ info->ray.planey * cos(info->ray.rot_speed / 2);
	}
	if (info->key.right == 1)
		ft_rotate_right(info);
}
