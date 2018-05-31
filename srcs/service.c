/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 19:32:16 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/13 17:45:22 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			ft_adrlen(void **ptr)
{
	int		i;

	i = 0;
	while (*ptr++)
		++i;
	return (i);
}

int			diff_distance(int x1, int y1, int x2, int y2)
{
	int		dx;
	int		dy;

	dx = x1 - x2;
	dx = ABS(dx);
	dy = y1 - y2;
	dy = ABS(dy);
	return (dx + dy);
}

void		plus_minus(int *nums, int len, _Bool code)
{
	int		i;

	i = 0;
	while (len--)
	{
		nums[i] = !code ? nums[i] - 1 : nums[i] + 1;
		++i;
	}
}

int			check_min(int *nums, int len)
{
	int		min;

	min = -1;
	while (len--)
		if (nums[min] > nums[len] || min == -1)
			min = len;
	return (min);
}

int			check_max(int *nums, int len)
{
	int		max;

	max = -1;
	while (len--)
		if (nums[max] < nums[len] || max == -1)
			max = len;
	return (max);
}
