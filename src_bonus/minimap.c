
#include "../inc_bonus/raycast_bonus.h"

static void ft_draw_square(int x, int y, int color, t_info *info)
{
    int i;
    int j;

    i = x;
    while (++i < x + 10)
    {
        j = y;
        while (++j < y + 10)
            ft_my_mlx_pixel_put(info, i, j, color);
    }
}

static void print_player(t_info *info)
{
    int x;
    int y;

    x = 79;
    y = 69;
    ft_draw_square(x, y, 0x00FF00, info);
}

static void check_map(t_info *info, int y, int k, int i, int start)
{
    int ind;
    ind = 0;
    if ((int)info->ray.posx - k < 0  || (int)info->ray.posy - i < 0 || (int)info->ray.posy  - i > (int)info->map->height || (int)info->ray.posx - k > (int)info->map->width)
    {
        ft_draw_square(start, y, 0x000000, info);
        ind = 1;
    }
    else if (ind == 0)
    {
        if (info->map->grid[(int)info->ray.posx - k][(int)info->ray.posy - i] == '1')
            ft_draw_square(start, y, 0xFFFFFF, info);
    }
    else
        ft_draw_square(start, y, 0x000FFF, info);
}

void ft_draw_minimap(t_info *info)
{
    int k;
    int i;
    k = 6;
    int start;
    int start2;
    start2 = 19;
    while (--k >= -5)
    {
        start = 19;
        i = 6;
        start2 += 10;
        while (--i >= -5)
        {
            check_map(info, start, k, i, start2);
            start += 10;
        }
    }
    print_player(info);
}