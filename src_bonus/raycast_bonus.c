/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:57:55 by shoffman          #+#    #+#             */
/*   Updated: 2023/03/14 16:57:56 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/raycast_bonus.h"

static int	ft_image_loop(t_info *info)
{
	ft_main_calc(info);
	return (0);
}

static void	ft_init2(t_info *info)
{
	if (info->map->player_dir == 'N')
		info->ray.dirx = -1;
	if (info->map->player_dir == 'S')
		info->ray.dirx = 1;
	if (info->map->player_dir == 'E')
		info->ray.diry = 1;
	if (info->map->player_dir == 'W')
		info->ray.diry = -1;
	if (info->map->player_dir == 'N')
		info->ray.planey = 0.66;
	if (info->map->player_dir == 'S')
		info->ray.planey = -0.66;
	if (info->map->player_dir == 'E')
		info->ray.planex = 0.66;
	if (info->map->player_dir == 'W')
		info->ray.planex = -0.66;
	info->f_col = (info->map->floor_rgb[0] << 16) | (
			info->map->floor_rgb[1]) << 8 | info->map->floor_rgb[2];
	info->c_col = (info->map->ceiling_rgb[0] << 16) | (
			info->map->ceiling_rgb[1]) << 8 | info->map->ceiling_rgb[2];
	info->ray.posx = (double)info->map->player_pos[1] + 0.5;
	info->ray.posy = (double)info->map->player_pos[0] + 0.5;
	info->map->grid[info->map->player_pos[1]][info->map->player_pos[0]] = '0';
}

void	ft_draw(int start, int end, t_info *info)
{
	int	y;

	y = -1;
	while (++y < start)
	{
		ft_my_mlx_pixel_put(info, info->ray.x, y, info->c_col);
	}
	while (end < HEIGHT)
	{
		ft_my_mlx_pixel_put(info, info->ray.x, end, info->f_col);
		end++;
	}
}

void	ft_main_raycast(t_map *map)
{
	t_info	info;

	ft_init_var(&info);
	info.map = map;
	ft_init2(&info);
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, WIDTH, HEIGHT, "cub3D");
	info.game.game.img = mlx_new_image(info.mlx, WIDTH, HEIGHT);
	info.game.game.data = mlx_get_data_addr(info.game.game.img,
			&info.game.game.bpp, &info.game.game.size_l,
			&info.game.game.endian);
	ft_load_images(&info);
	mlx_loop_hook(info.mlx, ft_image_loop, &info);
	mlx_hook(info.win, 17, 0, ft_close_window, &info);
	mlx_hook(info.win, 2, 1L << 0, &ft_key_config, &info);
	mlx_hook(info.win, 3, 1L << 1, &ft_key_release, &info);
	mlx_loop(info.mlx);
	ft_ray_free(&info, map);
}

void	ft_my_mlx_pixel_put(t_info *info, int x, int y, int color)
{
	char	*dst;

	dst = info->game.game.data + (y * info->game.game.size_l + x
			* (info->game.game.bpp / 8));
	*(unsigned int *)dst = color;
}
