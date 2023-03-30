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
