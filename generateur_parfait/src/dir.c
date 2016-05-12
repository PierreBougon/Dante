/*
** dir.c for dir in /home/lokoum/prog/dante/generateur_parfait/src
** 
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Thu May 12 13:54:56 2016 Lucas Troncy
** Last update Thu May 12 14:35:02 2016 Lucas Troncy
*/

#include <stdbool.h>
#include "maze.h"

bool	is_continuable(t_all *all, int x, int y)
{
  if (all->table[y][x - 2] == 'X' || all->table[y][x + 2] == 'X' ||
      all->table[y - 2][x] == 'X' || all->table[y + 2][x] == 'X')
    return (true);
  return (false);
}

int	check_up(t_all *all, int *x, int *y)
{
  if (all->table[*y - 2][*x] == 'X')
    {
      all->table[*y - 1][*x] = '*';
      all->table[*y - 2][*x] = '*';
      *y = *y - 2;
      return (0);
    }
  return (1);
}

int	check_down(t_all *all, int *x, int *y)
{
  if (all->table[*y + 2][*x] == 'X')
    {
      all->table[*y + 1][*x] = '*';
      all->table[*y + 2][*x] = '*';
      *y = *y + 2;
      return (0);
    }
  return (1);
}

int	check_left(t_all *all, int *x, int *y)
{
  if (all->table[*y][*x - 2] == 'X')
    {
      all->table[*y][*x - 1] = '*';
      all->table[*y][*x - 2] = '*';
      *x = *x - 2;
      return (0);
    }
  return (1);
}

int	check_right(t_all *all, int *x, int *y)
{
  if (all->table[*y][*x + 2] == 'X')
    {
      all->table[*y][*x + 1] = '*';
      all->table[*y][*x + 2] = '*';
      *x = *x + 2;
      return (0);
    }
  return (1);
}
