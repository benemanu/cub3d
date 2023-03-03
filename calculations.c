
#include "raycast.h"
#include "cub3D.h"

int main_calc(t_info *info)
{
    int y;
    int x;
    x = 0;
    while (x < WIDTH)
    {
        y = 0;
        info->ray.camerax = 2 * x / (double)WIDTH - 1;
        info->ray.dirx = info->ray.dirx + info->ray.planex * info->ray.camerax;
        info->ray.diry = info->ray.diry + info->ray.planey * info->ray.camerax;
        info->ray.deltadistx = fabs(1 / info->ray.dirx);
        info->ray.deltadisty = fabs(1 / info->ray.diry);
        info->ray.mapx = info->map->player_pos[0];
        info->ray.mapy = info->map->player_pos[1];
        get_direction(info);
        while (info->ray.hit == 0)
        {
            get_side(info);
            if (info->map->grid[info->ray.mapx][info->ray.mapy] == '1')
                info->ray.hit = 1;
            calc_dist(info);
            line_calc(info);
            while (y < info->ray.drawend)
            {
                drawing(info, x, y);
                y++;
            }
        }
        x++;  
    }
    return (0);
}

void drawing (t_info *info, int x, int y)
{
    if (info->ray.side == 0)
    {
        if (info->ray.dirx > 0)
            my_mlx_pixel_put(info, x, y, info->game.north.buff[y][x]);
        else
            my_mlx_pixel_put(info, x, y, info->game.east.buff[y][x]);
    }
    else
    {
        if (info->ray.diry > 0)
            my_mlx_pixel_put(info, x, y, info->game.west.buff[y][x]);
        else
            my_mlx_pixel_put(info, x, y, info->game.south.buff[y][x]);
    }
}

void calc_dist(t_info *info)
{
    if (info->ray.side == 0)
                info->ray.perpwalldist = (info->ray.sidedistx - info->ray.deltadistx);
        else
                info->ray.perpwalldist = (info->ray.sidedistx - info->ray.deltadistx);
}

void    line_calc(t_info *info)
{
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
}


void    get_direction(t_info *info)
{
    if (info->ray.dirx < 0)
        {
            info->ray.stepx = -1;
            info->ray.sidedistx = (info->ray.posx - info->ray.mapx) * info->ray.deltadistx;
        }
        else
        {
            info->ray.stepx = 1;
            info->ray.sidedistx = (info->ray.mapx + 1.0 - info->ray.posx) * info->ray.deltadistx;
        }
        if (info->ray.diry < 0)
        {
            info->ray.stepy = -1;
            info->ray.sidedisty = (info->ray.posy - info->ray.mapy) * info->ray.deltadisty;
        }
        else
        {
            info->ray.stepy = 1;
            info->ray.sidedisty = (info->ray.mapy + 1.0 - info->ray.posy) * info->ray.deltadisty;
        }
}

void    ray_init(t_info *info)
{
    info->ray.posx = (double) info->posx + 0.5;
    info->ray.posy = (double) info->posy + 0.5;
    info->ray.dirx = 0;
    info->ray.diry = 0;
    info->ray.planex = 0;
    info->ray.planey = 0;
    info->key.a = 0;
    info->key.d = 0;
    info->key.w = 0;
    info->key.s = 0;
    info->key.left = 0;
    info->key.right = 0;
    info->key.esc = 0;
    info->ray.perpwalldist = 0;
    info->ray.hit = 0;
}