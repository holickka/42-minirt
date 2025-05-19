COMPILE = cc

FLAGS = -Wall -Wextra -Werror -I$(PATH_PRINTF)

NAME = libft.a
PATH_PRINTF = ./ft_printf/
LIBFTPRINTF = $(PATH_PRINTF)libftprintf.a

# libft
SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_perror.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
			ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_basetoi.c \
			get_next_line.c get_next_line_bonus.c get_next_line_utils.c get_next_line_utils_bonus.c

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
		ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \

OBJECTS = $(SOURCES:%.c=%.o)
OBJECTS_BONUS = $(BONUS:%.c=%.o)

# ft_quaternion
PATH_QUAT = ./ft_quaternion/
QUAT_FILES = ft_quaternion.c ft_quaternion2.c ft_vector.c ft_vector2.c ft_vector3.c
QUAT_SOURCES = $(addprefix $(PATH_QUAT), $(QUAT_FILES))
QUAT_OBJECTS = $(QUAT_SOURCES:%.c=%.o)
FLAGS += -I$(PATH_QUAT)

all: $(NAME)

$(NAME): $(OBJECTS) $(OBJECTS_BONUS) $(QUAT_OBJECTS) $(LIBFTPRINTF)
	cp $(LIBFTPRINTF) $(NAME)
	ar -rcs $(NAME) $(OBJECTS) $(OBJECTS_BONUS) $(QUAT_OBJECTS)

%.o: %.c
	$(COMPILE) $(FLAGS) -c $< -o $@

$(LIBFTPRINTF):
	make all -C $(PATH_PRINTF)

clean:
	make clean -C $(PATH_PRINTF)
	rm -f $(OBJECTS) $(OBJECTS_BONUS) $(QUAT_OBJECTS)

fclean: clean
	make fclean -C $(PATH_PRINTF)
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
