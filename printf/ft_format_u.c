/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:14:23 by thlefebv          #+#    #+#             */
/*   Updated: 2023/05/04 12:14:25 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbr_u(unsigned int n)
{
	int		index;
	int		length;
	char	cara[12];

	length = 0;
	index = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		length++;
	}
	while (n != 0)
	{
		cara[index] = (n % 10) + '0';
		n = n / 10;
		index++;
	}
	while (index > 0)
	{
		index--;
		write(1, &cara[index], 1);
		length++;
	}
	return (length);
}
