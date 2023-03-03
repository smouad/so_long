/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_comp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:20:18 by msodor            #+#    #+#             */
/*   Updated: 2023/03/03 23:48:05 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map *map(int fd)
{
	t_map *map_info;
	char *line;
	static char *one_line_map;

	map_info = malloc(sizeof(t_map));
	if (!map_info)
		return (NULL);
	while ((line = get_next_line(fd)))
	{
		one_line_map = my_strjoin(one_line_map, line);
		free(line);
	}
	map_info->map = ft_split(one_line_map, '\n');
	return (map_info);
}

int check_comp(t_map *map_info)
{
	int y;
	int x;
	int PE_count;
	int C_count;

	y = 0;
	PE_count = 0;
	C_count = 0;
	while (map_info->map[y])
	{
		x = 0;
		while (map_info->map[y][x])
		{
			if (ft_strchr("01CPE", map_info->map[y][x]) == 0)
				return (1);
			if (map_info->map[y][x] == 'P' || map_info->map[y][x] == 'E')
				PE_count++;
			if (map_info->map[y][x] == 'C')
				C_count++;
			x++;
		}
		y++;
	}
	if (C_count == 0 || PE_count != 2)
		return (1);
	return (0);
}

int closed_rec(t_map *map_info)
{
	int y;
	int x;
	int len;

	y = 0;
	x = 0;
	while (map_info->map[y + 1])
	{
		len = ft_strlen(map_info->map[y]);
		if (len != ft_strlen(map_info->map[y + 1]))
			return (1);
		if (map_info->map[y][0] != '1' || map_info->map[y][len - 1] != '1')
			return (1);
		y++;
	}
	while (map_info->map[0][x] && map_info->map[y][x])
	{
		if (map_info->map[0][x] != '1' || map_info->map[y][x] != '1')
			return (1);
		x++;
	}
	return (0);
}

char **fill_map(t_map *map_info)
{
}

int valid_path(t_map *map_info)
{
}