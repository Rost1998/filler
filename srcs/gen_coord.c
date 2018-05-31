/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:50:12 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/14 17:49:54 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	add_decision(t_coords *coords, int dcns)
{
	if (!(coords->decisions = (int**)ft_realloc_modf(coords->decisions,
												sizeof(int*) * (dcns + 1),
												sizeof(int*) * dcns)))
		return ;
	if (!((coords->decisions)[dcns - 1] = ft_memalloc(sizeof(int*) * 2)))
		return ;
	(coords->decisions)[dcns - 1][0] = *(coords->main_point);
	(coords->decisions)[dcns - 1][1] = *(coords->main_point + 1);
}

static void	ret_state_y(t_coords *coords, int n)
{
	while (n--)
	{
		plus_minus(coords->shape_y, coords->number, 0);
		--*(coords->main_point + 1);
	}
}

static void	search_decisions(char **map, t_coords *coords)
{
	int		max_x;
	int		max_y;
	int		n;
	int		dcns;

	n = 0;
	dcns = 0;
	max_x = check_max(coords->shape_x, coords->number);
	max_y = check_max(coords->shape_y, coords->number);
	while (map[(coords->shape_x)[max_x]])
	{
		ret_state_y(coords, n);
		n = 0;
		while (map[(coords->shape_x)[max_x]][(coords->shape_y)[max_y]])
		{
			if (ft_check_place(map, coords) &&\
					++dcns)
				add_decision(coords, dcns);
			plus_minus(coords->shape_y, coords->number, 1);
			++*(coords->main_point + 1);
			++n;
		}
		plus_minus(coords->shape_x, coords->number, 1);
		++*(coords->main_point);
	}
}

static void	ft_memfree(char **map, char **piece, t_coords *coords)
{
	int		i;

	i = 0;
	while (map && map[i])
		free(map[i++]);
	map ? free(map) : 0;
	i = 0;
	while (piece && piece[i])
		free(piece[i++]);
	piece ? free(piece) : 0;
	coords->main_point ? free(coords->main_point) : 0;
	coords->shape_x ? free(coords->shape_x) : 0;
	coords->shape_y ? free(coords->shape_y) : 0;
	i = 0;
	while (coords->decisions && (coords->decisions)[i])
		free((coords->decisions)[i++]);
	coords->decisions ? free(coords->decisions) : 0;
	coords ? free(coords) : 0;
}

_Bool		gen_coords(char **map, char **piece)
{
	t_coords	*coords;
	char		*num;
	int			i;

	coords = create_coords(piece);
	search_decisions(map, coords);
	if (coords->decisions)
	{
		i = ft_choose_decision(map, piece, coords, 0);
		num = ft_itoa(*((coords->decisions)[i]));
		ft_putstr(num);
		free(num);
		write(1, " ", 1);
		num = ft_itoa(*((coords->decisions)[i] + 1));
		ft_putstr(num);
		free(num);
		write(1, "\n", 1);
		i = 1;
	}
	else if (!(i = 0))
		write(1, "0 0\n", 4);
	ft_memfree(map, piece, coords);
	return (i);
}
