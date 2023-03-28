/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_comp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:20:18 by msodor            #+#    #+#             */
/*   Updated: 2023/03/28 16:18:58 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*join(char *s1, char *s2)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	if (s1 == NULL)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	len = my_strlen(s1) + my_strlen(s2);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	free(s2);
	return (str);
}
void	get_map(int fd, t_game *game)
{
	char	*line;
	char	*one_line_map;

	line = get_next_line(fd);
	if (line == NULL)
		error();
	while (line)
	{
		if (!ft_strncmp("\n", line, 1))
			error();
		one_line_map = join(one_line_map, line);
		line = get_next_line(fd);
	}
	game->map = ft_split(one_line_map, '\n');
	game->map2 = ft_split(one_line_map, '\n');
	free(one_line_map);
	player_position(game);
}

void	check_comp(t_game game)
{
	game.y = 0;
	game.p_count = 0;
	game.e_count = 0;
	game.c_count = 0;
	while (game.map[game.y])
	{
		game.x = 0;
		while (game.map[game.y][game.x])
		{
			if (ft_strchr("01CPE", game.map[game.y][game.x]) == 0)
				error();
			if (game.map[game.y][game.x] == 'P')
				game.p_count++;
			if (game.map[game.y][game.x] == 'E')
				game.e_count++;
			if (game.map[game.y][game.x] == 'C')
				game.c_count++;
			game.x++;
		}
		game.y++;
	}
	if (game.c_count == 0 || game.e_count != 1 || game.p_count != 1)
		error();
}
