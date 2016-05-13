##
## Makefile for Makfile in /home/lokoum/prog/dante/generateur_parfait
## 
## Made by Lucas Troncy
## Login   <troncy_l@epitech.net>
## 
## Started on  Fri May 13 10:45:35 2016 Lucas Troncy
## Last update Fri May 13 10:48:48 2016 Lucas Troncy
##

SRCS=	src/dir.c	\
	src/gen.c	\
	src/hunt.c	\
	src/main.c	\
	src/rand_dir.c

OBJS=	$(SRCS:.c=.o)

CFLAGS=	-Wall -W -Werror -Wextra -ansi -pedantic

NAME=	perfect

$(NAME): $(OBJS)
	 gcc $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
