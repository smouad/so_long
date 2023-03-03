/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:48:25 by msodor            #+#    #+#             */
/*   Updated: 2023/03/03 19:14:33 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_first(char *stat)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!stat[i])
		return (NULL);
	while (stat[i] != '\n' && stat[i])
		i++;
	if (stat[i] == '\n')
		line = malloc(i + 2);
	else
		line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = stat[j];
		j++;
	}
	if (stat[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*get_rest(char *stat)
{
	int		j;
	int		i;
	char	*rest;

	j = 0;
	i = 0;
	while (stat && stat[i] && stat[i] != '\n')
		i++;
	if (stat[i] == '\0')
	{
		free(stat);
		return (NULL);
	}
	if (stat[i] == '\n')
		i++;
	rest = malloc(my_strlen(stat) - i + 1);
	while (stat && stat[i])
		rest[j++] = stat[i++];
	rest[j] = '\0';
	free(stat);
	return (rest);
}

char	*readfd(int fd, char *stat)
{
	int			reading_index;
	char		*buffer;

	reading_index = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (reading_index && my_strchr(stat, '\n') == 0)
	{
		reading_index = read(fd, buffer, BUFFER_SIZE);
		if (reading_index < 0)
		{
			free(stat);
			free(buffer);
			return (NULL);
		}
		buffer[reading_index] = '\0';
		stat = my_strjoin(stat, buffer);
	}
	free(buffer);
	return (stat);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stat;

	stat = readfd(fd, stat);
	if (!stat)
		return (NULL);
	line = get_first(stat);
	stat = get_rest(stat);
	return (line);
}
