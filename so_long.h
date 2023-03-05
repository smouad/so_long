/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor@student.1337.ma <msodor>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:51:49 by msodor            #+#    #+#             */
/*   Updated: 2023/03/05 15:03:21 by msodor@stud      ###   ########.fr       */
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

void error(void);
t_map *map(int fd);
void check_comp(t_map *map);
void closed_rec(t_map *map);
char **fill_around(t_map *map, int x, int y);
t_player *position(char **map);
void	check_map(t_map *map);

#endif