/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:18:40 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/14 19:14:47 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_memfree_exit(char **map, char **piece)
{
	int		i;

	i = 0;
	while (map && map[i])
		free(map[i++]);
	i = 0;
	while (piece && piece[i])
		free(piece[i++]);
	map ? free(map) : 0;
	piece ? free(piece) : 0;
	return (0);
}

int			check_valid(char **map, char **piece)
{
	int		len;
	int		x;
	int		y;

	x = 0;
	if (!map || !piece)
		return (ft_memfree_exit(map, piece));
	len = ft_strlen(map[0]);
	while (map[x])
	{
		if ((int)ft_strlen(map[x]) != len)
			return (ft_memfree_exit(map, piece));
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] != '.' && map[x][y] != 'O' && map[x][y] != 'o' &&
					map[x][y] != 'X' && map[x][y] != 'x')
				return (ft_memfree_exit(map, piece));
			++y;
		}
		++x;
	}
	return (1);
}
