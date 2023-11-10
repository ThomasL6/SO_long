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

void    print_back(t_data *data)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while(data->map[x])
    {
        while(data->map[x][y])
        {
            if(data->map[x][y] == 0)
                print_img(data, data->img.img_ground, 50, 50);
            y++;
        }
        y = 0;
        x++;
    }
}