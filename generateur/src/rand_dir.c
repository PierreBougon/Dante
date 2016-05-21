/*
** rand_dir.c for rand in /home/lokoum/prog/dante/generateur_parfait/src
** 
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Thu May 12 13:51:23 2016 Lucas Troncy
** Last update Thu May 12 13:53:17 2016 Lucas Troncy
*/

#include <stdlib.h>
#include "maze.h"

void	rand_tab(int *dir, int a, int b)
{
  int	tmp;

  tmp = dir[a];
  dir[a] = dir[b];
  dir[b] = tmp;
}
