/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crosshair.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhielsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:20:41 by bhielsch          #+#    #+#             */
/*   Updated: 2023/03/21 10:21:23 by bhielsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/raycast_bonus.h"

void	ft_print_crosshair(t_info *info)
{
	int	i;
	int	j;

	i = -12;
	while (++i < 11)
	{
		j = -3;
		while (++j < 0)
			ft_my_mlx_pixel_put(info, WIDTH / 2 + i, HEIGHT / 2 + j, 0xFF0000);
	}
	i = -3;
	while (++i < 0)
	{
		j = -12;
		while (++j < 11)
			ft_my_mlx_pixel_put(info, WIDTH / 2 + 1 + i, HEIGHT / 2 + j,
				0xFF0000);
	}
}
