##
## Makefile for astar in /home/bougon_p/rendu/dante/astar
## 
## Made by bougon_p
## Login   <bougon_p@epitech.net>
## 
## Started on  Sat May 14 17:39:55 2016 bougon_p
## Last update Sun May 15 02:55:44 2016 bougon_p
##

# USEFUL VARIABLES

RM      =	rm -rf

GREEN	=	\033[1;32m

WHITE	=	\033[0m

ECHO	=	echo -e

# SOURCES VARIABLES

MAIN		=	src/

SRC		=	$(MAIN)main.c \
			$(MAIN)create_graph.c \
			$(MAIN)create_node.c \
			$(MAIN)free.c \
			$(MAIN)debug.c \
			$(MAIN)solver.c \
			$(MAIN)check_sons.c \
			$(MAIN)open_list.c \

OBJS    	=	$(SRC:.c=.o)


# PROJECT VARIABLES

NAME	=	solver

IFLAG	=	-Iinclude/

CFLAGS  =	-W -Wall -Wextra -g

CC      =	gcc $(CFLAGS) $(IFLAG)


# LIBRARY VARIABLES

LIBPATH =       lib/

LIB	=	lib/libmy.a

SRCLIB	=	$(LIBPATH)my/get_next_line.c \
		$(LIBPATH)my/my_getnbr.c \
		$(LIBPATH)my/my_power_rec.c \
		$(LIBPATH)my/my_putchar.c \
		$(LIBPATH)my/my_put_nbr.c \
		$(LIBPATH)my/my_putstr.c \
		$(LIBPATH)my/my_revstr.c \
		$(LIBPATH)my/my_strcmp.c \
		$(LIBPATH)my/my_strcat.c \
		$(LIBPATH)my/my_strdup.c \
		$(LIBPATH)my/my_strlen.c \
		$(LIBPATH)my/my_strcpy.c \
		$(LIBPATH)my/my_bzero.c \
		$(LIBPATH)my/my_realloc.c \
		$(LIBPATH)my/my_alpha_num.c \
		$(LIBPATH)my/my_puterror.c \

LDFLAGS =       -lmy -L$(LIBPATH)

OBJSLIB	=	$(SRCLIB:.c=.o)


# PROJECT RULES

$(NAME)		: 	$(LIB) $(OBJS)
			@$(ECHO) "$(GREEN)\n\n> Linking \"$(NAME)\" with : \n\
$(CC)\n\n>>>>>>>>>>\t DONE\n$(WHITE)"
			@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) $(LIB)

$(LIB)		:	$(OBJSLIB)
			@ar rc $(LIB) $(OBJSLIB)
			@ranlib $(LIB)
			@$(ECHO) "$(GREEN)\n> Compiling Library\t\
 >>>>>>>>>> \t DONE\n$(WHITE)"

compile		:	$(OBJS)
			@$(ECHO) "$(GREEN)\n\n> Linking \"$(NAME)\" with : \n\
$(CC)\n\n>>>>>>>>>>\t DONE\n$(WHITE)"
			@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) $(LIB)

all		:	$(LIB)
			@make -j 4 -s compile

clean		:
			@$(RM) $(OBJS)
			@$(RM) $(OBJSLIB)
			@$(ECHO) "$(GREEN)\n> Cleaning repository\t\
 >>>>>>>>>> \t DONE\n$(WHITE)"

fclean		: 	clean
			@$(RM) $(NAME)
			@$(RM) $(LIB)
			@$(ECHO) "$(GREEN)\n> Cleaning exec\t\t\
 >>>>>>>>>> \t DONE\n$(WHITE)"

re		:	fclean all

.c.o		:
			@$(CC) -c $< -o $@
			@$(ECHO) "$(GREEN)[OK] > $<\t \t $(WHITE)"

.PHONY		:	comp all clean fclean re
