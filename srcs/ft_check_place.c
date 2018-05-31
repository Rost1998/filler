/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 10:21:44 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/09 14:26:29 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

_Bool		ft_check_place(char **map, t_coords *coords)
{
	int		*x;
	int		*y;
	int		len;
	int		num_of_point;

	num_of_point = 0;
	len = coords->number;
	x = coords->shape_x;
	y = coords->shape_y;
	while (len--)
	{
		if (!(map[*x]) || !(map[*x][*y]) || map[*x][*y] == g_enemy ||\
										map[*x][*y] == g_enemy + DIFF)
			return (0);
		if (map[*x][*y] == g_me || map[*x][*y] == g_me + DIFF)
			++num_of_point;
		++x;
		++y;
	}
	return (num_of_point == 1 ? 1 : 0);
}
