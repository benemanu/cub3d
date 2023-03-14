/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:03:13 by shoffman          #+#    #+#             */
/*   Updated: 2023/03/14 17:03:13 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/raycast.h"

static void	ft_ray_init2(t_info *info)
{
	if (info->ray.raydiry == 0)
		info->ray.deltadistx = 0;
	else if (info->ray.raydirx == 0)
		info->ray.deltadistx = 1;
	else
		info->ray.deltadistx = sqrt(1 + (info->ray.raydiry * info->ray.raydiry)
				/ (info->ray.raydirx * info->ray.raydirx));
	if (info->ray.raydirx == 0)
		info->ray.deltadisty = 0;
	else if (info->ray.raydiry == 0)
		info->ray.deltadisty = 1;
	else
		info->ray.deltadisty = sqrt(1 + (info->ray.raydirx * info->ray.raydirx)
				/ (info->ray.raydiry * info->ray.raydiry));
}

void	ft_ray_init(t_info *info)
{
	info->ray.hit = 0;
	info->ray.perpwalldist = 0;
	info->ray.camerax = 2 * info->ray.x / (double)WIDTH - 1;
	info->ray.raydirx = info->ray.dirx + info->ray.planex * info->ray.camerax;
	info->ray.raydiry = info->ray.diry + info->ray.planey * info->ray.camerax;
	info->ray.mapx = (int)info->ray.posx;
	info->ray.mapy = (int)info->ray.posy;
	info->ray.mov_speed = 0.075;
	info->ray.horz_speed = 0.0375;
	info->ray.rot_speed = 0.033 * 1.6;
	ft_ray_init2(info);
}

void	ft_calc_pixel(t_info *info)
{
	if (info->ray.side == 0)
		info->ray.wallx = info->ray.posy + info->ray.perpwalldist
			* info->ray.raydiry;
	else
		info->ray.wallx = info->ray.posx + info->ray.perpwalldist
			* info->ray.raydirx;
	info->ray.wallx -= floor((info->ray.wallx));
	info->ray.texx = (int)(info->ray.wallx * (double)64);
	if (info->ray.side == 0 && info->ray.raydirx > 0)
		info->ray.texx = 64 - info->ray.texx - 1;
	if (info->ray.side == 1 && info->ray.raydiry < 0)
		info->ray.texx = 64 - info->ray.texx - 1;
	info->ray.step = 1.0 * 64 / info->ray.lineheight;
	info->ray.texpos = (info->ray.drawstart - HEIGHT / 2 + info->ray.lineheight
			/ 2) * info->ray.step;
	ft_draw(info->ray.drawstart, info->ray.drawend, info);
}

int	ft_get_color(t_info *info, int ind)
{
	if (ind == 1)
		return (*(int *)(info->game.south.data + (info->ray.texx
				* (info->game.south.bpp / 8) + info->ray.texy
				* info->game.south.size_l)));
	if (ind == 2)
		return (*(int *)(info->game.north.data + (info->ray.texx
				* (info->game.north.bpp / 8) + info->ray.texy
				* info->game.north.size_l)));
	if (ind == 3)
		return (*(int *)(info->game.east.data + (info->ray.texx
				* (info->game.east.bpp / 8) + info->ray.texy
				* info->game.east.size_l)));
	if (ind == 4)
		return (*(int *)(info->game.west.data + (info->ray.texx
				* (info->game.west.bpp / 8) + info->ray.texy
				* info->game.west.size_l)));
	return (0);
}
