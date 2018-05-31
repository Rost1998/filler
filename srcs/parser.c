/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:58:20 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/13 17:19:22 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		shift_map(char **map)
{
	int		n;
	int		j;

	while (map && *map)
	{
		n = 4;
		while (n--)
		{
			j = 0;
			while ((*map)[j])
			{
				(*map)[j] = (*map)[j + 1];
				++j;
			}
		}
		++map;
	}
}

static char		**read_lines(int n)
{
	char	**arr;
	char	*line;
	int		lns;

	arr = 0;
	lns = 1;
	while (n--)
	{
		get_next_line(0, &line);
		if (!(arr = (char**)ft_realloc_modf(arr, (lns + 1) * sizeof(char*),
												lns * sizeof(char*))))
			return (0);
		arr[lns - 1] = line;
		++lns;
	}
	return (arr);
}

static int		get_num(void)
{
	char	*line;
	int		i;
	int		num;

	line = 0;
	get_next_line(0, &line);
	i = 0;
	while (line && line[i] && !ft_isdigit(line[i]))
		++i;
	num = line ? ft_atoi(&line[i]) : 0;
	line ? free(line) : 0;
	return (num);
}

static void		get_side(void)
{
	char	*line;

	line = 0;
	get_next_line(0, &line);
	if (ft_strstr(line, "p1"))
	{
		g_me = 'O';
		g_enemy = 'X';
	}
	else if (ft_strstr(line, "p2"))
	{
		g_me = 'X';
		g_enemy = 'O';
	}
	free(line);
}

void			parser(char **map, char **piece)
{
	char		*tmp;
	int			n;

	tmp = 0;
	get_side();
	g_first_game = 1;
	while (1)
	{
		n = get_num();
		get_next_line(0, &tmp);
		tmp ? free(tmp) : 0;
		map = read_lines(n);
		shift_map(map);
		g_first_game ? handle_placed(map) : 0;
		n = get_num();
		piece = read_lines(n);
		if (!check_valid(map, piece))
			return ;
		if (!gen_coords(map, piece))
			return ;
	}
}
