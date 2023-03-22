/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_comp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor@student.1337.ma <msodor>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:20:18 by msodor            #+#    #+#             */
/*   Updated: 2023/03/22 15:23:39 by msodor@stud      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_map(int fd, t_game *game)
{
	char		*line;
	static char	*one_line_map;
	static char	*one_line_map2;

	line = get_next_line(fd);
	while (line)
	{
		if (!ft_strncmp("\n", line, 1))
			error();
		one_line_map = my_strjoin(one_line_map, line);
		line = get_next_line(fd);
		free(line);
	}
	game->map = ft_split(one_line_map, '\n');
	// one_line_map2 = ft_strdup(one_line_map);
	// game->map2 = ft_split(one_line_map2, '\n');
}

void	check_comp(t_game game)
{
	game.y = 0;
	game.P_count = 0;
	game.E_count = 0;
	game.C_count = 0;
	while (game.map[game.y])
	{
		game.x = 0;
		while (game.map[game.y][game.x])
		{
			if (ft_strchr("01CPE", game.map[game.y][game.x]) == 0)
				error();
			if (game.map[game.y][game.x] == 'P')
				game.P_count++;
			if (game.map[game.y][game.x] == 'E')
				game.E_count++;
			if (game.map[game.y][game.x] == 'C')
				game.C_count++;
			game.x++;
		}
		game.y++;
	}
	if (game.C_count == 0 || game.E_count != 1 || game.P_count != 1)
		error();
}
