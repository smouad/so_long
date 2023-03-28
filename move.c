/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:03:21 by msodor            #+#    #+#             */
/*   Updated: 2023/03/27 14:47:32by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	c_count(t_game *game)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
void	check_do(t_game	*game)
{

}
void	move(int x, int y, t_game *game)
{
	int	from_x;
	int	from_y;
	int	count = 0;

	from_x = game->player_x;
	from_y = game->player_y;
	game->c_count = c_count(game);
	if (ft_strchr("E1", game->map[game->player_y + y][game->player_x + x]) == 0)
	{
		game->player_x = game->player_x + x;
		game->player_y = game->player_y + y;
		if (game->map[game->player_y][game->player_x] == 'C')
			game->c_count--;
		game->map[from_y][from_x] = '0';
		game->map[game->player_y][game->player_x] = 'P';
		mlx_clear_window(game->mlx, game->wind);
		exit_position(game);
		fill_screen(*game);
		if (game->c_count == 0)
			game->map[game->exit_y][game->exit_x] = 'e';
		// else if (game->map[game->player_y][game->player_x] == 'e')
		// {

		// 	printf("you won\n");
		// 	// mlx_destroy_window(game->mlx, game->wind);
		// 	// exit(0);
		// }
	}
		count++;
			printf("moves:%d\n", count);
}

void	move_handle(int keycode, t_game *game)
{
	if (keycode == W || keycode == 126)
		move(0, -1, game);	
	if (keycode == S || keycode == 125)
		move(0, 1, game);
	if (keycode == A || keycode == 123)
		move(-1, 0, game);
	if (keycode == D || keycode == 124)
		move(1, 0, game);
}