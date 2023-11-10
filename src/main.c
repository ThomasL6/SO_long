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

// int main()
// {
//     t_data data;

//     data.mlx_ptr = mlx_init();
//     data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_HEIGHT, WINDOW_WIDTH, "win42");
//     setting_img(&data);
//     print_background(&data);
//     mlx_loop(data.mlx_ptr);
// }

int main()
{
    t_data data;

    data.mlx_ptr = mlx_init();
	data.img.img = mlx_new_image(data.mlx_ptr, 1920, 1080);
    data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_HEIGHT, WINDOW_WIDTH, "win42");
    data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pix, &data.img.line_length,
								&data.img.endian);
    setting_img(&data);
    data.img.img = mlx_xpm_file_to_image(data.mlx_ptr, "./img/Ground.xpm", &data.img.img_width, &data.img.img_heigth);
    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.img, 50, 200);
    mlx_destroy_image(data.img.img, data.mlx_ptr);
    //print_back(&data);
    mlx_loop(data.mlx_ptr);
}