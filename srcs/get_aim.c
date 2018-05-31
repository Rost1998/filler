/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_aim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:05:05 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/13 17:48:18 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** 0 - highest x;
** 1 - lowest x;
** 2 - leftmost y;
** 3 - rightmost y;
*/

static _Bool	ft_check_updown(char **map, _Bool mode)
{
	int		y;
	int		x;

	y = 0;
	x = !mode ? 0 : ft_adrlen((void**)map) - 1;
	while (map[x][y])
	{
		if (map[x][y] == g_me || map[x][y] == g_me + DIFF)
			return (1);
		++y;
	}
	return (0);
}

static _Bool	ft_check_lr(char **map, _Bool mode)
{
	int		x;
	int		y;

	x = 0;
	y = !mode ? 0 : ft_strlen(map[0]) - 1;
	while (map[x])
	{
		if (map[x][y] == g_me || map[x][y] == g_me + DIFF)
			return (1);
		++x;
	}
	return (0);
}

static int		ft_num_checkpoints(char **map)
{
	if (!g_placed[0])
	{
		if (!g_placed[1] && (ft_check_updown(map, 0) || ft_check_lr(map, 1)) &&
						(ft_check_updown(map, 1) || ft_check_lr(map, 0)))
			return (2);
		else if (g_placed[1] && (ft_check_updown(map, 0) || ft_check_lr(map, 0))
				&& (ft_check_updown(map, 1) || ft_check_lr(map, 1)
													|| ft_check_lr(map, 0)))
			return (2);
	}
	else
	{
		if (g_placed[1] && (ft_check_updown(map, 0) || ft_check_lr(map, 1)) &&\
							(ft_check_updown(map, 1) || ft_check_lr(map, 0)))
			return (2);
		else if (!g_placed[1] &&
				(ft_check_updown(map, 0) || ft_check_lr(map, 0))
				&& (ft_check_updown(map, 1) || ft_check_lr(map, 1)
												|| ft_check_lr(map, 0)))
			return (2);
	}
	return (1);
}

static _Bool	check_first(char **map)
{
	if (!g_placed[0])
	{
		if (!g_placed[1] && (ft_check_lr(map, 1) || ft_check_updown(map, 0)\
												|| ft_check_updown(map, 1)))
			return (1);
		else if (g_placed[1] && (ft_check_lr(map, 0) || ft_check_updown(map, 0)\
													|| ft_check_updown(map, 1)))
			return (1);
	}
	else if (g_placed[0])
	{
		if (!g_placed[1] && (ft_check_lr(map, 1) || ft_check_lr(map, 0)\
													|| ft_check_updown(map, 0)))
			return (1);
		else if (g_placed[1] && (ft_check_lr(map, 0) || ft_check_lr(map, 1)\
													|| ft_check_updown(map, 0)))
			return (1);
	}
	return (0);
}

int				*get_aim(char **map)
{
	int		*aim;
	int		*enemys_points;
	int		*my_points;

	if (!(aim = (int*)ft_memalloc(sizeof(int) * 2)))
		return (0);
	enemys_points = get_player_points(map, g_enemy);
	my_points = get_player_points(map, g_me);
	if (!check_first(map))
		choose_aim_first(map, aim, my_points, enemys_points);
	else if (ft_num_checkpoints(map) < 2)
		choose_aim_second(map, aim, my_points, enemys_points);
	else
		choose_aim_attack(map, aim);
	free(my_points);
	free(enemys_points);
	return (aim);
}
