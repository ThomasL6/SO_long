/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:23:21 by thlefebv          #+#    #+#             */
/*   Updated: 2023/11/07 13:23:23 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void    print_img(t_data *data, void *img, int x, int y)
{
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, 
                            data->img.img_width * x, data->img.img_heigth * y);
}

void    print_background(t_data *data)
{
    print_img(data, data->img.img_ground, data->img.img_width,
                 data->img.img_heigth);
}