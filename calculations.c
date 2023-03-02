
#include "raycast.h"
#include "cub3D.h"

int main_calc(t_info *info, int *position)
{
    int ind;
    int x;
    double camx;
    x = 0;
    init_buff(info);
    while (x < width)
    {
        camx = 2 * x / (double)width - 1;
        info->raydirx = info->dirx + info->planex * camx;
        info->raydiry = info->diry + info->planey * camx;
    }
}

void    init_buff(t_info *info)
{
    int x;
    int y;

    x = -1;
    while (++x < height)
    {
        y = -1;
        while (++y < width)
            info->buff[x][y] = 0;
    }
}