/*
** main.c for main generator in /home/lokoum/prog/dante/generateur/src
** 
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Sat Apr 30 18:02:43 2016 Lucas Troncy
** Last update Sat Apr 30 19:11:42 2016 Lucas Troncy
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	maze_it(int **, int, int);

int	main(int argc, char **argv)
{
  int	**maze;
  int	x;
  int	y;

  if (argc < 3)
    {
      write(2, "./maze x y\n", 11);
      return (0);
    }
  if ((x = atoi(argv[1])) < 1)
    return (1);
  if ((y = atoi(argv[2])) < 1)
    return (1);
  if ((maze = malloc(sizeof(int *) * y)) == NULL)
    return (1);
  if (maze_it(maze, x, y))
    return (1);
  return (0);
}
