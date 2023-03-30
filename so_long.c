/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:59:04 by msodor            #+#    #+#             */
/*   Updated: 2023/03/03 20:59:04 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_all(t_game *game)
{
	check_shape(*game);
	check_comp(*game);
	check_path(game);
}

int	main(int ac, char **av)
{
	t_game	game;
	t_exit	ex;
	int		fd;

	if (ac != 2)
		exit(0);
	check_extention(av[1]);
	fd = open(av[1], O_RDONLY);
	get_map(fd, &game);
	check_all(&game);
	game_init(&game);
	fill_screen(game);
	game.moves = 0;
	mlx_hook(game.wind, 2, 0, keypress_listener, &game);
	mlx_hook(game.wind, 17, 0, press_cross, &game);
	mlx_loop(game.mlx);
	exit(0);
}
