#include "raycast.h"

void	ray_free(t_info *info)
{
	ft_free_map_struct(info->map);
	free_images(info);
}

void	free_images(t_info *info)
{
	mlx_destroy_window(info->mlx, info->win);
	free(info->game.game.img);
	free(info->image);
}
