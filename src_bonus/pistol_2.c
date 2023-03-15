/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pistol_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:10:13 by shoffman          #+#    #+#             */
/*   Updated: 2023/03/15 11:29:29 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/raycast_bonus.h"

void ft_draw_pistol(t_info *info, int reset_space)
{
	ft_draw_sprite(info, info->game.pistol0.data, info->game.pistol0.size_l,
			&info->game.pistol0.dimensions);
	if (reset_space == 1)
		info->key.space = 0;
}