/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_comp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:20:18 by msodor            #+#    #+#             */
/*   Updated: 2023/03/04 16:14:34 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map *map(int fd)
{
	t_map *map;
	char *line;
	static char *one_line_map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	while ((line = get_next_line(fd)))
	{
		one_line_map = my_strjoin(one_line_map, line);
		free(line);
	}
	map->map = ft_split(one_line_map, '\n');
	return (map);
}

int check_comp(t_map *map)
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
			if (ft_strchr("01CPE", map->map[map->y][map->x]) == 0)
				return (1);
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
	if (map->C_count == 0 || map->E_count != 1 || map->P_count != 1)
		return (1);
	return (0);
}
