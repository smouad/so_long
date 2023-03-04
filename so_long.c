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

int main()
{
    int fd = open("map", O_RDONLY);
    t_map *map_info = map(fd);
    if (check_comp(map_info) || closed_rec(map_info))
        printf("not valid\n");
    printf("valid\n");
    t_player *player = position(map_info->map);
    // printf("%d\n", player->y);
    // printf("%d\n", player->x);
    map_info->map = fill_path(map_info, player);
    int i = 0;
    while (map_info->map[i])
    {
        printf("%s\n", map_info->map[i]);
        i++;
    }
}