/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:03:23 by thlefebv          #+#    #+#             */
/*   Updated: 2023/11/09 12:03:25 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	setting_player(t_data *data)
{
	data->img.start = "./img/2ndRight.xpm";
	data->img.player_up = "./img/2ndBack.xpm";
	data->img.player_left = "./img/2ndLeft.xpm";
	data->img.ennemy = "./img/Nids.xpm";
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.start, &(data->img.img_width),
			&(data->img.img_heigth));
	data->img.img_player_up = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player_up,
			&(data->img.img_width), &(data->img.img_heigth));
	data->img.img_player_left = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player_left,
			&(data->img.img_width), &(data->img.img_heigth));
	data->img.img_ennemy = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.ennemy, &(data->img.img_width),
			&(data->img.img_heigth));
}

void	setting_img(t_data *data)
{
	data->img.img_heigth = 64;
	data->img.img_width = 64;
	data->img.wall = "./img/Walls.xpm";
	data->img.ground = "./img/Ground.xpm";
	data->img.collec = "./img/Flamer.xpm";
	data->img.exit = "./img/Exit.xpm";
	data->img.img_ground = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.ground,
			&(data->img.img_width), &(data->img.img_heigth));
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, data->img.wall,
			&(data->img.img_width),
			&(data->img.img_heigth));
	data->img.img_collec = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.collec, &(data->img.img_width), &(data->img.img_heigth));
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, data->img.exit,
			&(data->img.img_width), &(data->img.img_heigth));
	return (setting_player(data));
}

void	set_map(t_data *data)
{
	data->content.ground = '0';
	data->content.wall = '1';
	data->content.player = 'P';
	data->content.collec = 'C';
	data->content.exit = 'E';
	data->content.ennemy = 'V';
	data->content.count_c = 0;
	data->content.count_e = 0;
	data->content.count_p = 0;
}

void	set_pos(t_data *data)
{
	data->game_pos = 0;
	data->move = 0;
}
