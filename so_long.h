/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thlefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:39:30 by thlefebv          #+#    #+#             */
/*   Updated: 2023/10/31 16:39:33 by thlefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
#define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "printf/ft_printf.h"
# include <X11/keysym.h>
# include <stdlib.h>

# define WINDOW_HEIGHT 1080
# define WINDOW_WIDTH 720

typedef struct s_point
{
    int x;
    int y;
}   t_point;

typedef struct s_image
{
    void *img;
    void *img_ground;
    char *ground;
    char *addr;
    int bits_per_pix; 
    int line_length;
    int endian;
    int img_heigth;
    int img_width;
} t_image;

typedef struct s_data
{
    void *mlx_ptr;
    void *win_ptr;
    char **map;
    t_image img;
    t_point point;
} t_data;

void    setting_img(t_data *data);
void    print_img(t_data *data, void *img, int x, int y);
void    print_background(t_data *data);
void    print_back(t_data *data);
#endif