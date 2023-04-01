/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:49:20 by msodor@stud       #+#    #+#             */
/*   Updated: 2023/03/27 14:13: by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->wind);
	mlx_destroy_image(game->mlx, game->hero.img);
	mlx_destroy_image(game->mlx, game->bg.img);
	mlx_destroy_image(game->mlx, game->wall.img);
	mlx_destroy_image(game->mlx, game->coin.img);
	mlx_destroy_image(game->mlx, game->exit.img);
	my_free(game->map);
	my_free(game->map2);
	free(game->mlx);
	exit(0);
}

void	win(t_game *game)
{
	ft_printf("You won\n");
	destroy(game);
}

int	press_cross(t_game *game)
{
	destroy(game);
	return (0);
}

int	keypress_listener(int key_code, t_game *game)
{
	move_handle(key_code, game);
	if (key_code == 53)
		destroy(game);
	return (0);
}
