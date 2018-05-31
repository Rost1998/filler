/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:37:08 by rtulchiy          #+#    #+#             */
/*   Updated: 2018/02/13 18:23:12 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"
# include "libft.h"

# define ABS(x) ((x) > 0 ? (x) : (x) * -1 )
# define DIFF ('a' - 'A')

/*
** placed[0] - 0: high x; 1: low x;
** placed[1] - 0: left y; 1: right y;
*/

_Bool			g_first_game;
char			g_me;
char			g_enemy;
int				*g_placed;

typedef struct	s_coords
{
	int			*main_point;
	int			*shape_x;
	int			*shape_y;
	int			**decisions;
	int			number;
}				t_coords;

void			parser(char **map, char **piece);
_Bool			ft_check_place(char **map, t_coords *coords);
_Bool			gen_coords(char **map, char **piece);
t_coords		*create_coords(char **piece);
void			plus_minus(int *nums, int len, _Bool code);
int				check_min(int *nums, int len);
int				check_max(int *nums, int len);
void			*ft_realloc_modf(void *ptr, size_t newsize, size_t oldsize);
int				ft_choose_decision(char **map, char **piece,
												t_coords *coords, int i);
int				diff_distance(int x1, int y1, int x2, int y2);
int				*get_aim(char **map);
int				ft_adrlen(void **ptr);
void			choose_aim_attack(char **map, int *aim);
void			choose_aim_second(char **map, int *aim, int *mp, int *ep);
void			choose_aim_first(char **map, int *aim, int *mp, int *ep);
int				*get_player_points(char **map, char player);
void			handle_placed(char **map);
int				check_valid(char **map, char **piece);

#endif
