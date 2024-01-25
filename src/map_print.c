/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:05:03 by thlefebv          #+#    #+#             */
/*   Updated: 2023/11/09 18:05:04 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	print_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img,
		data->img.img_width * x, data->img.img_heigth * y);
}

void	print_player(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == data->content.player)
			{
				data->point.pos_x = x;
				data->point.pos_y = y;
				print_img(data, data->img.img_player, x, y);
				if (data->game_pos == 1)
					print_img(data, data->img.img_player_up, x, y);
				else if (data->game_pos == 2)
					print_img(data, data->img.img_player_left, x, y);
				else if (data->game_pos == 3)
					print_img(data, data->img.img_player, x, y);
			}
			x++;
		}
		y++;
	}
}

void	print_back(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->map[++y] != NULL)
	{
		x = -1;
		while (data->map[y][++x] != '\0')
		{
			print_player(data);
			if (data->map[y][x] == data->content.wall)
				print_img(data, data->img.img_wall, x, y);
			if (data->map[y][x] == data->content.ground)
				print_img(data, data->img.img_ground, x, y);
			if (data->map[y][x] == data->content.collec)
				print_img(data, data->img.img_collec, x, y);
			if (data->map[y][x] == data->content.exit)
				print_img(data, data->img.img_exit, x, y);
			if (data->map[y][x] == data->content.ennemy)
				print_img(data, data->img.img_ennemy, x, y);
		}
	}
}

char	**map_copy(char **map)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * (count_lines(map) + 1));
	if (!copy)
		return (NULL);
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (i >= 0)
			{
				free(copy[i]);
				i--;
			}
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	heart_maps(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->width, data->height, "so_long");
	if (data->win_ptr == NULL)
	{
		free(data->mlx_ptr);
		return ;
	}
	print_back(data);
	mlx_key_hook(data->win_ptr, key_handler, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, close_solong, data);
	mlx_loop(data->mlx_ptr);
	close_solong(data);
}
