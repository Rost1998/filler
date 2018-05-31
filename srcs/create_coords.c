/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_coords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 19:32:20 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/13 17:53:11 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		subtraction(t_coords *new)
{
	int		i;

	i = check_min(new->shape_x, new->number);
	while ((new->shape_x)[i])
	{
		plus_minus(new->shape_x, new->number, 0);
		--*(new->main_point);
	}
	i = check_min(new->shape_y, new->number);
	while ((new->shape_y)[i])
	{
		plus_minus(new->shape_y, new->number, 0);
		--*(new->main_point + 1);
	}
}

static void		assignment(t_coords *new, int num, int x, int y)
{
	if (!(new->shape_x = (int*)ft_realloc_modf(new->shape_x,
					sizeof(int) * num, sizeof(int) * (num - 1))) ||
		!(new->shape_y = (int*)ft_realloc_modf(new->shape_y,
					sizeof(int) * num, sizeof(int) * (num - 1))))
		return ;
	(new->shape_x)[num - 1] = x;
	(new->shape_y)[num - 1] = y;
}

static void		shift_coords(t_coords *new, char **piece)
{
	int		num;
	int		x;
	int		y;

	num = 1;
	x = 0;
	while (piece && piece[x])
	{
		y = 0;
		while (piece[x][y])
		{
			if (piece[x][y] == '*')
			{
				assignment(new, num, x, y);
				++num;
			}
			++y;
		}
		++x;
	}
	new->number = num - 1;
	subtraction(new);
}

t_coords		*create_coords(char **piece)
{
	t_coords	*new;

	if (!(new = ft_memalloc(sizeof(t_coords))))
		return (0);
	if (!(new->main_point = ft_memalloc(sizeof(int) * 2)))
		return (0);
	*(new->main_point) = 0;
	*(new->main_point + 1) = 0;
	new->shape_x = 0;
	new->shape_y = 0;
	new->decisions = 0;
	shift_coords(new, piece);
	return (new);
}
