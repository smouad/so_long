/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:19:36 by msodor            #+#    #+#             */
/*   Updated: 2023/03/03 19:12:29 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 29
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		my_strlen(char *str);
int		my_strchr(char *str, char c);
char	*my_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif