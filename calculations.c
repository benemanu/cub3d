
#include "raycast.h"
#include "cub3D.h"

int main_calc(t_info *info, int *position)
{
    int ind;
    int x;
    x = 0;
    init_buff(info);
    while (x < WIDTH)
    {
        info->ray.camerax = 2 * x / (double)WIDTH - 1;
        info->ray.dirx = info->ray.dirx + info->ray.planex * info->ray.camerax;
        info->ray.diry = info->ray.diry + info->ray.planey * info->ray.camerax;
        info->ray.deltadistx = abs(1 / info->ray.dirx);
        info->ray.deltadisty = abs(1 / info->ray.diry);
        info->ray.mapx = (int)info->ray.posx;
        info->ray.mapy = (int)info->ray.posy;
        get_direction(info);
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
            if (info->game.map[info->ray.mapx][info->ray.mapy] == '1')
                info->ray.hit = 1;
        }
        if (info->ray.side == 0)
                info->ray.perpwalldist = (info->ray.sidedistx - info->ray.deltadistx);
        else
                info->ray.perpwalldist = (info->ray.sidedistx - info->ray.deltadistx);
    }
}
void    ray_func(t_info *info)
{
    
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