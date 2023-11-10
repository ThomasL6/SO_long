# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thlefebv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 13:25:16 by thlefebv          #+#    #+#              #
#    Updated: 2023/04/28 13:25:18 by thlefebv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a

FICHIERS_C = ft_printf.c\
	     ft_putchar_prct.c\
	     ft_putnbr_x.c\
	     ft_putnbr_majx.c\
	     ft_putstr.c\
	     ft_putchar_c.c\
	     ft_format_p.c\
	     ft_format_i.c\
	     ft_format_u.c\

AR = ar rcs

OBJS =	${FICHIERS_C:.c=.o}

CFLAGS= -Wall -Wextra -Werror #-g3 -fsanitize=address

CC = cc

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)


${NAME} : ${OBJS}
	$(AR) $(NAME) ${OBJS}

all : ${NAME}


#compile: $(OBJS)
#        $(CC) $(CFLAGS) -o a.out $(OBJS)

clean:
	rm -f ${OBJS}

fclean :clean
	rm -f ${NAME}

re: fclean all
