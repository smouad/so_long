/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:44:30 by msodor            #+#    #+#             */
/*   Updated: 2022/11/01 19:56:13 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(unsigned int n, int *counter)
{
	if (n < 10)
		ft_putchar(n + '0', counter);
	else
	{
		ft_putnbr_u(n / 10, counter);
		ft_putnbr_u(n % 10, counter);
	}
}
