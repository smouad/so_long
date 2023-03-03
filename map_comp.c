/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_comp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:20:18 by msodor            #+#    #+#             */
/*   Updated: 2023/03/03 19:41:52 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*map(int fd)
{
	t_map		*map_info;
	char		*line;
	static char	*one_line_map;

	map_info = malloc(sizeof(t_map));
	if (!map_info)
		return (NULL);
	while ((line = get_next_line(fd)))
		one_line_map = my_strjoin(one_line_map, line);
	map_info->map = ft_split(one_line_map, '\n');
	return (map_info);
}

int	setchr(char c, char *set)
{
	int	i;
	i = 0;
	while (set[i])
	{
		if (c != set[i])
			return (1);
		i++;
	}
	return (0);
}

int check_comp(int fd)
{
	t_map	*map_info;
	int		y;
	int		x;

	map_info = map(fd);
	x = 0;
	y = 0;
	while (map_info->map[y])
	{
		while (map_info->map[y][x])
		{
			if (setchr(map_info->map[y][x], "0C1PE"))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int main()
{
	int fd = open("map", O_RDONLY);
	t_map *map_info = map(fd);
	if (check_comp(fd))
		printf("not valid");
	printf("valid");
	// int i = 0;
	// while (i < 3)
	// {
	// printf("%s\n", map_info->map[i]);
	// 	i++;
	// }
	
}