/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:19:23 by msodor            #+#    #+#             */
/*   Updated: 2022/11/01 19:57:11 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	hexa(unsigned long n, int *counter)
{
	char	*base;

	base = "0123456789abcdef";
	if (n < 16)
		ft_putchar(base[n], counter);
	else
	{
		hexa(n / 16, counter);
		hexa(n % 16, counter);
	}
}

void	ft_putad(unsigned long n, int *counter)
{
	ft_putstr("0x", counter);
	hexa(n, counter);
}
