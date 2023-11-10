/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:26:07 by thlefebv          #+#    #+#             */
/*   Updated: 2023/05/04 11:26:09 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_ibis(int n, unsigned int prct_i, int index, int length)
{
	char		cara[13];

	if (n < 0)
	{
		write(1, "-", 1);
		prct_i = -n;
		length++;
	}
	while (prct_i != 0)
	{
		cara[index] = (prct_i % 10) + '0';
		prct_i = prct_i / 10;
		length++;
		index++;
	}
	while (index-- > 0)
		ft_putchar_c(cara[index]);
	if (n == 0)
	{
		write(1, "0", 1);
		length++;
	}
	return (length);
}

int	ft_putnbr_i(int n)
{
	int					length;
	int					index;
	unsigned int		unb;

	unb = n;
	index = 0;
	length = 0;
	return (ft_putnbr_ibis(n, unb, index, length));
}
