/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:04:14 by shoffman          #+#    #+#             */
/*   Updated: 2023/03/14 17:04:15 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/raycast.h"

void	ft_init_var(t_info *info)
{
	info->ray.dirx = 0;
	info->ray.diry = 0;
	info->ray.planex = 0;
	info->ray.planey = 0;
	info->key.right = 0;
	info->key.left = 0;
	info->key.w = 0;
	info->key.s = 0;
	info->key.a = 0;
	info->key.d = 0;
	info->key.esc = 0;
}
