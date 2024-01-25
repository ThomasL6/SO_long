/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:52:18 by thlefebv          #+#    #+#             */
/*   Updated: 2023/11/03 13:52:20 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	check_form(t_data *data)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (data->map[0][count])
		count++;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
			x++;
		if (x != count)
		{
			ft_printf("Error\nMap is not a rectangle\n");
			return (ERROR);
		}
		x = 0;
		y++;
	}
	return (VALID);
}

int	check_symbols(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (data->map[y] != NULL)
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] != 'E' && data->map[y][x] != 'C'
			&& data->map[y][x] != 'P' && data->map[y][x] != 'V'
			&& data->map[y][x] != '1' && data->map[y][x] != '0')
			{
				ft_printf("Error\nunknown symbols\n");
				return (ERROR);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (VALID);
}

void	count_symb(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->map[++y] != NULL)
	{
		x = 0;
		while (data->map[y][x++])
		{
			if (data->map[y][x] == 'E')
				data->content.count_e = data->content.count_e + 1;
			if (data->map[y][x] == 'P')
				data->content.count_p = data->content.count_p + 1;
			if (data->map[y][x] == 'C')
				data->content.count_c = data->content.count_c + 1;
		}
	}
}

int	count_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	check_walls(t_data *data)
{
	int	y;
	int	x;

	data->height = count_lines(data->map);
	data->width = ft_strlen(data->map[0]);
	y = -1;
	while (data->map[++y])
	{
		if (data->map[y][0] != '1' || data->map[y][data->width - 1] != '1')
			return (ERROR);
		if (y == 0 || y == data->height - 1)
		{
			x = -1;
			while (data->map[y][++x])
			{
				if (data->map[y][x] != '1')
					return (ERROR);
			}
		}
	}
	return (VALID);
}
