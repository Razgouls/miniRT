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

CC			= clang

FLAGS		= 	-Wall -Wextra -Werror

NAME		= 	libft.a
LIBDIR		= 	./ft_printf/
PRINTF		=	libftprintf.a

RM			= rm -f

SRC		 	=	ft_atoi.c \
				ft_bzero.c \
				ft_isalpha.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_strchr.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_strlen.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_split_multi.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_get_next_line.c \
				ft_strdel.c \
				ft_strndup.c \
				ft_strcmp.c \
				ft_atof.c \
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_strcat.c \
				ft_reverse_tab.c \
				ft_len_new_base.c \
				ft_atoi_base.c \
				ft_convert_base.c \
				ft_clamp.c \
				ft_calc_determinant.c \
				ft_abs.c \
				ft_rad_to_deg.c \

INCS		= libft.h

OBJS		= ${SRC:.c=.o}
OBJS_BONUS	= ${SRC_BONUS:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			make all -C $(LIBDIR)
			cp $(LIBDIR)/$(PRINTF) $(NAME)
			ar rc ${NAME} ${OBJS}

%.o: %.c
			$(CC) -I. -o $@ -c $? $(FLAGS)

clean:		
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re


