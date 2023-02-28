
#include "cub3D.h"

void    init_var(t_info *info)
{
    info->posx = 22.0;
    info->posy = 11.5;
    info->dirx = -1;
    info->diry = 0;
    info->mlx = mlx_init();
    info->planex = 0.0;
    info->planey = 0.66;
    info->mov_speed = 0.05;
    info->rot_speed = 0.05;
}

void    load_images_xpm(t_info *info, int *texture, char *path, t_img *img)
{
    int x;
    int y;

    y = -1;
    img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
    img->data = mlx_get_data_addr(info->win, &img->bpp, &img->line_len, &img->endian);
    while (++y < img->img_height)
    {
        x = -1;
        while (++x < img->img_width)
            texture[img->img_width * y + x] = img->data[img->img_width * y + x];
    }
    //mlx_destroy_image(info->mlx, img->img);
}