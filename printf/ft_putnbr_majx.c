/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_majx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:02:13 by thlefebv          #+#    #+#             */
/*   Updated: 2023/05/03 15:02:17 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_majx(unsigned int n)
{
	int	length;

	length = 0;
	if (n >= 16)
	{
		length = length + ft_putnbr_majx(n / 16);
		n = n % 16;
	}
	if (n <= 9)
	{
		length = length + ft_putchar_c(n + 48);
	}
	else
	{
		length = length + ft_putchar_c((n - 10) + 'A');
	}
	return (length);
}
