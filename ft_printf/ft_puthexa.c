/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:48:24 by msodor            #+#    #+#             */
/*   Updated: 2022/11/01 19:56:02 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(unsigned int n, char format, int *counter)
{
	char	*base;
	char	*base2;

	base = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	if (n < 16 && format == 'X')
	{
		ft_putchar(base2[n], counter);
	}
	else if (n < 16 && format == 'x')
	{
		ft_putchar(base[n], counter);
	}
	else
	{
		ft_puthexa(n / 16, format, counter);
		ft_puthexa(n % 16, format, counter);
	}
}
