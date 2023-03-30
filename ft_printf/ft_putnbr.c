/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:12:29 by msodor            #+#    #+#             */
/*   Updated: 2022/10/31 21:40:41 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long int n, int *counter)
{
	if (n < 0)
	{
		ft_putchar('-', counter);
		n *= -1;
	}
	if (n < 10)
		ft_putchar(n + '0', counter);
	else
	{
		ft_putnbr(n / 10, counter);
		ft_putnbr(n % 10, counter);
	}
}
