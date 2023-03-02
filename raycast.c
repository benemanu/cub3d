
#include "cub3D.h"
#include "raycast.h"

int    image_loop(t_info *info)
{
    //calculate the distance to the walls
    draw(info);
    return (0);
}

void    draw(t_info *info)
{
    int x;
    int y;

    x = -1;
    while (++x < width)
    {
        y = -1;
        while (++y < height / 2)
        {
            my_mlx_pixel_put(info, x, y, CEILING_COLOR);
        }
        while (y < height)
        {
            my_mlx_pixel_put(info, x, y, FLOOR_COLOR);
            y++;
        }
    }
    mlx_put_image_to_window(info->mlx, info->win, info->game.game.img, 0, 0);
}

void    main_raycast(void)
{
    t_info info;
    init_var(&info);
    info.mlx = mlx_init();
    info.win = mlx_new_window(info.mlx, width, height, "cub3D");
    info.game.game.img = mlx_new_image(info.mlx, width, height);
    info.game.game.data = mlx_get_data_addr(info.game.game.img, &info.game.game.bpp, &info.game.game.size_l, &info.game.game.endian);
    load_images(&info);
    draw(&info);
    mlx_destroy_window(info.mlx, info.win);

   
    // mlx_loop_hook(info.mlx, image_loop, &info);
    // mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_config, &info);

    // mlx_loop(info.mlx);
}

void    load_images(t_info *info)
{
    load_img_north(info, "./images/bluestone.xpm");
    load_img_east(info, "./images/redbrick.xpm");
    load_img_west(info, "./images/purplestone.xpm");
    load_img_south(info, "./images/mossy.xpm");
}

void my_mlx_pixel_put(t_info *info, int x, int y, int color)
{
    char    *dst;

    dst = info->game.game.data + (y * info->game.game.size_l + x * (info->game.game.bpp / 8));
    *(unsigned int*)dst = color;
}