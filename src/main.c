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
//     t_data *data;

//     data = malloc((sizeof(data))* 10000);
//     data->mlx_ptr = mlx_init();
//     data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_HEIGHT, WINDOW_WIDTH, "win42");
//      printf("1");
//     mlx_key_hook(data->win_ptr, key_handler, data);
//     // printf("%p",key_handler);
//     mlx_loop(data->mlx_ptr);
//     return(0);
// }

int key_handler(int keycode, t_data *data) 
{
    if (keycode == 65307) 
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        exit(0);
    }
    else if (keycode == 100) 
    { 
        data->move += 1;
        printf("Nombre de mouvement %d\n", data->move);
    }
    else if (keycode == 115) 
    { 
        data->move += 1;
        printf("Nombre de mouvement %d\n", data->move);
    }
    else if (keycode == 97) 
    { 
        data->move += 1;
        printf("Nombre de mouvement %d\n", data->move);
    }
    else if (keycode == 119) 
    { 
        data->move += 1;
        printf("Nombre de mouvement %d\n", data->move);
    }
    return (0);
}

int	mouse_handler()
{  
    // mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	// mlx_destroy_display(data->mlx_ptr);
	exit(0);
}

int main()
{
    t_data *data;

    data = malloc((sizeof(t_data)));
    data->mlx_ptr = mlx_init();
	data->img.img = mlx_new_image(data->mlx_ptr, 1920, 1080);
    data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_HEIGHT, WINDOW_WIDTH, "win42");
    data->move = 0;
    setting_img(data);
    mlx_key_hook(data->win_ptr, key_handler, data);
    mlx_hook(data->win_ptr, 17, 1L << 17, mouse_handler, &data);
    mlx_loop(data->mlx_ptr);
    // mlx_destroy_image(data->img.img, data->mlx_ptr);
}