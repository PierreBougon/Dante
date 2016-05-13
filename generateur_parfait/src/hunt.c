/*
** hunt.c for hunt in /home/lokoum/prog/dante/generateur_parfait/src
** 
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Fri May 13 10:20:29 2016 Lucas Troncy
** Last update Fri May 13 10:42:07 2016 Lucas Troncy
*/

#include <stdio.h>
#include <stdlib.h>
#include "maze.h"

int	hunt_left(t_all *all, int a, int b)
{
  all->table[a][b - 1] = '*';
  all->table[a][b] = '*';
  all->hunt_x = b;
  all->hunt_y = a;
  return (0);
}

int	hunt_right(t_all *all, int a, int b)
{
  all->table[a][b + 1] = '*';
  all->table[a][b] = '*';
  all->hunt_x = b;
  all->hunt_y = a;
  return (0);
}

int	hunt_down(t_all *all, int a, int b)
{
  all->table[a + 1][b] = '*';
  all->table[a][b] = '*';
  all->hunt_x = b;
  all->hunt_y = a;
  return (0);
}

int	hunt_up(t_all *all, int a, int b)
{
  all->table[a - 1][b] = '*';
  all->table[a][b] = '*';
  all->hunt_x = b;
  all->hunt_y = a;
  return (0);
}

int	all_hunt(t_all *all, int a, int b)
{
  if (all->table[a][b] == 'X')
    {
      if(all->table[a][b - 1] == '*' ||
	 all->table[a][b + 1] == '*' ||
	 all->table[a - 1][b] == '*' ||
	 all->table[a + 1][b] == '*')
	{
	  return (0);
	}
      if(all->table[a][b - 2] == '*')
	hunt_left(all, a, b);
      if(all->table[a][b + 2] == '*')
	hunt_right(all, a, b);
      if(all->table[a + 2][b] == '*')
	hunt_down(all, a, b);
      if(all->table[a - 2][b] == '*')
	hunt_up(all, a, b);
    }
  return (0);
}

