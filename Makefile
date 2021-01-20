# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/20 08:42:39 by user42            #+#    #+#              #
#    Updated: 2021/01/20 08:42:45 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

FLAGS		= -Wall -Wextra -Werror

NAME		= miniRT
LIBDIR		= ./libft/

RM			= rm -f

SRC =		Maths/ft_operator.c \
			Maths/ft_utils_maths.c \
			Parser/ft_affichage.c \
			Parser/ft_check_error.c \
			Parser/ft_check_error_bis.c \
			Parser/ft_fill_parser.c \
			Parser/ft_fill_parser_2.c \
			Parser/ft_fill_parser_base.c \
			Parser/ft_fill_parser_res_aligth.c \
			Parser/ft_parser.c \
			Parser/ft_print_error.c \
			Raytracer/ft_intersect.c \
			Raytracer/ft_intersect_2.c \
			Raytracer/ft_raytracer.c \
			Raytracer/ft_rotation.c \
			Raytracer/ft_translation.c \
			Raytracer/ft_utils.c \
			Raytracer/ft_utils_2.c \
			Raytracer/ft_viewplane.c \
			Raytracer/restes.c \
			Raytracer/ft_minirt.c \

INCS		= minirt.h

MLX_DIR		= minilibx-linux
MLX			= libmlx.a 
CC			= gcc

OBJS		= ${SRC:.c=.o}
OBJS_BONUS	= ${SRC_BONUS:.c=.o}

all:		${NAME}

%.o: %.c
			$(CC) -I. -o $@ -c $? $(FLAGS)

$(NAME):	$(OBJS)
			make all -C $(LIBDIR)
			${CC} $(FLAGS) -o $(NAME) $(OBJS) libft/libft.a -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext -no-pie
			@echo $(NAME) : DONE !

clean:		
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re


