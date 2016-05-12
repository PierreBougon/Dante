/*
** main.c for generation parfaite in /home/lokoum/prog/dante/generateur_parfait/src
** 
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Thu May 12 10:37:55 2016 Lucas Troncy
** Last update Thu May 12 13:33:51 2016 Lucas Troncy
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "maze.h"

int	init_data(t_all *all)
{
  int	i;
  int	j;

  i = -1;
  if ((all->table = malloc(sizeof(char *) * (all->y + 1))) == NULL)
    return (1);
  all->table[all->y] = NULL;
  while (++i < all->y)
    {
      j = -1;
      if ((all->table[i] = malloc(sizeof(char) * (all->x + 1))) == NULL)
	return (1);
      all->table[i][all->x] = 0;
      while (++j < all->x)
	all->table[i][j] = 'X';
    }
  return (0);
}

int	main(int argc, char **argv)
{
  t_all all;

  if (argc < 3)
    {
      write(1, "x y\n", 4);
      return (1);
    }
  all.x = atoi(argv[1]);
  all.y = atoi(argv[2]);
  all.hunt_x = 0;
  all.hunt_y = 0;
  if (init_data(&all))
    return (1);
  if (do_generation(&all))
    return (1);
  return (0);
}
