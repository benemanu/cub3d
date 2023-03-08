
#include "cub3D.h"
#include "raycast.h"

void    load_images(t_info *info)
{
    load_img_north(info, info->map->north_t);
    load_img_east(info, info->map->east_t);
    load_img_west(info, info->map->west_t);
    load_img_south(info, info->map->south_t);
}

void    load_img_north(t_info *info, char *path)
{
    int x;
    int y;

    x = -1;
    info->game.north.img = mlx_xpm_file_to_image(info->mlx, path, &info->img_width, &info->img_height); 
    info->game.north.data = mlx_get_data_addr(info->game.north.img, &info->game.north.bpp, &info->game.north.size_l, &info->game.north.endian);
    while (++x < info->img_height)
    {
        y = -1;
        while (++y < info->img_width)
            info->game.north.buff[x][y] = *(int *)(info->game.north.data + (x * (info->game.north.bpp / 8) + y * info->game.north.size_l));
    }
    mlx_destroy_image(info->mlx, info->game.north.img);
}

void    load_img_south(t_info *info, char *path)
{
    int x;
    int y;

    x = -1;
    info->game.south.img = mlx_xpm_file_to_image(info->mlx, path, &info->img_width, &info->img_height);
    info->game.south.data = mlx_get_data_addr(info->game.south.img, &info->game.south.bpp, &info->game.south.size_l, &info->game.south.endian);
    while (++x < info->img_height)
    {
        y = -1;
        while (++y < info->img_width)
        {
            info->game.south.buff[x][y] = *(int *)(info->game.south.data + (x * (info->game.south.bpp / 8) + y * info->game.south.size_l));
        }
    }
    mlx_destroy_image(info->mlx, info->game.south.img);
}

void    load_img_west(t_info *info, char *path)
{
    int x;
    int y;

    x = -1;
    info->game.west.img = mlx_xpm_file_to_image(info->mlx, path, &info->img_width, &info->img_height);
    info->game.west.data = mlx_get_data_addr(info->game.west.img, &info->game.west.bpp, &info->game.west.size_l, &info->game.west.endian);
    while (++x < info->img_height)
    {
        y = -1;
        while (++y < info->img_width)
        {
            info->game.west.buff[x][y] = *(int *)(info->game.west.data + (x * (info->game.west.bpp / 8) + y * info->game.west.size_l));
        }
    }
    mlx_destroy_image(info->mlx, info->game.west.img);
}

void    load_img_east(t_info *info, char *path)
{
    int x;
    int y;
    
    x = -1;
    info->game.east.img = mlx_xpm_file_to_image(info->mlx, path, &info->img_width, &info->img_height);
    info->game.east.data = mlx_get_data_addr(info->game.east.img, &info->game.east.bpp, &info->game.east.size_l, &info->game.east.endian);
    while (++x < info->img_height)
    {
        y = -1;
        while (++y < info->img_width)
        {
            info->game.east.buff[x][y] = *(int *)(info->game.east.data + (x * (info->game.east.bpp / 8) + y * info->game.east.size_l));
        }
    }
    mlx_destroy_image(info->mlx, info->game.east.img);
}