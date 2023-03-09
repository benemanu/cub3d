#include  "../inc/raycast.h"

int	main_calc(t_info *info)
{
	info->ray.x = -1;
	while (++info->ray.x < WIDTH)
	{
		ray_init(info);
		get_direction(info);
		drawing(info);
	}
	mlx_clear_window(info->mlx, info->win);
	mlx_put_image_to_window(info->mlx, info->win, info->game.game.img, 0, 0);
	move_forth_back(info);
	move_left_right(info);
	rotate(info);
	return (0);
}

void	drawing(t_info *info)
{
	int color;
	if (info->ray.side == 0)
		info->ray.wallx = info->ray.posy + info->ray.perpwalldist
			* info->ray.raydiry;
	else
		info->ray.wallx = info->ray.posx + info->ray.perpwalldist
			* info->ray.raydirx;
	info->ray.wallx -= floor((info->ray.wallx));
	info->ray.texX = (int)(info->ray.wallx * (double)64);
	if (info->ray.side == 0 && info->ray.raydirx > 0)
		info->ray.texX = 64 - info->ray.texX - 1;
	if (info->ray.side == 1 && info->ray.raydiry < 0)
		info->ray.texX = 64 - info->ray.texX - 1;
	info->ray.step = 1.0 * 64 / info->ray.lineheight;
	info->ray.texpos = (info->ray.drawstart - HEIGHT / 2 + info->ray.lineheight
			/ 2) * info->ray.step;
	draw(info->ray.drawstart, info->ray.drawend, info);
	while (info->ray.drawstart < info->ray.drawend)
	{
		info->ray.texy = (int)info->ray.texpos & (64 - 1);
		info->ray.texpos += info->ray.step;
		if (info->ray.side == 0)
		{
			if (info->ray.raydirx > 0)
			{
				color = *(int *)(info->game.south.data + (info->ray.texX * (info->game.south.bpp / 8) + info->ray.texy * info->game.south.size_l));
				my_mlx_pixel_put(info, info->ray.x, info->ray.drawstart,
						color);
			}
			else
			{
				color = *(int *)(info->game.north.data + (info->ray.texX * (info->game.north.bpp / 8) + info->ray.texy * info->game.north.size_l));
				my_mlx_pixel_put(info, info->ray.x, info->ray.drawstart,
						color);
			}
		}
		else
		{
			if (info->ray.raydiry > 0)
			{
				color = *(int *)(info->game.east.data + (info->ray.texX * (info->game.east.bpp / 8) + info->ray.texy * info->game.east.size_l));
				my_mlx_pixel_put(info, info->ray.x, info->ray.drawstart,
						color);
			}
			else
			{
				color = *(int *)(info->game.west.data + (info->ray.texX * (info->game.west.bpp / 8) + info->ray.texy * info->game.west.size_l));
				my_mlx_pixel_put(info, info->ray.x, info->ray.drawstart,
						color);
			}
		}
		info->ray.drawstart++;
	}
}

void	calc_dist(t_info *info)
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

void	get_side(t_info *info)
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
	calc_dist(info);
}

void	get_direction(t_info *info)
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
	get_side(info);
}
