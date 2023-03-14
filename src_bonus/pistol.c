#include "../inc_bonus/raycast_bonus.h"

void ft_load_img_pistol_0(t_info *info, char *img)
{
	info->game.pistol0.img = mlx_xpm_file_to_image(info->mlx, img, &info->img_width, &info->img_height);
}

void ft_draw_pistol(t_info *info)
{
	mlx_put_image_to_window(info->mlx, info->win, info->game.pistol0.img, 500, 520);
}
