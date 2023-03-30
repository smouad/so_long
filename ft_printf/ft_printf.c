/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msodor <msodor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:58:14 by msodor            #+#    #+#             */
/*   Updated: 2022/11/05 22:34:32 by msodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	format_check(va_list args, const char format, int *counter)
{
	if (format == 'c')
		ft_putchar(va_arg(args, int), counter);
	else if (format == 's')
		ft_putstr(va_arg(args, char *), counter);
	else if (format == '%')
		ft_putchar('%', counter);
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), counter);
	else if (format == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), counter);
	else if (format == 'x' || format == 'X')
		ft_puthexa(va_arg(args, unsigned int), format, counter);
	else if (format == 'p')
		ft_putad(va_arg(args, unsigned long), counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;

	counter = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			format_check(args, *format, &counter);
		}
		else
			ft_putchar(*format, &counter);
		format++;
	}
	va_end(args);
	return (counter);
}
