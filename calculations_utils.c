#include "raycast.h"

void	ray_init(t_info *info)
{
	info->ray.hit = 0;
	info->ray.perpwalldist = 0;
	info->ray.camerax = 2 * info->ray.x / (double)WIDTH - 1;
	info->ray.raydirx = info->ray.dirx + info->ray.planex * info->ray.camerax;
	info->ray.raydiry = info->ray.diry + info->ray.planey * info->ray.camerax;
	info->ray.mapx = (int)info->ray.posx;
	info->ray.mapy = (int)info->ray.posy;
	info->ray.mov_speed = 0.1;
	info->ray.horz_speed = 0.05;
	info->ray.rot_speed = 0.033 * 1.6;
	ray_init1(info);
}

void	ray_init1(t_info *info)
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