/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor@student.1337.ma <msodor>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:51:49 by msodor            #+#    #+#             */
/*   Updated: 2023/03/15 18:41:46 by msodor@stud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include <stdlib.h>

typedef struct s_map
{
	char **map;
	char **map2;
	int x;
	int y;
	int E_count;
	int P_count;
	int C_count;
} t_map;

typedef struct s_player
{
	int x;
	int y;
} t_player;

typedef struct s_game
{
	t_map map;
	t_player player;
} t_player;



void		error(void);
void		get_map(int fd, t_map **map);
void		check_comp(t_map *map);
void		closed_rec(t_map *map);
void		fill_around(t_map *map, int x, int y);
t_player	*position(char **map);
void		check_map(t_map *map);
void		check_extention(char *str);

#endif