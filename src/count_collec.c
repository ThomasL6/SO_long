/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_collec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:05:10 by thlefebv          #+#    #+#             */
/*   Updated: 2023/12/01 11:05:13 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	check_collec(t_data *data)
{
	if (data->content.count_c == 0)
	{
		if (data->content.count_e == 0)
		{
			ft_printf("Nombre de mouvement %d\nCongrats, you won", data->move);
			end(data);
		}
	}
}

int	empty_map(t_data *data)
{
	int	x;
	int	y;
	int	tmp;

	x = 0;
	y = 0;
	tmp = 0;
	while (data->map[y] != NULL)
	{
		while (data->map[y][x] != '\0')
			x++;
		tmp = x;
		x = 0;
		y++;
	}
	if (tmp == y)
	{
		ft_printf("Error\nFile empty\n");
		return (1);
	}
	return (0);
}
