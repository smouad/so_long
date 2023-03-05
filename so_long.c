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

void	check_all(t_map *map_info)
{
	t_player *player;

	player = position(map_info->map);
	closed_rec(map_info);
	check_comp(map_info);
	map_info->map = fill_around(map_info, player->x, player->y);
	check_map(map_info);
}
int main(int ac, char **av)
{
	t_map *map_info;
	int fd = open(av[1], O_RDONLY);
	map_info = map(fd);
	check_all(map_info);
	int i = 0;
	while (map_info->map[i])
	{
		printf("%s\n", map_info->map[i]);
		i++;
	}
}