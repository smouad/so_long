/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:51:49 by msodor            #+#    #+#             */
/*   Updated: 2023/03/03 23:16:39 by msodor           ###   ########.fr       */
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
} t_map;

t_map *map(int fd);
int setchr(char *set, char c);
int check_comp(t_map *map_info);
int closed_rec(t_map *map_info);

#endif