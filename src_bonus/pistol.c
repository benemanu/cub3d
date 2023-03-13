#include "../inc_bonus/raycast_bonus.h"

void ft_draw_pistol(t_info *info)
{
	int height;
	int width;
	void *pistol_img = mlx_xpm_file_to_image(info->mlx, "pistol.xpm", &width, &height);
	mlx_put_image_to_window(info->mlx, info->win, pistol_img, 400, 400);
}
