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

WHITE   		= \x1b[37;01m
CYAN    		= \x1b[36;01m
PINK    		= \x1b[35;01m
BLUE    		= \x1b[34;01m
YELLOW  		= \x1b[33;01m
GREEN   		= \x1b[32;01m
RED     		= \x1b[31;01m
BLACK   		= \x1b[30;01m
RESET   		= \x1b[0m

SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS			= ${SRCS:.c=.o}

HEADER			= includes
FOLDER			= srcs
SAVE 			= -fsanitize=address
LIBFT 			= libft

CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror $(SAVE)
LFLAGS			= -L libft -lft

LIBMLX 			= libmlx.dylib \
				  libmlx.a

RM				= rm -f

all:			$(NAME)

$(NAME):		$(OBJS)
				@echo "$(GREEN) -----> NORMINETTE MLX <----- $(RESET)"
				@echo "$(GREEN) -----> COMPILATION MLX <----- $(RESET)"
				@make -C ./minilibx_mms
				@make -C ./minilibx_opengl
				@cp ./minilibx_mms/libmlx.dylib libmlx.dylib
				@cp ./minilibx_opengl/libmlx.a libmlx.a
				@echo "$(GREEN) -----> COMPILATION LIBFT <----- $(RESET)"
				@make -s -C $(LIBFT)
				@$(CC) $(CFLAGS) $(LFLAGS) -I $(HEADER) $(LIBMLX) $(OBJS) -o $(NAME)

%.o: %.c
				@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<
				@echo "$(GREEN) [OK] : $(RESET) $<"

norme:
				norminette $(DIR_SRCS)
				norminette $(DIR_HEADERS)

clean:
				@echo "$(RED) -----> CLEAR <----- $(RESET)"
				@$(RM) $(OBJS)

fclean:			clean
				@echo "$(RED) -----> COMPILATION FCLEAN <----- $(RESET)"
				@$(RM) $(NAME)
				@make fclean -C $(LIBFT)

re:				fclean all

.PHONY: 		all fclean clean re