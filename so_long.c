/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:59:04 by msodor            #+#    #+#             */
/*   Updated: 2023/03/03 20:59:04 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_all(t_map *map)
{
	t_player *player;

	// player = position(map->map);
	// closed_rec(map);
	// check_comp(map);
	// fill_around(map, player->x, player->y);
	// check_map(map);
}

int main(int ac, char **av)
{
	t_map *map;
	if (ac != 2)
		exit(0);
	check_extention(av[1]);
	map = malloc(sizeof(t_map));
	int fd = open(av[1], O_RDONLY);
	get_map(fd, &map);
	check_all(map);
	int i = 0;
	while (map->map[i])
	{
		printf("%s\n", map->map[i]);
		i++;
	}
	i = 0;
	while (map->map2[i])
	{
		printf("%s\n", map->map2[i]);
		i++;
	}
}