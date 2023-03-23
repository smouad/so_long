/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:14:37 by msodor            #+#    #+#             */
/*   Updated: 2023/03/04 16:14:37 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_shape(t_game game)
{
	int	len;

	game.y = 0;
	game.x = 0;
	while (game.map[game.y + 1])
	{
		len = ft_strlen(game.map[game.y]);
		if (len != ft_strlen(game.map[game.y + 1]))
			error();
		if (game.map[game.y][0] != '1' || game.map[game.y][len - 1] != '1')
			error();
		game.y++;
	}
	while (game.map[0][game.x] && game.map[game.y][game.x])
	{
		if (game.map[0][game.x] != '1' || game.map[game.y][game.x] != '1')
			error();
		game.x++;
	}
}
