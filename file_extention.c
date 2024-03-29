/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_extention.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:47:08 by msodor@stud       #+#    #+#             */
/*   Updated: 2023/03/30 14:00:14 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extention(char *str)
{
	char	*s;
	char	*ext;
	int		i;

	i = 0;
	s = ft_strchr(str, '.');
	if (!s)
		error();
	if (ft_strlen(str) <= 4 || ft_strlen(s) > 4)
		error();
	ext = ".ber";
	while (s[i] && ext[i])
	{
		if (s[i] != ext[i])
			error();
		i++;
	}
}
