/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:27:18 by thlefebv          #+#    #+#             */
/*   Updated: 2023/12/01 13:27:19 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	mark_accessible(t_data *data, int y, int x, int **visited)
{
	if (y < 0 || x < 0 || y >= data->height || x >= data->width
		|| data->map_copy[y][x] == '1' || data->map_copy[y][x] == 'A'
		|| data->map_copy[y][x] == 'E' || data->map_copy[y][x] == 'V'
		|| visited[y][x])
		return ;
	visited[y][x] = 1;
	data->map_copy[y][x] = 'A';
	mark_accessible(data, y + 1, x, visited);
	mark_accessible(data, y - 1, x, visited);
	mark_accessible(data, y, x + 1, visited);
	mark_accessible(data, y, x - 1, visited);
}

void	free_map_copy(t_data *data, int y, int **visited)
{
	while (y < data->height)
	{
		free(visited[y]);
		y++;
	}
}

int	found_player(t_data *data, int x, int y, int **visited)
{
	int	player_found;

	player_found = 0;
	while (y++ < data->height && !player_found)
	{
		x = 0;
		while (x < data->width && !player_found)
		{
			if (data->map_copy[y][x] == 'P')
			{
				player_found = 1;
				mark_accessible(data, y, x, visited);
			}
			x++;
		}
	}
	if (!player_found)
	{
		y = 0;
		free_map_copy(data, y, visited);
		free(visited);
		return (ERROR);
	}
	return (VALID);
}

int	access_player(t_data *data, int x, int y, int **visited)
{
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x++ < data->width)
		{
			if (data->map_copy[y][x] == 'P' || data->map_copy[y][x] == 'C')
			{
				if (data->map_copy[y][x] != 'A')
				{
					y = 0;
					while (y < data->height)
					{
						free(visited[y]);
						y++;
					}
					free(visited);
					return (ERROR);
				}
			}
		}
		y++;
	}
	return (VALID);
}

int	flood_fill(t_data *data)
{
	int	x;
	int	y;
	int	**visited;

	visited = malloc(data->height * sizeof(int *));
	y = 0;
	x = 0;
	while (y < data->height)
	{
		visited[y] = calloc(data->width, sizeof(int));
		y++;
	}
	y = 0;
	if (found_player(data, x, y, visited) == ERROR)
		return (ERROR);
	if (access_player(data, x, y, visited) == ERROR)
		return (ERROR);
	while (y < data->height)
	{
		free(visited[y]);
		y++;
	}
	free(visited);
	free_map_no_launch(data->map_copy);
	return (0);
}
