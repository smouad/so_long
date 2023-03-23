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

void	position(t_game *game)
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

void	fill_around(t_game game, int x, int y)
{
	game.map2[y][x] = 'X';
	// printf("%c\n, %d %d", game.map[y + 1][x], y, x);
	if (ft_strchr("0EC", game.map2[y - 1][x]))
		fill_around(game, x, y - 1);
	if (ft_strchr("0EC", game.map2[y + 1][x]))
		fill_around(game, x, y + 1);
	if (ft_strchr("0EC", game.map2[y][x + 1]))
		fill_around(game, x + 1, y);
	if (ft_strchr("0EC", game.map2[y][x - 1]))
		fill_around(game, x - 1, y);
}

void	check_path(t_game *game)
{
	fill_around(*game, game->player_x, game->player_y);
	game->y = 0;
	game->P_count = 0;
	game->E_count = 0;
	game->C_count = 0;
	while (game->map2[game->y])
	{
		game->x = 0;
		while (game->map2[game->y][game->x])
		{
			if (game->map2[game->y][game->x] == 'P')
				game->P_count++;
			if (game->map2[game->y][game->x] == 'E')
				game->E_count++;
			if (game->map2[game->y][game->x] == 'C')
				game->C_count++;
			game->x++;
		}
		game->y++;
	}
	if (game->C_count != 0 || game->E_count != 0 || game->P_count != 0)
		error();
}
