
#include "raycast.h"

void    raycastidk(t_info *info, int side)
{
    info->ray.raydiry = info->posy;
    info->ray.raydirx = info->posx;
    info->ray.side = side;
    info->ray.hit = 0;

}

void draw_player(t_info *info)
{
    
}