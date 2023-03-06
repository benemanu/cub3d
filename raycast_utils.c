
#include "cub3D.h"
#include "raycast.h"
#include <math.h>

void    init_var(t_info *info)
{
    info->ray.dirx = -1;
    info->ray.diry = 0;
    info->ray.planex = 0.0;
    info->ray.planey = 0.66;
    info->img_width = 64;
    info->img_height = 64;
    info->map = NULL;
    struct s_map *map = malloc(sizeof(struct s_map));
    if(!map)
        printf("\033[1;31mError.\nMalloc failed.\033[0m\n");
}

double get_player_facing_angle(t_info *info)
{
    double angle;

    angle = atan2(info->ray.diry, info->ray.dirx);
    if (angle < 0)
        angle = 2 * M_PI + angle;
    return (angle);
}