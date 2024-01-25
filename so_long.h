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
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define ERROR 1
# define VALID 0
# define RIGHT 100
# define LEFT 97
# define UP 119
# define DOWN 115
# define IMAGE_SIZE 64

typedef struct s_point
{
	int	pos_x;
	int	pos_y;
}	t_point;

typedef struct s_map
{
	char	ground;
	char	wall;
	char	player;
	char	player_up;
	char	collec;
	char	exit;
	char	ennemy;
	int		count_p;
	int		count_e;
	int		count_c;
}	t_map;

typedef struct s_image
{
	void	*img;
	void	*img_ground;
	void	*img_wall;
	void	*img_player;
	void	*img_player_up;
	void	*img_player_left;
	void	*img_collec;
	void	*img_exit;
	void	*img_ennemy;
	char	*wall;
	char	*ground;
	char	*start;
	char	*player_up;
	char	*player_left;
	char	*addr;
	char	*collec;
	char	*exit;
	char	*ennemy;
	int		bits_per_pix;
	int		line_length;
	int		endian;
	int		img_heigth;
	int		img_width;
}	t_image;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	char	**map_copy;
	int		move;
	int		width;
	int		height;
	int		game_pos;
	t_image	img;
	t_point	point;
	t_map	content;
}	t_data;

int		get_next_line(int fd, char **str);
int		check_symbols(t_data *data);
int		check_form(t_data *data);
int		check_walls(t_data *data);
int		close_solong(t_data *data);
int		end(t_data *data);
int		check_is_rectangle(t_data *data);
int		key_handler(int keycode, t_data *data);
int		count_lines(char **map);
int		flood_fill(t_data *data);
int		ft_strchr_int(char *str, char *cmp);
int		empty_map(t_data *data);
char	*read_lines_map(int fd);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	**map_core(char **str, t_data *data);
char	**map_copy(char **map);
void	setting_img(t_data *data);
void	print_img(t_data *data, void *img, int x, int y);
void	print_background(t_data *data);
void	print_back(t_data *data);
void	set_map(t_data *data);
void	count_symb(t_data *data);
void	print_error(t_data *data);
void	*ft_free_map(t_data *data);
void	check_collec(t_data *data);
void	fill_line(t_data *data, int y, int x);
void	fill_col(t_data *data, int y, int x);
void	free_map_no_launch(char **data);
void	set_pos(t_data *data);
void	heart_maps(t_data *data);
void	free_img(void *img, void *mlx_ptr);
#endif