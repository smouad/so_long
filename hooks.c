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

int	press_cross(int key_code, t_game *game)
{
	(void) key_code;
	mlx_destroy_window(game->mlx, game->wind);
	return (0);
}

int	keypress_listener(int key_code, t_game *game)
{
	move_handle(key_code, game);
	if (key_code == 53)
	{
		mlx_destroy_window(game->mlx, game->wind);
		exit(0); 
	} 
	return (0); 
}