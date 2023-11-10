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

int	check_form(char **map)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	while (map[0][count])
		count++;
	while (map[x])
	{
		while (map[x][y])
			x++;
		if (x != count)
		{
			ft_printf("Error, map is not a rectangle\n");
			return (0);
		}
		y++;
	}
	return (1);
}

int	check_symbols(char **map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[x])
	{
		if (map[x][y] != 'E' && map[x][y] != 'C' && map[x][y] != 'P'
		&& map[x][y] != '1' && map[x][y] != '0' && map[x][y] != '\n')
		{
			ft_printf("Error, unknown symbols\n");
			return (0);
		}
		y++;
	}
	return (1);
}

int	too_much(char **map)
{
	int	x;
	int	y;
	int	count1;
	int	count2;

	x = 0;
	count1 = 0;
	count2 = 0;
	while(map[x])
	{
		y = 0;
		while(map[x][y] != '\n')
		{
			if(map[x][y] == 'E')
				count1++;
			else if(map[x][y] == 'P')
				count2++;
			y++;
		}
		x++;
	}
	if (count1 != '1' || count2 != '1')
	{
		ft_printf("Error, too many exits or starts");
		return (0);
	}
	return (1);
}

int count_lines(char **map)
{
    int i;

    i = 0;
    while(map[i])
        i++;
    return(i);
}

int check_walls(char **map)
{
    int x;
    int y;
    char character;

    x = 0;
    character = map[x][y];
    while(map[x])
    {
        y = 0;
        while(character != '\n')
        {
            if((x == 0 || y == 0) && character != '1')
                return(0);
            if (y == (ft_strlen(map[x]) - 1) && character != '1')
				return (0);
            if(x == (count_lines(map) - 1) && character != '1')
                return(0);
            y++;
        }
        x++;
    }
    return(1);
}
