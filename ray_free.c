#include "raycast.h"

void	ray_free(t_info *info)
{
	ft_free_map_struct(info->map);
	exit(0);
	free_images(info);
}

void	free_images(t_info *info)
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
	if (info->win)
		mlx_destroy_window(info->mlx, info->win);
	free(info->mlx);
}
