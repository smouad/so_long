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

t_player *position(char **map)
{
	t_player *player;

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

char **fill_path(t_map *map, int x, int y)
{
	map->map[y][x] = 'X';
	if (ft_strchr("P0E", map->map[y - 1][x]))
		map->map[y - 1][x] = 'X';
	if (ft_strchr("P0E", map->map[y - 1][x - 1]))
		map->map[y - 1][x - 1] = 'X';
	if (ft_strchr("P0E", map->map[y - 1][x + 1]))
		map->map[y - 1][x + 1] = 'X';
	if (ft_strchr("P0E", map->map[y + 1][x]))
		map->map[y + 1][x] = 'X';
	if (ft_strchr("P0E", map->map[y + 1][x - 1]))
		map->map[y + 1][x - 1] = 'X';
	if (ft_strchr("P0E", map->map[y + 1][x + 1]))
		map->map[y + 1][x + 1] = 'X';
	if (ft_strchr("P0E", map->map[y][x + 1]))
		map->map[y][x + 1] = 'X';
	if (ft_strchr("P0E", map->map[y][x - 1]))
		map->map[y][x - 1] = 'X';
	return (map->map);
}

char **fill_all(t_map *map, t_player *player)
{
	int
}