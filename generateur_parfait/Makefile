##
## Makefile for Makfile in /home/lokoum/prog/dante/generateur_parfait
## 
## Made by Lucas Troncy
## Login   <troncy_l@epitech.net>
## 
## Started on  Fri May 13 10:45:35 2016 Lucas Troncy
## Last update Fri May 20 13:56:45 2016 Lucas Troncy
##

DEBUG=	no

SRCS=	src/dir.c	\
	src/gen.c	\
	src/verify.c	\
	src/hunt.c	\
	src/main.c	\
	src/rand_dir.c

OBJS=	$(SRCS:.c=.o)

ifeq ($(DEBUG), yes)
CFLAGS=	-Iinclude -Wall -W -Werror -Wextra -ansi -pedantic -g -pg
else
CFLAGS=	-Iinclude -Wall -W -Werror -Wextra -ansi -pedantic
endif

NAME=	perfect

$(NAME): $(OBJS)
	 gcc $(OBJS) -o $(NAME) $(CFLAGS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
