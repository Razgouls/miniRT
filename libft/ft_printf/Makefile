# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/28 18:40:23 by eoliveir          #+#    #+#              #
#    Updated: 2020/11/28 18:40:25 by eoliveir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
LIBDIR		=	./libft/
LIBFT		=	libft.a

SRCS		=	ft_convert_hexa.c \
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

OBJS		=	$(SRCS:.c=.o)
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
AR			=	ar rc
RM			=	rm -f

%.o: %.c
				$(CC) -I. -o $@ -c $? $(FLAGS)

$(NAME)		:	$(OBJS)
				make all -C $(LIBDIR)
				cp $(LIBDIR)/$(LIBFT) $(NAME)
				$(AR) $(NAME) $(OBJS)

all			:	$(NAME)

fclean		:	clean
				$(RM) $(NAME)
				make fclean -C $(LIBDIR)

clean		:
				$(RM) $(OBJS)
				make clean -C $(LIBDIR)

re			:	fclean all

.PHONY		:	all re clean fclean