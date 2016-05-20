/*
** verify.c for verify in /home/lokoum/prog/dante/generateur_parfait/src
** 
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Fri May 20 13:21:49 2016 Lucas Troncy
** Last update Fri May 20 13:48:21 2016 Lucas Troncy
*/

#include <stdio.h>
#include "maze.h"

int	built_univers(t_all *all)
{
  all->table[all->y - 1][all->x - 1] = '*';
  if (all->table[all->y - 2][all->x - 2] == '*' &&
      all->table[all->y - 2][all->x - 1] == 'X' &&
      all->table[all->y - 1][all->x - 2] == 'X')
    all->table[all->y - 2][all->x - 1] = '*';
  return (0);
}

int	verify(t_all *all)
{
  if (all->table[all->y - 1][all->x - 1] == 'X')
    return (built_univers(all));
  return (0);
}
