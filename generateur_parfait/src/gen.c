/*
** gen.c for gen func in /home/lokoum/prog/dante/generateur_parfait/src
** 
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Thu May 12 10:46:35 2016 Lucas Troncy
** Last update Tue May 17 13:38:50 2016 Lucas Troncy
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "maze.h"

void	disp_table(t_all *);

int	get_rand(t_all *all, int *x, int *y)
{
  int	dir[4];
  int	nb;

  dir[0] = 0;
  dir[1] = 1;
  dir[2] = 2;
  dir[3] = 3;
  rand_tab(dir, rand() % 4, rand() % 4);
  nb = -1;
  while (++nb < 4)
    {
      if (dir[nb] == 0)
	{
	if (!check_up(all, x, y))
	  return (0);
	}
      else if (dir[nb] == 1)
	{
	if (!check_left(all, x, y))
	  return (1);
	}
      else if (dir[nb] == 2)
	{
	if (!check_right(all, x, y))
	  return (2);
	}
      else
	if (!check_down(all, x, y))
	  return (3);
    }
  return (-1);
}

int	my_hunt(t_all *all)
{
  int	a;
  int	b;

  a = -1;
  while (++a < all->y)
    {
      b = -1;
      while (++b < all->x)
	{
	  if (!all_hunt(all, a, b))
	    return (0);
	}
    }
  disp_table(all);
  printf("END\n");
  exit(1);
  return (1);
}

int	my_kill(t_all *all)
{
  int	x;
  int	y;
  int	nb;
  static int toto = 0;

  x = all->hunt_x;
  y = all->hunt_y;
  toto++;
  printf("laby de : %dx%d, on est a %d,%d et hunt: %d,%d\n",
	  all->x, all->y, x, y, all->hunt_x, all->hunt_y);
  printf("my_kill\n");
  if (toto > 300)
      {
	disp_table(all);
	exit(1);
      }
  while (is_continuable(all, x, y))
    {
      printf("u\n");
      printf("laby de : %dx%d, on est a %d,%d et hunt: %d,%d\n",
	    all->x, all->y, x, y, all->hunt_x, all->hunt_y);
      disp_table(all);
      if ((nb = get_rand(all, &x, &y)) == -1)
	return (1);
    }
  return (0);
}

int	do_generation(t_all *all)
{
  while (!my_hunt(all))
    if (my_kill(all))
      return (1);
  return (0);
}
