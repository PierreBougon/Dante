##
## Makefile for Makefile in /home/lokoum/prog/dante/generateur
## 
## Made by Lucas Troncy
## Login   <troncy_l@epitech.net>
## 
## Started on  Sat Apr 30 17:19:45 2016 Lucas Troncy
## Last update Thu May 05 09:51:28 2016 Lucas Troncy
##

SRCS	=	src/main.c	\
		src/maze.c	\
		src/utils.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	generateur

CFLAGS	=	-Wall -ansi -pedantic -Werror

$(NAME):	$(OBJS)
		gcc $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
