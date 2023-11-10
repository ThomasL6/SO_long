/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:19:10 by thlefebv          #+#    #+#             */
/*   Updated: 2023/05/04 18:17:25 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf_s(char *s);
int	ft_putchar_prct(void);
int	ft_putnbr_i(int n);
int	ft_putnbr_u(unsigned int n);
int	ft_putchar_c(char c);
int	ft_printf(const char *c, ...);
int	ft_putnbr_x(unsigned int n);
int	ft_putnbr_majx(unsigned int n);
int	ft_puthexa_p(void *n);

#endif
