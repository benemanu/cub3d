#include "../inc_bonus/raycast_bonus.h"

void    ft_print_crosshair(t_info *info)
{
    int i;
    int j;

    i = - 11;
    while (i < 11)
    {
        j = -2;
        while (j < 0)
        {
            ft_my_mlx_pixel_put(info, WIDTH / 2 + i, HEIGHT / 2 + j, 0xFF0000);
            j++;
        }
        i++;
    }
    i = -2;
    while (i < 0)
    {
        j = -11;
        while (j < 11)
        {
            ft_my_mlx_pixel_put(info, WIDTH / 2 + 1 + i, HEIGHT / 2 + j, 0xFF0000);
            j++;
        }
        i++;
    }
}