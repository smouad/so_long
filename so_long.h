/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:51:49 by msodor            #+#    #+#             */
/*   Updated: 2023/03/28 15:05:51 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <mlx.h>

# define A 0
# define S 1
# define D 2
# define W 13


typedef struct s_img
{
	void	*img;
	int		img_w;
	int		img_h;
}	t_img;

typedef struct s_fill
{
	int	x;
	int	y;
	int	i;
	int	j;
}	t_fill;

typedef struct s_exit
{
	int	exit_x;
	int	exit_y;
}	t_exit;

typedef struct s_game
{
	char	**map;
	char	**map2;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		x;
	int		y;
	int		e_count;
	int		p_count;
	int		c_count;
	void	*mlx;
	void	*wind;
	t_img	hero;
	t_img	bg;
	t_img	wall;
	t_img	exit;
	t_img	coin;
	t_fill	f;
}	t_game;

void	error(void);
void	my_free(char **str);
void	get_map(int fd, t_game *game);
void	player_position(t_game *game);
void	exit_position(t_game *game);
void	fill_around(t_game game, int x, int y);
void	check_comp(t_game game);
void	check_shape(t_game game);
void	check_path(t_game *game);
void	check_extention(char *str);

void	game_init(t_game *game);
void	images(t_game *game);
void	fill_screen(t_game game);
int		press_cross(int key_code, t_game *game);
int		keypress_listener(int key_code, t_game *game);
void	move_handle(int keycode, t_game *game);

#endif