
#include "raycast.h"
#include "cub3D.h"

int    key_config(int key, t_info *info)
{
    if (key == K_A)
        info->key.a = 1;
    else if (key == K_D)
        info->key.d = 1;
    else if (key == K_W)
        info->key.w = 1;
    else if (key == K_S)
        info->key.s = 1;
    else if (key == K_LEFT)
        info->key.left = 1;
    else if (key == K_RIGHT)
        info->key.right = 1;
    else if (key == K_ESC)
        exit(32);
    return (0);
}

int     key_release(int key, t_info *info)
{
    if (key == K_A)
        info->key.a = 0;
    else if (key == K_D)
        info->key.d = 0;
    else if (key == K_W)
        info->key.w = 0;
    else if (key == K_S)
        info->key.s = 0;
    else if (key == K_LEFT)
        info->key.left = 0;
    else if (key == K_RIGHT)
        info->key.right = 0;
    return (0);
}

int     close_window(t_info *info)
{
    (void)info;
    exit(32);
    return (0);
}