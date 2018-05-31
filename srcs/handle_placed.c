/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_placed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:39:49 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/13 17:48:43 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		analyze_places(int *pme, int *penemy)
{
	if (!(g_placed = (int*)ft_memalloc(sizeof(int) * 2)))
		return ;
	if (pme[0] < penemy[0])
		g_placed[0] = 0;
	else
		g_placed[0] = 1;
	if (pme[1] < penemy[1])
		g_placed[1] = 0;
	else
		g_placed[1] = 1;
	free(pme);
	free(penemy);
}

static void		assignment(int *place, int x, int y)
{
	place[0] = x;
	place[1] = y;
}

void			handle_placed(char **map)
{
	int		*pme;
	int		*penemy;
	int		x;
	int		y;

	if (!(pme = (int*)ft_memalloc(sizeof(int) * 2)) ||\
			!(penemy = (int*)ft_memalloc(sizeof(int) * 2)))
		return ;
	g_first_game = 0;
	x = 0;
	while (map && map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == g_me)
				assignment(pme, x, y);
			else if (map[x][y] == g_enemy)
				assignment(penemy, x, y);
			++y;
		}
		++x;
	}
	analyze_places(pme, penemy);
}
