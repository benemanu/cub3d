#include  "../inc/raycast.h"

static void    load_img_north(t_info *info, char *path)
{
    info->game.north.img = mlx_xpm_file_to_image(info->mlx, path, &info->img_width, &info->img_height); 
    info->game.north.data = mlx_get_data_addr(info->game.north.img, &info->game.north.bpp, &info->game.north.size_l, &info->game.north.endian);
}

static void    load_img_south(t_info *info, char *path)
{
    info->game.south.img = mlx_xpm_file_to_image(info->mlx, path, &info->img_width, &info->img_height);
    info->game.south.data = mlx_get_data_addr(info->game.south.img, &info->game.south.bpp, &info->game.south.size_l, &info->game.south.endian);
}

static void    load_img_west(t_info *info, char *path)
{
    info->game.west.img = mlx_xpm_file_to_image(info->mlx, path, &info->img_width, &info->img_height);
    info->game.west.data = mlx_get_data_addr(info->game.west.img, &info->game.west.bpp, &info->game.west.size_l, &info->game.west.endian);
}

static void    load_img_east(t_info *info, char *path)
{
    info->game.east.img = mlx_xpm_file_to_image(info->mlx, path, &info->img_width, &info->img_height);
    info->game.east.data = mlx_get_data_addr(info->game.east.img, &info->game.east.bpp, &info->game.east.size_l, &info->game.east.endian);
}

void    load_images(t_info *info)
{
    load_img_north(info, info->map->north_t);
    load_img_east(info, info->map->east_t);
    load_img_west(info, info->map->west_t);
    load_img_south(info, info->map->south_t);
}