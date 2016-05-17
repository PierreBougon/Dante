/*
** dir.c for dir in /home/lokoum/prog/dante/generateur_parfait/src
** 
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Thu May 12 13:54:56 2016 Lucas Troncy
** Last update Tue May 17 11:11:01 2016 Lucas Troncy
*/

#include <stdio.h>
#include <stdbool.h>
#include "maze.h"

bool	is_continuable(t_all *all, int x, int y)
{
  if (all->table[y][(x > 1) ? x - 2 : x] == 'X' ||
      all->table[y][(x < all->x - 1) ? x + 2 : x] == 'X' ||
      all->table[(y > 1) ? y - 2 : y][x] == 'X' ||
      all->table[(y < all->y - 2) ? y + 2 : y][x] == 'X')
    return (true);
  return (false);
}

int	check_up(t_all *all, int *x, int *y)
{
  if (all->table[(*y > 1) ? *y - 2 : *y][*x] == 'X')
    {
      all->table[(*y > 0) ? *y - 1 : *y][*x] = '*';
      all->table[(*y > 1) ? *y - 2 : *y][*x] = '*';
      *y = *y - 2;
      printf("*y-\n");
      return (0);
    }
  return (1);
}

int	check_down(t_all *all, int *x, int *y)
{
  if (all->table[(*y < all->y - 1) ? *y + 2 : *y][*x] == 'X')
    {
      all->table[(*y < all->y) ? *y + 1 : *y][*x] = '*';
      all->table[(*y < all->y - 1) ? *y + 2 : *y][*x] = '*';
      *y = *y + 2;
      printf("*y+\n");
      return (0);
    }
  return (1);
}

int	check_left(t_all *all, int *x, int *y)
{
  if (all->table[*y][(*x > 1) ? *x - 2 : *x] == 'X')
    {
      all->table[*y][(*x > 0) ? *x - 1 : *x] = '*';
      all->table[*y][(*x > 1) ? *x - 2 : *x] = '*';
      *x = *x - 2;
      printf("*x-\n");
      return (0);
    }
  return (1);
}

int	check_right(t_all *all, int *x, int *y)
{
  if (all->table[*y][(*x < all->x - 1) ? *x + 2 : *x] == 'X')
    {
      all->table[*y][(*x < all->x) ? *x + 1 : *x] = '*';
      all->table[*y][(*x < all->x - 1) ? *x + 2 : *x] = '*';
      *x = *x + 2;
      printf("*x+\n");
      return (0);
    }
  return (1);
}
