/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialising.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:07:16 by msodor@stud       #+#    #+#             */
/*   Updated: 2023/03/30 13:12:30 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->wind = mlx_new_window(game->mlx, \
		game->x * 50, game->y * 50, "so_long");
	images(game);
	if (!game->mlx || !game->wind)
		error();
}

void	images(t_game *game)
{
	game->wall.img = mlx_xpm_file_to_image(game->mlx, \
		"./textures/wall.xpm", &game->wall.img_w, &game->wall.img_h);
	game->hero.img = mlx_xpm_file_to_image(game->mlx, \
		"./textures/hero.xpm", &game->hero.img_w, &game->hero.img_h);
	game->bg.img = mlx_xpm_file_to_image(game->mlx, \
		"./textures/bg.xpm", &game->bg.img_w, &game->bg.img_h);
	game->coin.img = mlx_xpm_file_to_image(game->mlx, \
		"./textures/coin.xpm", &game->coin.img_w, &game->coin.img_h);
	game->exit.img = mlx_xpm_file_to_image(game->mlx, \
		"./textures/exit.xpm", &game->exit.img_w, &game->exit.img_h);
	if (!game->wall.img || !game->bg.img || !game->coin.img || !game->exit.img \
		|| !game->hero.img)
		error();
}

void	put_img(t_game game)
{
	if (game.map[game.f.i][game.f.j] == '1')
		mlx_put_image_to_window(game.mlx, game.wind,
			game.wall.img, game.f.x, game.f.y);
	else if (game.map[game.f.i][game.f.j] == '0')
		mlx_put_image_to_window(game.mlx, game.wind,
			game.bg.img, game.f.x, game.f.y);
	else if (game.map[game.f.i][game.f.j] == 'P')
		mlx_put_image_to_window(game.mlx, game.wind,
			game.hero.img, game.f.x, game.f.y);
	else if (game.map[game.f.i][game.f.j] == 'C')
		mlx_put_image_to_window(game.mlx, game.wind,
			game.coin.img, game.f.x, game.f.y);
	else if (game.map[game.f.i][game.f.j] == 'E'\
	|| game.map[game.f.i][game.f.j] == 'e')
		mlx_put_image_to_window(game.mlx, game.wind,
			game.exit.img, game.f.x, game.f.y);
}

void	fill_screen(t_game game)
{
	game.f.y = 0;
	game.f.i = 0;
	while (game.map[game.f.i])
	{
		game.f.j = 0;
		game.f.x = 0;
		while (game.map[game.f.i][game.f.j])
		{
			put_img(game);
			game.f.x += 50;
			game.f.j++;
		}
		game.f.y += 50;
		game.f.i++;
	}
}
