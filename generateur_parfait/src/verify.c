/*
** verify.c for verify in /home/lokoum/prog/dante/generateur_parfait/src
** 
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Fri May 20 13:21:49 2016 Lucas Troncy
** Last update Fri May 20 14:07:55 2016 Lucas Troncy
*/

#include <stdlib.h>
#include <stdio.h>
#include "maze.h"

int	build_univers(t_all *all)
{
  all->table[all->y - 1][all->x - 1] = '*';
  if (all->table[all->y - 2][all->x - 2] == '*' &&
      all->table[all->y - 2][all->x - 1] == 'X' &&
      all->table[all->y - 1][all->x - 2] == 'X')
    all->table[all->y - 2][all->x - 1] = '*';
  return (0);
}

int	build_loop(t_all *all)
{
  int	i;
  int	j;

  i = -1;
  while (++i < all->y - 1)
    {
      j = -1;
      while (++j < all->x - 1)
	{
	  if (all->table[i][j] == 'X')
	    if (rand() % 4 == 0)
	      all->table[i][j] = '*';
	}
    }
  return (0);
}

int	verify(t_all *all)
{
  if (all->table[all->y - 1][all->x - 1] == 'X')
    build_univers(all);
  if (!all->perfect)
    build_loop(all);
  return (0);
}
