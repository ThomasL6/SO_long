/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:59:48 by thlefebv          #+#    #+#             */
/*   Updated: 2023/05/02 14:59:53 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_x(unsigned int n)
{
	int	length;

	length = 0;
	if (n >= 16)
	{
		length = length + ft_putnbr_x(n / 16);
		n = n % 16;
	}
	if (n <= 9)
		length = length + ft_putchar_c(n + 48);
	else
		length = length + ft_putchar_c((n - 10) + 'a');
	return (length);
}
