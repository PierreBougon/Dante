/*
** gen.c for gen func in /home/lokoum/prog/dante/generateur_parfait/src
** 
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Thu May 12 10:46:35 2016 Lucas Troncy
** Last update Sun May 22 16:59:01 2016 Lucas Troncy
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "maze.h"

void	disp_table(t_all *);


void	init_dir(int *dir, int *nb)
{
  dir[0] = 0;
  dir[1] = 1;
  dir[2] = 2;
  dir[3] = 3;
  rand_tab(dir, rand() % 4, rand() % 4);
  *nb = -1;
}

int	get_rand(t_all *all, int *x, int *y, int nb)
{
  int	dir[4];

  init_dir(dir, &nb);
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

int		my_hunt(t_all *all)
{
  static int	a = -1;
  int		b;

  /*a = all->hunt_y;*/
  while (++a < all->y)
    {
      b = -1;
      /*b = all->hunt_x;*/
      while (++b < all->x)
	{
	  if (!all_hunt(all, a, b))
	    return (0);
	}
    }
  return (1);
}

int	my_kill(t_all *all)
{
  int	x;
  int	y;
  int	nb;

  x = all->hunt_x;
  y = all->hunt_y;
  while (is_continuable(all, x, y))
    {
      if ((nb = get_rand(all, &x, &y, 0)) == -1)
	return (1);
    }
  return (0);
}

int	do_generation(t_all *all)
{
  while (!my_hunt(all))
    if (my_kill(all))
      return (1);
  if (verify(all))
    return (1);
  return (0);
}
