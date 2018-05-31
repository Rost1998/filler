/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_decision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 21:14:55 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/13 18:00:28 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_tmp_memfree(t_coords *tmp, int *nps)
{
	nps ? free(nps) : 0;
	tmp->main_point ? free(tmp->main_point) : 0;
	tmp->shape_x ? free(tmp->shape_x) : 0;
	tmp->shape_y ? free(tmp->shape_y) : 0;
	tmp ? free(tmp) : 0;
}

static void		shift_shape(t_coords *tmp, int *mp)
{
	while (*(tmp->main_point) != *mp)
	{
		plus_minus(tmp->shape_x, tmp->number, 1);
		++*(tmp->main_point);
	}
	while (*(tmp->main_point + 1) != *(mp + 1))
	{
		plus_minus(tmp->shape_y, tmp->number, 1);
		++*(tmp->main_point + 1);
	}
}

static int		*get_near_shape(t_coords *tmp, int *aim)
{
	int		*nps;
	int		len;
	int		nearest;

	if (!(nps = (int*)ft_memalloc(sizeof(int) * 2)))
		nearest = -1;
	len = tmp->number;
	while (len--)
	{
		if (nearest == -1 ||\
				diff_distance((tmp->shape_x)[len], (tmp->shape_y)[len],
							*aim, *(aim + 1)) < nearest)
		{
			nearest = diff_distance((tmp->shape_x)[len], (tmp->shape_y)[len],
									*aim, *(aim + 1));
			nps[0] = (tmp->shape_x)[len];
			nps[1] = (tmp->shape_y)[len];
		}
	}
	return (nps);
}

int				ft_choose_decision(char **map, char **piece,
											t_coords *coords, int i)
{
	t_coords	*tmp;
	int			*aim;
	int			*nps;
	int			tmp_indx;
	int			id;

	aim = get_aim(map);
	id = -1;
	tmp_indx = -1;
	while ((coords->decisions)[i])
	{
		tmp = create_coords(piece);
		shift_shape(tmp, (coords->decisions)[i]);
		nps = get_near_shape(tmp, aim);
		if (id == -1 || (tmp_indx != -1 && diff_distance(*aim, *(aim + 1),
											*nps, *(nps + 1)) < tmp_indx))
		{
			tmp_indx = diff_distance(*aim, *(aim + 1), *nps, *(nps + 1));
			id = i;
		}
		++i;
		ft_tmp_memfree(tmp, nps);
	}
	free(aim);
	return (id);
}
