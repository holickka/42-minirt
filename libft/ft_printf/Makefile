COMPILE = cc

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SOURCES = ftpf_printf.c ftpf_putchar.c ftpf_putnbr_ux.c\
		 ftpf_putnbr.c ftpf_putptr.c ftpf_putstr.c ftpf_strlen.c\
		 ftpf_strchr.c ftpf_substr.c ftpf_checkinvalid.c ftpf_bzero.c

OBJECTS = $(SOURCES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
