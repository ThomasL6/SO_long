# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thlefebv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 17:05:06 by thlefebv          #+#    #+#              #
#    Updated: 2023/11/22 17:05:08 by thlefebv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = src/main.c\
      src/render_back.c\
      src/settings_img.c\
      src/map_print.c\
      src/check_map.c\
	  src/movements.c\
	  src/count_collec.c\
	  src/path_checking.c\
	  src/free_maps.c\
      get_next_line/get_next_line.c\
      get_next_line/get_next_line_utils.c\
      libft/ft_strdup.c\
      libft/ft_split.c\
      printf/ft_format_i.c\
      printf/ft_format_p.c\
      printf/ft_format_u.c\
      printf/ft_printf.c\
      printf/ft_putchar_c.c\
      printf/ft_putchar_prct.c\
      printf/ft_putnbr_majx.c\
      printf/ft_putnbr_x.c\
      printf/ft_putstr.c\

CFLAGS = -Wall -Werror -Wextra -g3
MLX_FLAGS = -L/home/thlefebv/Desktop/solo/minilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lz -lm -g3 #-fsanitize=address
OBJS = $(SRC:.c=.o) 

CC = cc

all: ${NAME}

.c.o:
	$(CC) $(CFLAGS) -I/usr/include -Imini/minilibx -c $< -o $@

${NAME}: ${OBJS}
	@echo $(MLX_FLAGS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME) -g

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}
	cd get_next_line; 

re: fclean all

.SILENT: