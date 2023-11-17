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

void setting_img(t_data *data)
{
    data->img.img_heigth = 50;
    data->img.img_width = 50;
    data->img.ground = "./img/AstartesRight.xpm";
    data->img.img_ground = mlx_xpm_file_to_image(data->mlx_ptr, data->img.ground, 
                                &(data->img.img_width), &(data->img.img_heigth));
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ground, 0, 0);
}