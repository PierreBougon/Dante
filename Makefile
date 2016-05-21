##
## Makefile for make in /home/bougon_p/rendu/dante/profondeur
## 
## Made by bougon_p
## Login   <bougon_p@epitech.net>
## 
## Started on  Sat Apr 30 18:18:31 2016 bougon_p
## Last update Sat May 21 20:59:07 2016 bougon_p
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

clean		:
			@make clean -s -C profondeur/
			@make clean -s -C astar/
			@make clean -C generateur/

fclean		: 	clean
			@make fclean -s -C profondeur/
			@make fclean -s -C astar/
			@make fclean -C generateur/

re		:	fclean all

.PHONY		:	all clean fclean re
