NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
	   ft_flags.c \
	   characters.c \
	   functions.c \
	   functions1.c \
	   functions2.c

OBJS :=$(SRCS:.c=.o)

.PHONY : all fclean clean re

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
