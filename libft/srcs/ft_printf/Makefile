# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/17 09:04:13 by eoliveir          #+#    #+#              #
#    Updated: 2021/01/19 11:49:16 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

SRCS			=	ft_convert_hexa.c \
					ft_parser.c \
					ft_printf.c \
					ft_printf_affichage.c \
					ft_printf_affichage_bis.c \
					ft_printf_d.c \
					ft_printf_u.c \
					ft_printf_p.c \
					ft_printf_hexa.c \
					ft_printf_utils.c \
					ft_printf_c.c

WHITE   		= \x1b[37;01m
CYAN    		= \x1b[36;01m
PINK    		= \x1b[35;01m
BLUE    		= \x1b[34;01m
YELLOW  		= \x1b[33;01m
GREEN   		= \x1b[32;01m
RED     		= \x1b[31;01m
BLACK   		= \x1b[30;01m
RESET   		= \x1b[0m

OBJS			= ${SRCS:.c=.o}

HEADER			= ../../includes

CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror
RM				= rm -f

all:			${NAME}

$(NAME):		${OBJS}
				@ar -rcs ${NAME} ${OBJS}

%.o: %.c
				@${CC} ${CFLAGS} -I ${HEADER} -o $@ -c $<
				@echo "$(GREEN) [OK] : $(RESET) $<"

clean:
				@${RM} ${OBJS}

fclean:			clean
				@${RM} ${NAME}

re:				fclean all

.PHONY: 		all fclean clean re