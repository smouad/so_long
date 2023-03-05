/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_comp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor@student.1337.ma <msodor>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:20:18 by msodor            #+#    #+#             */
/*   Updated: 2023/03/05 13:17:35 by msodor@stud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*map(int fd)
{
	t_map		*map;
	char		*line;
	static char	*one_line_map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (!ft_strncmp("\n", line, 1))
			error();
		one_line_map = my_strjoin(one_line_map, line);
		line = get_next_line(fd);
		// free(line);
	}
	map->map = ft_split(one_line_map, '\n');
	return (map);
}

void	check_comp(t_map *map)
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
				error();
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
		error();
}
