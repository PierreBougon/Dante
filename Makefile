##
## Makefile for make in /home/bougon_p/rendu/dante/profondeur
## 
## Made by bougon_p
## Login   <bougon_p@epitech.net>
## 
## Started on  Sat Apr 30 18:18:31 2016 bougon_p
## Last update Sat May 21 20:34:12 2016 bougon_p
##

# USEFUL VARIABLES

RM      =	rm -rf

GREEN	=	\033[1;32m

WHITE	=	\033[0m

ECHO	=	echo -e

all		:
			@make -s -C profondeur/
			@make -s -C astar/
			@make -C generateur/
			@make -C generateur_parfait/

clean		:
			@make clean -s -C profondeur/
			@make clean -s -C astar/
			@make clean -C generateur/
			@make clean -C generateur_parfait/

fclean		: 	clean
			@make fclean -s -C profondeur/
			@make fclean -s -C astar/
			@make fclean -C generateur/
			@make fclean -C generateur_parfait/

re		:	fclean all

.c.o		:
			@$(CC) -c $< -o $@
			@$(ECHO) "$(GREEN)[OK] > $<\t \t $(WHITE)"

.PHONY		:	all clean fclean re
