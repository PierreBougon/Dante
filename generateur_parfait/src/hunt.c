/*
** hunt.c for hunt in /home/lokoum/prog/dante/generateur_parfait/src
** 
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Fri May 13 10:20:29 2016 Lucas Troncy
** Last update Tue May 17 13:37:26 2016 Lucas Troncy
*/

#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

int	hunt_left(t_all *all, int a, int b)
{
  printf("left\n");
  all->table[a][(b > 0) ? b - 1 : b] = '*';
  all->table[a][b] = '*';
  all->hunt_x = b;
  all->hunt_y = a;
  return (0);
}

int	hunt_right(t_all *all, int a, int b)
{
  printf("right\n");
  all->table[a][(b < all->x) ? b + 1 : b] = '*';
  all->table[a][b] = '*';
  all->hunt_x = b;
  all->hunt_y = a;
  return (0);
}

int	hunt_down(t_all *all, int a, int b)
{
  printf("down\n");
  all->table[(a < all->y) ? a + 1 : a][b] = '*';
  all->table[a][b] = '*';
  all->hunt_x = b;
  all->hunt_y = a;
  return (0);
}

int	hunt_up(t_all *all, int a, int b)
{
  printf("up\n");
  all->table[(a > 0) ? a - 1 : a][b] = '*';
  all->table[a][b] = '*';
  all->hunt_x = b;
  all->hunt_y = a;
  return (0);
}

int	all_hunt(t_all *all, int a, int b)
{
  if (all->table[a][b] == 'X')
    {
      printf("a\n");
      if(all->table[a][(b > 0) ? b - 1 : b] == '*' ||
	 all->table[a][(b > 0) ? b + 1 : b] == '*' ||
	 all->table[(a > 0) ? a - 1 : a][b] == '*' ||
	 all->table[(a < all->y - 1) ? a + 1 : a][b] == '*')
	{
	  printf("b\n");
	  return (1);
	}
      if(all->table[a][(b > 1) ? b - 2 : b] == '*')
	return (hunt_left(all, a, b));
      if(all->table[a][(b < all->x - 2) ? b + 2 : b] == '*')
	return (hunt_right(all, a, b));
      if(all->table[(a < all->y - 2) ? a + 2 : a][b] == '*')
	return (hunt_down(all, a, b));
      if(all->table[(a > 1) ? a - 2 : a][b] == '*')
	return (hunt_up(all, a, b));
    }
  return (1);
}

