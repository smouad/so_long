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

int main(int ac, char **av)
{
	t_game game;
	if (ac != 2)
		exit(0);
	check_extention(av[1]);
	int fd = open(av[1], O_RDONLY);
	get_map(fd, &game);
	check_all(&game);
	int i = 0;
	
}