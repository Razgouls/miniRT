NAME			= miniRT

SRCS_LIST 		= Maths/ft_operator.c \
				  Maths/ft_utils_maths.c \
				  Parser/ft_check_error.c \
				  Parser/ft_check_error_bis.c \
				  Parser/ft_fill_parser.c \
				  Parser/ft_fill_parser_2.c \
				  Parser/ft_fill_parser_base.c \
				  Parser/ft_fill_parser_res_aligth.c \
				  Parser/ft_parser.c \
				  Parser/ft_utils_parser.c \
				  Parser/ft_print_error.c \
				  Raytracer/ft_intersect.c \
				  Raytracer/ft_intersect_2.c \
				  Raytracer/ft_raytracer.c \
				  Raytracer/ft_rotation.c \
				  Raytracer/ft_translation.c \
				  Raytracer/ft_utils.c \
				  Raytracer/ft_utils_2.c \
				  Raytracer/ft_viewplane.c \
				  Raytracer/ft_minirt.c \
				  Raytracer/bmp_image.c \
				  Raytracer/ft_events_mlx.c \

GREEN   		= \e[32m
RESET   		= \e[39m

SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS			= ${SRCS:.c=.o}

HEADER			= includes
FOLDER			= srcs
LIBFT 			= libft

CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror
LFLAGS			= -L libft -lft
MLX_DIR			= minilibx-linux

RM				= rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				@echo "$(GREEN) -----> COMPILATION MLX <----- $(RESET)"
				@make -C ./minilibx-linux
				@cp ./minilibx-linux/libmlx.a libmlx.a
				@echo "$(GREEN) -----> COMPILATION LIBFT <----- $(RESET)"
				@make -C $(LIBFT)
				${CC} $(CFLAGS) $(LFLAGS) -o $(NAME) $(OBJS) libft/libft.a -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext -no-pie

%.o: %.c
				@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<
				@echo "$(GREEN) [OK] : $(RESET) $<"

clean:
				@echo "$(GREEN) -----> CLEAR OK <----- $(RESET)"
				@$(RM) $(OBJS)

fclean:			clean
				@echo "$(GREEN) -----> COMPILATION FCLEAN OK <----- $(RESET)"
				@$(RM) $(NAME)
				@make fclean -C $(LIBFT)

re:				fclean all

.PHONY: 		all fclean clean re