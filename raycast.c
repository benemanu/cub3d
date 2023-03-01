
#include "cub3D.h"

void    mlx_loop(t_info *info)
{
    //calculate the distance to the walls
    draw(info);
}

void    draw(t_info *info)
{
    int y;
    int x;

    y = -1;
    while (++y < height)
    {
        x = -1;
        while (++x < width)
            info->img.data[width * y + x] = info->buff[y][x];
    }
    mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void    main_raycast(void)
{
    t_info info;
    init_var(&info);
    load_img(&info);
    info.win = mlx_new_window(info.mlx, width, height, "cub3D");
    mlx_loop(&info);
    info.img.img = mlx_new_image(info.mlx, width, height);
    info.img.data = mlx_get_data_addr(info.img.img, &info.img.bpp, &info.img.line_len, &info.img.endian);
    mlx_loop_hook(info.mlx, mlx_loop, &info);
    mlx_hook(info.win, , 0, , &info);

    mlx_loop(info.mlx);  
}

void    load_img(t_info *info)
{
    t_img img;

    load_images_xpm(info, info->texture[0], "./images/bluestone.xpm", &img);
    load_images_xpm(info, info->texture[1], "./images/redbrick.xpm", &img);
    load_images_xpm(info, info->texture[2], "./images/purplestone.xpm", &img);
    load_images_xpm(info, info->texture[3], "./images/mossy.xpm", &img);
}



