
#include "raycast.h"

int    image_loop(t_info *info)
{
    draw(info);
    main_calc(info);
    return (0);
}

void    draw(t_info *info)
{
    int x;
    int y;

    x = -1;
    while (++x < WIDTH)
    {
        y = -1;
        while (++y < HEIGHT / 2)
        {
            my_mlx_pixel_put(info, x, y, info->c_col);
        }
        while (y < HEIGHT)
        {
            my_mlx_pixel_put(info, x, y, info->f_col);
            y++;
        }
    }
}

void    main_raycast(t_map *map)
{
    t_info info;
    init_var(&info);
    info.map = map;
    init2(&info);
    info.mlx = mlx_init();
    info.win = mlx_new_window(info.mlx, WIDTH, HEIGHT, "cub3D");
    info.game.game.img = mlx_new_image(info.mlx, WIDTH, HEIGHT);
    info.game.game.data = mlx_get_data_addr(info.game.game.img, &info.game.game.bpp, &info.game.game.size_l, &info.game.game.endian);
    load_images(&info);
    mlx_loop_hook(info.mlx, image_loop, &info);
    mlx_hook(info.win, 17, 0, close_window, &info);
    mlx_hook(info.win, 2, 1L << 0, &key_config, &info);
    mlx_hook(info.win, 3, 1L << 1, &key_release, &info);
    mlx_loop(info.mlx);
}

void init2(t_info *info)
{
    if (info->map->player_dir == 'N')
		info->ray.dirx = -1;
	if (info->map->player_dir == 'S')
		info->ray.dirx = 1;
	if (info->map->player_dir == 'E')
		info->ray.diry = 1;
	if (info->map->player_dir == 'W')
		info->ray.diry = -1;
	if (info->map->player_dir == 'N')
		info->ray.planey = 0.66;
	if (info->map->player_dir == 'S')
		info->ray.planey = -0.66;
	if (info->map->player_dir == 'E')
		info->ray.planex = 0.66;
	if (info->map->player_dir == 'W')
		info->ray.planex = -0.66;
    info->f_col = (info->map->floor_rgb[0] << 16) | (info->map->floor_rgb[1]) << 8 | info->map->floor_rgb[2];
    info->c_col = (info->map->ceiling_rgb[0] << 16) | (info->map->ceiling_rgb[1]) << 8 | info->map->ceiling_rgb[2];
    info->ray.posx = (double)info->map->player_pos[1] + 0.5;
    info->ray.posy = (double)info->map->player_pos[0] + 0.5;
    info->map->grid[info->map->player_pos[1]][info->map->player_pos[0]] = '0';
}

void my_mlx_pixel_put(t_info *info, int x, int y, int color)
{
    char    *dst;

    dst = info->game.game.data + (y * info->game.game.size_l + x * (info->game.game.bpp / 8));
    *(unsigned int*)dst = color;
}