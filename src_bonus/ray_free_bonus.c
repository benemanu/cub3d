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
