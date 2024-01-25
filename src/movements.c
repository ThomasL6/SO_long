/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:10:49 by thlefebv          #+#    #+#             */
/*   Updated: 2023/11/29 11:10:51 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	movement_right(t_data *data)
{
	int	y;
	int	x;

	y = data->point.pos_y;
	x = data->point.pos_x;
	if (data->map[y][x + 1] == data->content.ennemy)
	{
		ft_printf("Game Over\nTry Again");
		end(data);
	}
	if (data->map[y][x + 1] == data->content.collec)
		data->content.count_c -= 1;
	if (data->content.count_c == 0
		&& data->map[y][x + 1] == data->content.exit)
		data->content.count_e -= 1;
	if (data->map[y][x + 1] != data->content.wall
		&& data->map[y][x + 1] != data->content.exit
		&& data->content.count_e != 0)
	{
		data->map[y][x + 1] = data->content.player;
		data->map[y][x] = data->content.ground;
		data->move += 1;
	}
	data->game_pos = 3;
	check_collec(data);
}

void	movement_left(t_data *data)
{
	int	y;
	int	x;

	y = data->point.pos_y;
	x = data->point.pos_x;
	if (data->map[y][x - 1] == data->content.ennemy)
	{
		ft_printf("Game Over\nTry Again");
		end(data);
	}
	if (data->map[y][x - 1] == data->content.collec)
		data->content.count_c -= 1;
	if (data->content.count_c == 0
		&& data->map[y][x - 1] == data->content.exit)
		data->content.count_e -= 1;
	if (data->map[y][x - 1] != data->content.wall
		&& data->map[y][x - 1] != data->content.exit
		&& data->content.count_e != 0)
	{
		data->map[y][x - 1] = data->content.player;
		data->map[y][x] = data->content.ground;
		data->move += 1;
	}
	data->game_pos = 2;
	check_collec(data);
}

void	movement_up(t_data *data)
{
	int	y;
	int	x;

	y = data->point.pos_y;
	x = data->point.pos_x;
	if (data->map[y - 1][x] == data->content.ennemy)
	{
		ft_printf("Game Over\nTry Again");
		end(data);
	}
	if (data->map[y - 1][x] == data->content.collec)
		data->content.count_c -= 1;
	if (data->content.count_c == 0
		&& data->map[y - 1][x] == data->content.exit)
		data->content.count_e -= 1;
	if (data->map[y - 1][x] != data->content.wall
		&& data->map[y - 1][x] != data->content.exit
		&& data->content.count_e != 0)
	{
		data->map[y - 1][x] = data->content.player;
		data->map[y][x] = data->content.ground;
		data->move += 1;
	}
	data->game_pos = 1;
	check_collec(data);
}

void	movement_down(t_data *data)
{
	int	y;
	int	x;

	y = data->point.pos_y;
	x = data->point.pos_x;
	if (data->map[y + 1][x] == data->content.ennemy)
	{
		ft_printf("Game Over\nTry Again");
		end(data);
	}
	if (data->map[y + 1][x] == data->content.collec)
		data->content.count_c -= 1;
	if (data->content.count_c == 0
		&& data->map[y + 1][x] == data->content.exit)
		data->content.count_e -= 1;
	if (data->map[y + 1][x] != data->content.wall
		&& data->map[y + 1][x] != data->content.exit
		&& data->content.count_e != 0)
	{
		data->map[y + 1][x] = data->content.player;
		data->map[y][x] = data->content.ground;
		data->move += 1;
	}
	data->game_pos = 3;
	check_collec(data);
}

int	key_handler(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		end(data);
	}
	if (keycode == RIGHT)
		movement_right(data);
	if (keycode == DOWN)
		movement_down(data);
	if (keycode == LEFT)
		movement_left(data);
	if (keycode == UP)
		movement_up(data);
	print_back(data);
	ft_printf("Nombre de mouvement %d\n", data->move);
	return (0);
}
