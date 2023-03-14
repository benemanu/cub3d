/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoffman <shoffman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:48:00 by shoffman          #+#    #+#             */
/*   Updated: 2023/03/14 17:04:50 by shoffman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && n > 0)
	{
		if (s1[i] > s2[i] || s1[i] < s2[i])
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		else if (s1[i] == '\0')
			return (0);
		i++;
		n--;
	}
	if (!s1[i] && s2[i] && n > 0)
		return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
	return (0);
}
