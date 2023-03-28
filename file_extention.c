/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_extention.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:47:08 by msodor@stud       #+#    #+#             */
/*   Updated: 2023/03/28 11:55:29 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extention(char *str)
{
	char	**s;

	s = ft_split(str, '.');
	if (!s[0] || !s[1] || s[2] || ft_strncmp(s[1], "ber", 3))
	{
		my_free(s);
		error();
	}
	my_free(s);
}
