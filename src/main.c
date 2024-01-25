/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:19:52 by thlefebv          #+#    #+#             */
/*   Updated: 2023/11/09 11:19:53 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	end(t_data *data)
{
	int	i;

	i = 0;
	if (data->map != NULL)
	{
		while (data->map[i] != NULL)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
		mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
		mlx_destroy_image(data->mlx_ptr, data->img.img_ground);
		mlx_destroy_image(data->mlx_ptr, data->img.img_collec);
		mlx_destroy_image(data->mlx_ptr, data->img.img_ennemy);
		mlx_destroy_image(data->mlx_ptr, data->img.img_player);
		mlx_destroy_image(data->mlx_ptr, data->img.img_player_left);
		mlx_destroy_image(data->mlx_ptr, data->img.img_player_up);
		mlx_destroy_image(data->mlx_ptr, data->img.img_exit);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

void	calculate_window_size(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
			x++;
		y++;
	}
	data->width = x * IMAGE_SIZE;
	data->height = y * IMAGE_SIZE;
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (argc != 2)
		ft_printf("Error\n2 arguments needed");
	else
	{
		set_pos(&data);
		set_map(&data);
		data.map = map_core(argv, &data);
		if (!data.map)
			return (0);
		data.mlx_ptr = mlx_init();
		setting_img(&data);
		calculate_window_size(&data);
		if (data.map != NULL)
			heart_maps(&data);
		else
		{
			close_solong(&data);
			free(data.map);
		}
	}
	return (0);
}
