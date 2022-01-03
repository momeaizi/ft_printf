NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
	   ft_flags.c \
	   characters.c \
	   functions.c \
	   functions1.c \
	   functions2.c

BONUS = ft_printf_bonus.c \
	   ft_flags_bonus.c \
	   characters_bonus.c \
	   functions_bonus.c \
	   functions1_bonus.c \
	   functions2_bonus.c

OBJS :=$(SRCS:.c=.o)

BONUS_OBJS :=$(BONUS:.c=.o)

.PHONY : all fclean clean re

all : $(NAME)

bonus : $(BONUS_OBJS)

$(NAME) : $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@
	ar -rc $(NAME) $@

clean :
	rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
