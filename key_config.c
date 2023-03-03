
#include "raycast.h"
#include "cub3D.h"

int    key_config(int key, t_info *info)
{
    if (key == K_A)
        info->posx -= 1;
    else if (key == K_D)
        info->posx += 1;
    else if (key == K_W)
        info->posy -= 1;
    else if (key == K_S)
        info->posy += 1;
    // else if (key == K_LEFT || key == K_Q)
    //     info->key.left = 1;
    // else if (key == K_RIGHT || key == K_E)
        // info->key.right = 1;
    else if (key == K_ESC)
        our_exit(32);
    return (0);
}

int main()
{
    t_info info;
    key_config(0, &info);
}