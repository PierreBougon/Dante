/*
** main.c for generation parfaite in /home/lokoum/prog/dante/generateur_parfait/src
**
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
**
** Started on  Thu May 12 10:37:55 2016 Lucas Troncy
** Last update Sat May 21 20:48:16 2016 bougon_p
*/

#include <time.h>
#include <string.h>
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
  all->table[0][0] = '*';
  return (0);
}

void	disp_table(t_all *all)
{
  int	i;
  int	j;

  i = -1;
  while (++i < all->y)
    {
      j = -1;
      while (++j < all->x)
	{
	  if (write(1, &all->table[i][j], 1) == -1)
	    return ;
	}
      if (write(1, "\n", 1) == -1)
	return ;
    }
}

int	main(int argc, char **argv)
{
  t_all all;

  if (argc < 3)
    {
      if (write(1, "x y\n", 4) == -1)
	return (1);
      return (1);
    }
  all.perfect = false;
  if (argc == 4)
    if (strncmp(argv[3], "parfait", 7) == 0)
      all.perfect = true;
  srand(time(NULL) * getpid());
  all.x = atoi(argv[1]);
  all.y = atoi(argv[2]);
  all.hunt_x = 0;
  all.hunt_y = 0;
  if (init_data(&all))
    return (1);
  if (do_generation(&all))
    return (1);
  disp_table(&all);
  return (0);
}
