
#include "cub3D.h"
#include "raycast.h"

void    image_loop(t_info *info)
{
    //calculate the distance to the walls
    draw(info);
}

void    draw(t_info *info)
{
    if (get_player_facing_angle(info) > 0 && get_player_facing_angle(info) < 180)
        info->buff[info->img_height][info->img_width] = 0x000000FF;
    else if (get_player_facing_angle(info) > 180 && get_player_facing_angle(info) < 360)
        info->buff[info->img_height][info->img_width] = 0x00FF0000;
    else if (get_player_facing_angle(info) == 0 || get_player_facing_angle(info) == 180)
        info->buff[info->img_height][info->img_width] = 0x0000FF00;
    else if (get_player_facing_angle(info) == 90 || get_player_facing_angle(info) == 270)
        info->buff[info->img_height][info->img_width] = 0x00FFFF00;
    mlx_pixel_put(info->mlx, info->win, info->img_width, info->img_height, info->buff[info->img_height][info->img_width]);
    info->img_width++;
    if (info->img_width == width)
    {
        info->img_width = 0;
        info->img_height++;
    }
    if (info->img_height == height)
    {
        info->img_height = 0;
        info->img_width = 0;
        //one frame is drawn
    }
}

void    main_raycast(void)
{
    t_info info;
    init_var(&info);
    load_img(&info);
    draw(&info);

    mlx_loop(info.mlx);
    mlx_loop_hook(info.mlx, mlx_loop, &info);

    image_loop(info.mlx);
}

void    load_img(t_info *info)
{
    load_images_xpm(info, info->texture[0], "./images/bluestone.xpm");
    load_images_xpm(info, info->texture[1], "./images/redbrick.xpm");
    load_images_xpm(info, info->texture[2], "./images/purplestone.xpm");
    load_images_xpm(info, info->texture[3], "./images/mossy.xpm");
}



