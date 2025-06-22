# __________detect os____________
UNAME_S := $(shell uname -s)


# _________program name__________
NAME = miniRT
#BONUS_NAME =

# _____________color_____________
GREEN = \033[92m
RESET = \033[0m

# _____________paths_____________
INC_PATH = ./inc/
SRCS_PATH = ./srcs/
QUAT_PATH = ./libft/ft_quaternion/
PRINTF_PATH = ./libft/ft_printf/

# __________libft.a paths__________
LIBFT_PATH = ./libft/
LIBFT = $(LIBFT_PATH)/libft.a

# __________libmlx.a paths__________
ifeq ($(UNAME_S), Linux)
	LIBMLX_PATH	:= ./libmlx_linux
	LIBMLX		:= $(LIBMLX_PATH)/libmlx_Linux.a
	MLXFLAG		:= -L/usr/lib -lXext -lX11 -lm -lz

else ifeq ($(UNAME_S), Darwin)
	LIBMLX_PATH	:= ./libmlx
	LIBMLX		:= $(LIBMLX_PATH)/libmlx_intel-mac.a
	MLXFLAG		:= -L/usr/X11/lib -lX11 -lXext -framework OpenGL -framework AppKit

endif

# __________srcs paths__________
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))
SRCS_FILES =	\
				rt_utils_init.c				\
				rt_utils_malloc.c			\
				rt_utils_key.c				\
				rt_utils_ray.c				\
				rt_utils_rand.c				\
				rt_utils_draw1.c			\
				rt_utils_draw2.c			\
				rt_utils_color.c			\
				rt_utils_free.c				\
				rt_utils.c					\
				debug.c 					\
				main.c 						
#				main-test.c 				\
#				rt_utils_color.c			\
#				rt_utils_color2.c			\
#				rt_utils_color5.c			\

OBJS = $(SRCS:%.c=%.o)

# __________bonus (if any)__________
#BONUS_FILES =
#BONUS_OBJS = $(BONUS_FILES:%.c=%.o)

CC = cc
#FSAN = -fsanitize=address -g3
INCS = -I$(INC_PATH) -I$(LIBFT_PATH) -I$(PRINTF_PATH) -I$(QUAT_PATH) -I$(LIBMLX_PATH)
FLAGS = -Wall -Wextra -Werror $(FSAN) $(INCS)

# ___________remove files___________
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(LIBMLX) $(MLXFLAG) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(RESET)"

$(LIBFT):
	make -C $(LIBFT_PATH)

$(LIBMLX):
	make -C $(LIBMLX_PATH)

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