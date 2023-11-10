/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:30:19 by thlefebv          #+#    #+#             */
/*   Updated: 2023/05/03 17:30:21 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthexa_p_bis(void *n, int i, unsigned long unb, int length)
{
	char	c[20];
	char	*hexa;

	hexa = "0123456789abcdef";
	if (n == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write (1, "0", 1);
	write (1, "x", 1);
	while (unb != 0)
	{
		c[i] = hexa[unb % 16];
		unb = unb / 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		write(1, &c[i], 1);
		length++;
	}
	return (length + 2);
}

int	ft_puthexa_p(void *n)
{
	int					length;
	int					i;
	unsigned long		unb;

	unb = (unsigned long int) n;
	i = 0;
	length = 0;
	return (ft_puthexa_p_bis(n, i, unb, length));
}
