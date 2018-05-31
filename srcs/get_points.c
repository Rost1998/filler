/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:39:15 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/13 17:43:36 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		get_highest(char **map, char player)
{
	int		x;
	int		y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == player || map[x][y] == player + DIFF)
				return (x);
			++y;
		}
		++x;
	}
	return (-1);
}

static int		get_lowest(char **map, char player)
{
	int		x;
	int		y;
	int		lowest;

	lowest = -1;
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == player || map[x][y] == player + DIFF)
				lowest = x;
			++y;
		}
		++x;
	}
	return (lowest);
}

static int		get_leftmost(char **map, char player)
{
	int		x;
	int		y;
	int		leftmost;

	leftmost = -1;
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if ((map[x][y] == player || map[x][y] == player + DIFF) &&
					(leftmost == -1 || y < leftmost))
				leftmost = y;
			++y;
		}
		++x;
	}
	return (leftmost);
}

static int		get_rightmost(char **map, char player)
{
	int		x;
	int		y;
	int		rightmost;

	rightmost = -1;
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if ((map[x][y] == player || map[x][y] == player + DIFF) &&
					(rightmost == -1 || y > rightmost))
				rightmost = y;
			++y;
		}
		++x;
	}
	return (rightmost);
}

int				*get_player_points(char **map, char player)
{
	int		*ep;

	if (!(ep = (int*)ft_memalloc(sizeof(int) * 4)))
		return (0);
	ep[0] = get_highest(map, player);
	ep[1] = get_lowest(map, player);
	ep[2] = get_leftmost(map, player);
	ep[3] = get_rightmost(map, player);
	return (ep);
}
