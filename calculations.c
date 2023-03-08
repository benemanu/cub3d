
#include "raycast.h"
#include "cub3D.h"

int main_calc(t_info *info)
{
    info->ray.x = -1;
    while (++info->ray.x < WIDTH)
    {
        ray_init(info);
        get_direction(info);
        drawing(info);
    }
    mlx_clear_window(info->mlx, info->win);
    mlx_put_image_to_window(info->mlx, info->win, info->game.game.img, 0, 0);
    move_forth_back(info);
    move_left_right(info);
    rotate(info);
    return (0);
}

void drawing (t_info *info)
{
    if (info->ray.side == 0)
        info->ray.wallx = info->ray.posy + info->ray.perpwalldist * info->ray.raydiry;
    else
        info->ray.wallx = info->ray.posx + info->ray.perpwalldist * info->ray.raydirx;
    info->ray.wallx -= floor((info->ray.wallx));
    info->ray.texX = (int)(info->ray.wallx * (double)64);
    if (info->ray.side == 0 && info->ray.raydirx > 0)
        info->ray.texX = 64 - info->ray.texX - 1;
    if (info->ray.side == 1 && info->ray.raydiry < 0)
        info->ray.texX = 64 - info->ray.texX - 1;
    info->ray.step = 1.0 * 64 / info->ray.lineheight;
    info->ray.texpos = (info->ray.drawstart - HEIGHT / 2 + info->ray.lineheight / 2) * info->ray.step;
    while (info->ray.drawstart < info->ray.drawend)
    {
        info->ray.texy = (int)info->ray.texpos & (64 - 1);
        info->ray.texpos += info->ray.step;
        if (info->ray.side == 0)
        {
            if (info->ray.raydirx > 0)
                my_mlx_pixel_put(info, info->ray.x, info->ray.drawstart, info->game.south.buff[info->ray.texX][info->ray.texy]); //south
            else
                my_mlx_pixel_put(info, info->ray.x, info->ray.drawstart, info->game.north.buff[info->ray.texX][info->ray.texy]); //north
        }
        else
        {
            if (info->ray.raydiry > 0)
                my_mlx_pixel_put(info, info->ray.x, info->ray.drawstart, info->game.south.buff[info->ray.texX][info->ray.texy]);
            else
                my_mlx_pixel_put(info, info->ray.x, info->ray.drawstart, info->game.west.buff[info->ray.texX][info->ray.texy]);
        }
         info->ray.drawstart++;       
    }
}

void calc_dist(t_info *info)
{
    if (info->ray.side == 0)
        info->ray.perpwalldist = ((double)info->ray.mapx - info->ray.posx + (1 - (double)info->ray.stepx) / 2) / info->ray.raydirx;
    else
        info->ray.perpwalldist = ((double)info->ray.mapy - info->ray.posy + (1 - (double)info->ray.stepy) / 2) / info->ray.raydiry;
    info->ray.lineheight = (int)(HEIGHT / info->ray.perpwalldist);
    info->ray.drawstart = -info->ray.lineheight / 2 + HEIGHT / 2;
    if (info->ray.drawstart < 0)
        info->ray.drawstart = 0;
    info->ray.drawend = info->ray.lineheight / 2 + HEIGHT / 2;
    if (info->ray.drawend >= HEIGHT)
        info->ray.drawend = HEIGHT - 1;
}

void get_side(t_info *info)
{
    while (info->ray.hit == 0)
    {
        if (info->ray.sidedistx < info->ray.sidedisty)
        {
            info->ray.sidedistx += info->ray.deltadistx;
            info->ray.mapx += info->ray.stepx;
            info->ray.side = 0;
        }
        else
        {
            info->ray.sidedisty += info->ray.deltadisty;
            info->ray.mapy += info->ray.stepy;
            info->ray.side = 1;
        }
         if (info->ray.mapx < (int)info->map->height && info->ray.mapy < (int)info->map->width && info->map->grid[info->ray.mapx][info->ray.mapy] == '1')
			info->ray.hit = 1;
    }
    calc_dist(info);
}


void    get_direction(t_info *info)
{
    if (info->ray.raydirx < 0)
    {
        info->ray.stepx = -1;
        info->ray.sidedistx = (info->ray.posx - info->ray.mapx) * info->ray.deltadistx;
    }
    else
    {
        info->ray.stepx = 1;
        info->ray.sidedistx = (info->ray.mapx + 1.0 - info->ray.posx) * info->ray.deltadistx;
    }
    if (info->ray.raydiry < 0)
    {
        info->ray.stepy = -1;
        info->ray.sidedisty = (info->ray.posy - info->ray.mapy) * info->ray.deltadisty;
    }
    else
    {
        info->ray.stepy = 1;
        info->ray.sidedisty = (info->ray.mapy + 1.0 - info->ray.posy) * info->ray.deltadisty;
    }
    get_side(info);
}

void    ray_init(t_info *info)
{
    info->ray.hit = 0;
    info->ray.perpwalldist = 0;
    info->ray.camerax = 2 * info->ray.x / (double)WIDTH - 1;
    info->ray.raydirx = info->ray.dirx + info->ray.planex * info->ray.camerax;
    info->ray.raydiry = info->ray.diry + info->ray.planey * info->ray.camerax;
    info->ray.mapx = (int)info->ray.posx;
    info->ray.mapy = (int)info->ray.posy;
    info->ray.mov_speed = 0.1;
    info->ray.rot_speed = 0.033 * 1.8;
    ray_init1(info);
}

void    ray_init1(t_info *info)
{
    if (info->ray.raydiry == 0)
        info->ray.deltadistx = 0;
    else if (info->ray.raydirx == 0)
        info->ray.deltadistx = 1;
    else
        info->ray.deltadistx = sqrt(1 + (info->ray.raydiry * info->ray.raydiry) / (info->ray.raydirx * info->ray.raydirx));
    if (info->ray.raydirx == 0)
        info->ray.deltadisty = 0;
    else if (info->ray.raydiry == 0)
        info->ray.deltadisty = 1;
    else
        info->ray.deltadisty = sqrt(1 + (info->ray.raydirx * info->ray.raydirx) / (info->ray.raydiry * info->ray.raydiry));
}