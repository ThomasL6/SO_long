# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thlefebv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 11:19:15 by thlefebv          #+#    #+#              #
#    Updated: 2023/06/15 11:19:17 by thlefebv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = so_long

SRC = src/main.c\
      src/render_back.c\
      src/settings_img.c\
	  src/map_print.c\

CFLAGS = -Wall -Werror -Wextra -g3
MLX_FLAGS = -L/home/thlefebv/Desktop/So_long/minilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lz -lm
OBJS = $(SRC:.c=.o)

CC = cc

all: ${NAME}

.c.o:
	$(CC) $(CFLAGS) -I/usr/include -Imini/minilibx -c $< -o $@

${NAME}: ${OBJS}
	@echo $(MLX_FLAGS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME) -g -fsanitize=address

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}
	cd libft ; make fclean

re: fclean all
