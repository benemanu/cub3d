/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:56:26 by shoffman          #+#    #+#             */
/*   Updated: 2023/03/14 18:29:10 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/raycast_bonus.h"

static void	ft_drawing(t_info *info)
{
	while (info->ray.drawstart < info->ray.drawend)
	{
		info->ray.texy = (int)info->ray.texpos & (64 - 1);
		info->ray.texpos += info->ray.step;
		if (info->ray.side == 0)
		{
			if (info->ray.raydirx > 0)
				info->ray.color = ft_get_color(info, 1);
			else
				info->ray.color = ft_get_color(info, 2);
		}
		else
		{
			if (info->ray.raydiry > 0)
				info->ray.color = ft_get_color(info, 3);
			else
				info->ray.color = ft_get_color(info, 4);
		}
		ft_my_mlx_pixel_put(info, info->ray.x, info->ray.drawstart,
			info->ray.color);
		info->ray.drawstart++;
	}
}

static void	ft_calc_dist(t_info *info)
{
	if (info->ray.side == 0)
		info->ray.perpwalldist = ((double)info->ray.mapx - info->ray.posx + (1
					- (double)info->ray.stepx) / 2) / info->ray.raydirx;
	else
		info->ray.perpwalldist = ((double)info->ray.mapy - info->ray.posy + (1
					- (double)info->ray.stepy) / 2) / info->ray.raydiry;
	info->ray.lineheight = (int)(HEIGHT / info->ray.perpwalldist);
	info->ray.drawstart = -info->ray.lineheight / 2 + HEIGHT / 2;
	if (info->ray.drawstart < 0)
		info->ray.drawstart = 0;
	info->ray.drawend = info->ray.lineheight / 2 + HEIGHT / 2;
	if (info->ray.drawend >= HEIGHT)
		info->ray.drawend = HEIGHT - 1;
}

static void	ft_get_side(t_info *info)
{
	while (info->ray.hit == 0)
	{
		if (info->ray.sidedistx < info->ray.sidedisty)
		{
			info->ray.sidedistx += info->ray.deltadistx;
			info->ray.mapx += info->ray.stepx;
			info->ray.side = 0;
		}
		else
		{
			info->ray.sidedisty += info->ray.deltadisty;
			info->ray.mapy += info->ray.stepy;
			info->ray.side = 1;
		}
		if (info->map->grid[info->ray.mapx][info->ray.mapy] == '1')
			info->ray.hit = 1;
	}
	ft_calc_dist(info);
}

static void	ft_get_direction(t_info *info)
{
	if (info->ray.raydirx < 0)
	{
		info->ray.stepx = -1;
		info->ray.sidedistx = (info->ray.posx - info->ray.mapx)
			* info->ray.deltadistx;
	}
	else
	{
		info->ray.stepx = 1;
		info->ray.sidedistx = (info->ray.mapx + 1.0 - info->ray.posx)
			* info->ray.deltadistx;
	}
	if (info->ray.raydiry < 0)
	{
		info->ray.stepy = -1;
		info->ray.sidedisty = (info->ray.posy - info->ray.mapy)
			* info->ray.deltadisty;
	}
	else
	{
		info->ray.stepy = 1;
		info->ray.sidedisty = (info->ray.mapy + 1.0 - info->ray.posy)
			* info->ray.deltadisty;
	}
	ft_get_side(info);
}

int	ft_main_calc(t_info *info)
{
	info->ray.x = -1;
	while (++info->ray.x < WIDTH)
	{
		ft_ray_init(info);
		ft_get_direction(info);
		ft_calc_pixel(info);
		ft_drawing(info);
	}
	mlx_clear_window(info->mlx, info->win);
	mlx_put_image_to_window(info->mlx, info->win, info->game.game.img, 0, 0);
	ft_draw_minimap(info);
	if (info->key.space == 1)
		ft_shoot_pistol(info);
	else
		ft_draw_sprite(info, info->game.pistol0.data, info->game.pistol0.size_l,
			&info->game.pistol0.dimensions);
	ft_draw_hud(info);
	ft_move_forth_back(info);
	ft_move_left_right(info);
	ft_rotate(info);
	return (0);
}
