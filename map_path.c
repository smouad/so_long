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

void	player_position(t_game *game)
{
	game->player_y = 0;
	while (game->map[game->player_y])
	{
		game->player_x = 0;
		while (game->map[game->player_y][game->player_x])
		{
			if (game->map[game->player_y][game->player_x] == 'P')
				return ;
			game->player_x++;
		}
		game->player_y++;
	}
	return ;
}

void	exit_position(t_game *game)
{
	game->exit_y = 0;
	while (game->map[game->exit_y])
	{
		game->exit_x = 0;
		while (game->map[game->exit_y][game->exit_x])
		{
			if (game->map[game->exit_y][game->exit_x] == 'E'\
			|| game->map[game->exit_y][game->exit_x] == 'e')
				return ;
			game->exit_x++;
		}
		game->exit_y++;
	}
	return ;
}

void	fill_around(t_game game, int x, int y)
{
	game.map2[y][x] = 'X';
	if (ft_strchr("0C", game.map2[y - 1][x]))
		fill_around(game, x, y - 1);
	if (ft_strchr("0C", game.map2[y + 1][x]))
		fill_around(game, x, y + 1);
	if (ft_strchr("0C", game.map2[y][x + 1]))
		fill_around(game, x + 1, y);
	if (ft_strchr("0C", game.map2[y][x - 1]))
		fill_around(game, x - 1, y);
}

void	check_path(t_game *game)
{
	exit_position(game);
	fill_around(*game, game->player_x, game->player_y);
	game->y = 0;
	game->p_count = 0;
	game->c_count = 0;
	while (game->map2[game->y])
	{
		game->x = 0;
		while (game->map2[game->y][game->x])
		{
			if (game->map2[game->y][game->x] == 'P')
				game->p_count++;
			if (game->map2[game->y][game->x] == 'C')
				game->c_count++;
			game->x++;
		}
		game->y++;
	}
	if ((game->c_count != 0 || game->p_count != 0)
		|| !(game->map2[game->exit_y + 1][game->exit_x] == 'X'
		|| game->map2[game->exit_y - 1][game->exit_x] == 'X'
		|| game->map2[game->exit_y][game->exit_x + 1] == 'X'
		|| game->map2[game->exit_y][game->exit_x - 1] == 'X'))
		error();
}
