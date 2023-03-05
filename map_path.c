/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:24:02 by msodor            #+#    #+#             */
/*   Updated: 2023/03/04 16:24:02 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	*position(char **map)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->y = 0;
	while (map[player->y])
	{
		player->x = 0;
		while (map[player->y][player->x])
		{
			if (map[player->y][player->x] == 'P')
				return (player);
			player->x++;
		}
		player->y++;
	}
	return (0);
}

char	**fill_around(t_map *map, int x, int y)
{
	map->map[y][x] = 'X';
	if (ft_strchr("0EC", map->map[y - 1][x]))
		fill_around(map, x, y - 1);
	if (ft_strchr("0EC", map->map[y + 1][x]))
		fill_around(map, x, y + 1);
	if (ft_strchr("0EC", map->map[y][x + 1]))
		fill_around(map, x + 1, y);
	if (ft_strchr("0EC", map->map[y][x - 1]))
		fill_around(map, x - 1, y);
	return (map->map);
}

void	check_map(t_map *map)
{
	map->y = 0;
	map->P_count = 0;
	map->E_count = 0;
	map->C_count = 0;
	while (map->map[map->y])
	{
		map->x = 0;
		while (map->map[map->y][map->x])
		{
			if (map->map[map->y][map->x] == 'P')
				map->P_count++;
			if (map->map[map->y][map->x] == 'E')
				map->E_count++;
			if (map->map[map->y][map->x] == 'C')
				map->C_count++;
			map->x++;
		}
		map->y++;
	}
	if (map->C_count != 0 || map->E_count != 0 || map->P_count != 0)
		error();
}
