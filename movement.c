
#include "raycast.h"

void move_forth_back(t_info *info)
{
    if (info->key.w == 1)
    {
        if (info->map->grid [(int)(info->ray.posx + info->ray.dirx * info->ray.mov_speed)][(int)(info->ray.posy)] == '0')
            info->ray.posx += info->ray.dirx * info->ray.mov_speed;
        if (info->map->grid [(int)(info->ray.posx)][(int)(info->ray.posy + info->ray.diry * info->ray.mov_speed)] == '0')
            info->ray.posy += info->ray.diry * info->ray.mov_speed;
    }
    if (info->key.s == 1)
    {
        if (info->map->grid [(int)(info->ray.posx - info->ray.dirx * info->ray.mov_speed)][(int)(info->ray.posy)] == '0')
            info->ray.posx -= info->ray.dirx * info->ray.mov_speed;
        if (info->map->grid [(int)(info->ray.posx)][(int)(info->ray.posy - info->ray.diry * info->ray.mov_speed)] == '0')
            info->ray.posy -= info->ray.diry * info->ray.mov_speed;
    }
}

void move_left_right(t_info *info)
{
    if (info->key.a == 1)
    {
        if (info->map->grid [(int)(info->ray.posx - info->ray.diry * info->ray.mov_speed)][(int)(info->ray.posy)] == '0')
            info->ray.posx -= info->ray.diry * info->ray.mov_speed;
        if (info->map->grid [(int)(info->ray.posx)][(int)(info->ray.posy + info->ray.dirx * info->ray.mov_speed)] == '0')
            info->ray.posy += info->ray.dirx * info->ray.mov_speed;
    }
    if (info->key.d == 1)
    {
        if (info->map->grid [(int)(info->ray.posx + info->ray.diry * info->ray.mov_speed)][(int)(info->ray.posy)] == '0')
            info->ray.posx += info->ray.diry * info->ray.mov_speed;
        if (info->map->grid [(int)(info->ray.posx)][(int)(info->ray.posy - info->ray.dirx * info->ray.mov_speed)] == '0')
            info->ray.posy -= info->ray.dirx * info->ray.mov_speed;
    }
}

void rotate(t_info *info)
{
    double old_dirx;
    double old_planex;

    old_dirx = info->ray.dirx;
    old_planex = info->ray.planex;
    if (info->key.left == 1)
    {
        
        info->ray.dirx = info->ray.dirx * cos(info->ray.rot_speed) - info->ray.diry * sin(info->ray.rot_speed);
        info->ray.diry = old_dirx * sin(info->ray.rot_speed) + info->ray.diry * cos(info->ray.rot_speed);
        info->ray.planex = info->ray.planex * cos(info->ray.rot_speed) - info->ray.planey * sin(info->ray.rot_speed);
        info->ray.planey = old_planex * sin(info->ray.rot_speed) + info->ray.planey * cos(info->ray.rot_speed);
    }
    if (info->key.right == 1)
    {
        info->ray.dirx = info->ray.dirx * cos(-info->ray.rot_speed) - info->ray.diry * sin(-info->ray.rot_speed);
        info->ray.diry = old_dirx * sin(-info->ray.rot_speed) + info->ray.diry * cos(-info->ray.rot_speed);
        info->ray.planex = info->ray.planex * cos(-info->ray.rot_speed) - info->ray.planey * sin(-info->ray.rot_speed);
        info->ray.planey = old_planex * sin(-info->ray.rot_speed) + info->ray.planey * cos(-info->ray.rot_speed);
    }
}