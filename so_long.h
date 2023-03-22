/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor@student.1337.ma <msodor>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:51:49 by msodor            #+#    #+#             */
/*   Updated: 2023/03/22 14:58:24 by msodor@stud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include <stdlib.h>

typedef struct s_gmae
{
	char **map;
	char **map2;
	int player_x;
	int player_y;
	int x;
	int y;
	int E_count;
	int P_count;
	int C_count;
} t_game;

void	error(void);
void	get_map(int fd, t_game *game);
void	check_comp(t_game game);
void	closed_rec(t_game *game);
void	fill_around(t_game game, int x, int y);
int	position(t_game game);
void	check_map(t_game game);
void	check_extention(char *str);

#endif