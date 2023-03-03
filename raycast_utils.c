
#include "cub3D.h"
#include "raycast.h"
#include <math.h>

void    init_var(t_info *info)
{
    info->posx = 0;
    info->posy = 0;
    info->ray.dirx = -1;
    info->ray.diry = 0;
    info->ray.planex = 0.0;
    info->ray.planey = 0.66;
    info->mov_speed = 0.05;
    info->rot_speed = 0.05;
    info->img_width = 64;
    info->img_height = 64;
}

double get_player_facing_angle(t_info *info)
{
    double angle;

    angle = atan2(info->ray.diry, info->ray.dirx);
    if (angle < 0)
        angle = 2 * M_PI + angle;
    return (angle);
}