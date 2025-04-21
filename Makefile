NAME = miniRT
#BONUS_NAME =

GREEN = \033[92m
RESET = \033[0m

INC_PATH = ./inc/
SRCS_PATH = ./srcs/
QUAT_PATH = ./libft/ft_quaternion/
PRINTF_PATH = ./libft/ft_printf/
LIBFT_PATH = ./libft/
LIBMLX_PATH = ./libmlx/
#BONUS_PATH =

LIBMLX = $(LIBMLX_PATH)/libmlx_intel-mac.a
LIBFT = $(LIBFT_PATH)/libft.a
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))
SRCS_FILES =	main.c \
				rt_utils_init.c		\
				rt_utils_key.c		\
				rt_utils_free.c
#main-test-drawline_zoom_panmouse.c
OBJS = $(SRCS:%.c=%.o)
#BONUS_FILES =
#BONUS_OBJS = $(BONUS_FILES:%.c=%.o)

CC = cc
#FSAN = -fsanitize=address -g3
INCS = -I$(INC_PATH) -I$(LIBFT_PATH) -I$(PRINTF_PATH) -I$(QUAT_PATH) -I$(LIBMLX_PATH)
FLAGS = -Wall -Wextra -Werror $(FSAN) $(INCS)
MLX = -L/usr/X11/lib -lX11 -lXext -framework OpenGL -framework AppKit
#MLX = -lmlx -framework OpenGL -framework AppKit

AR = ar -rc
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(LIBMLX) $(MLX) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(RESET)"

$(LIBFT):
	make -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

bonus: all

clean:
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re