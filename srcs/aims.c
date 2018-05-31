/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aims.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:39:02 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/14 19:14:19 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			choose_aim_first(char **map, int *aim, int *mp, int *ep)
{
	if (mp[0] < ep[0])
	{
		aim[0] = ep[0] >= 2 ? ep[0] - 2 : ep[0];
		if (mp[2] < ep[2])
			aim[1] = ep[3] < (int)ft_strlen(map[0]) - 1 ? ep[3] + 1 : ep[3];
		else
			aim[1] = ep[2] > 1 ? ep[2] - 2 : ep[2];
	}
	else
	{
		aim[0] = ep[0] >= 2 ? ep[0] - 2 : ep[0];
		if (g_placed[1])
			aim[1] = ep[3] < (int)ft_strlen(map[0]) - 1 ? ep[3] + 1 : ep[3];
		else
			aim[1] = ep[2] > 1 ? ep[2] - 2 : ep[2];
	}
}

void			choose_aim_second(char **map, int *aim, int *mp, int *ep)
{
	if (!g_placed[0])
	{
		aim[0] = ep[1] < ft_adrlen((void**)map) - 1 ? ep[1] + 1 : ep[1];
		if (mp[2] < ep[2])
			aim[1] = ep[2] > 1 ? ep[2] - 2 : ep[2];
		else
			aim[1] = ep[3] < (int)ft_strlen(map[0]) - 1 ? ep[3] + 1 : ep[3];
	}
	else
	{
		aim[0] = ep[1] < ft_adrlen((void**)map) - 1 ? ep[1] + 1 : ep[1];
		if (mp[2] > ep[2])
			aim[1] = ep[3] > 1 ? ep[3] - 1 : ep[3];
		else
			aim[1] = ep[3] < ft_adrlen((void**)map) - 1 ? ep[3] + 1 : ep[3];
	}
}

void			choose_aim_attack(char **map, int *aim)
{
	if (!g_placed[1])
	{
		aim[1] = ft_strlen(map[0]) - 1;
		if (!g_placed[0])
			aim[0] = ft_adrlen((void**)map) - 1;
		else
			aim[0] = 0;
	}
	else
	{
		aim[1] = 0;
		if (g_placed[0])
			aim[0] = 0;
		else
			aim[0] = ft_adrlen((void**)map) - 1;
	}
}
