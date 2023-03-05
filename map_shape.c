/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:14:37 by msodor            #+#    #+#             */
/*   Updated: 2023/03/04 16:14:37 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	closed_rec(t_map *map)
{
	int	len;

	map->y = 0;
	map->x = 0;
	while (map->map[map->y + 1])
	{
		len = ft_strlen(map->map[map->y]);
		if (len != ft_strlen(map->map[map->y + 1]))
			error();
		if (map->map[map->y][0] != '1' || map->map[map->y][len - 1] != '1')
			error();
		map->y++;
	}
	while (map->map[0][map->x] && map->map[map->y][map->x])
	{
		if (map->map[0][map->x] != '1' || map->map[map->y][map->x] != '1')
			error();
		map->x++;
	}
}
