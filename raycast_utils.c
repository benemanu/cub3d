
#include "cub3D.h"
#include "raycast.h"
#include <math.h>

void    init_var(t_info *info)
{
    info->posx = 22.0;
    info->posy = 11.5;
    info->dirx = -1;
    info->diry = 0;
    info->mlx = mlx_init();
    info->win = mlx_new_window(info->mlx, width, height, "cub3D");
    info->planex = 0.0;
    info->planey = 0.66;
    info->mov_speed = 0.05;
    info->rot_speed = 0.05;
    info->img_width = 64;
    info->img_height = 64;
    info->game.east.img = mlx_xpm_file_to_image(info->mlx, "./images/bluestone.xpm", &info->img_width, &info->img_height);
    info->game.east.data = mlx_get_data_addr(info->game.east.img, &info->game.east.bpp, &info->game.east.size_l, &info->game.east.endian);
    info->game.west.img = mlx_xpm_file_to_image(info->mlx, "./images/redbrick.xpm", &info->img_width, &info->img_height);
    info->game.west.data = mlx_get_data_addr(info->game.west.img, &info->game.west.bpp, &info->game.west.size_l, &info->game.west.endian);
    info->game.north.img = mlx_xpm_file_to_image(info->mlx, "./images/purplestone.xpm", &info->img_width, &info->img_height);
    info->game.north.data = mlx_get_data_addr(info->game.north.img, &info->game.north.bpp, &info->game.north.size_l, &info->game.north.endian);
    info->game.south.img = mlx_xpm_file_to_image(info->mlx, "./images/mossy.xpm", &info->img_width, &info->img_height);
    info->game.south.data = mlx_get_data_addr(info->game.south.img, &info->game.south.bpp, &info->game.south.size_l, &info->game.south.endian);
    info->texture = (int **)malloc(sizeof(int *) * 4);
    info->texture[0] = (int *)malloc(sizeof(int) * 64 * 64);
    info->texture[1] = (int *)malloc(sizeof(int) * 64 * 64);
    info->texture[2] = (int *)malloc(sizeof(int) * 64 * 64);
    info->texture[3] = (int *)malloc(sizeof(int) * 64 * 64);
}

void    load_images_xpm(t_info *info, int *texture, char *path)
{
    int x;
    int y;

    y = -1;
    info->image = mlx_xpm_file_to_image(info->mlx, path, &info->img_width, &info->img_height);
    info->image = mlx_get_data_addr(info->image, &info->game.east.bpp, &info->game.east.size_l, &info->game.east.endian);
    while (++y < info->img_height)
    {
        x = -1;
        while (++x < info->img_width)
        {
            texture[y * info->img_width + x] = *(int *)(info->image + (x * (info->game.east.bpp / 8) + y * info->game.east.size_l));
        }
    }
    // mlx_destroy_window(info->mlx, info->win);
}

double get_player_facing_angle(t_info *info)
{
    double angle;

    angle = atan2(info->diry, info->dirx);
    if (angle < 0)
        angle = 2 * M_PI + angle;
    return (angle);
}