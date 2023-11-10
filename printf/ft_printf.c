/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:02:54 by thlefebv          #+#    #+#             */
/*   Updated: 2023/05/02 15:50:20 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_typeconv(char symbconv, va_list list, int length)
{
	if (symbconv == 'c')
		length = length + (ft_putchar_c(va_arg(list, int)));
	else if (symbconv == 's')
		length = length + (ft_printf_s(va_arg(list, char *)));
	else if (symbconv == '%')
		length = length + (ft_putchar_c('%'));
	else if (symbconv == 'x')
		length = length + (ft_putnbr_x(va_arg(list, int)));
	else if (symbconv == 'X')
		length = length + (ft_putnbr_majx(va_arg(list, int)));
	else if (symbconv == 'i' || symbconv == 'd')
		length = length + (ft_putnbr_i(va_arg(list, int)));
	else if (symbconv == 'p')
		length = length + (ft_puthexa_p(va_arg(list, void *)));
	else if (symbconv == 'u')
		length = length + (ft_putnbr_u(va_arg(list, int)));
	return (length);
}

int	ft_printf(const char *c, ...)
{
	int		index;
	int		length;
	va_list	list;

	index = 0;
	length = 0;
	va_start(list, c);
	while (c[index] != '\0')
	{
		if (c[index] == '%')
		{
			index++;
			length = ft_typeconv(c[index], list, length);
		}
		else
			length += ft_putchar_c(c[index]);
		index++;
	}
	va_end (list);
	return (length);
}
