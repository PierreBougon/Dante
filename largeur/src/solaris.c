/*
** solaris.c for solaris in /home/lokoum/prog/dante/largeur/src
** 
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Sat May 21 12:35:06 2016 Lucas Troncy
** Last update Sat May 21 13:13:23 2016 Lucas Troncy
*/

#include <stdbool.h>
#include "dante.h"

void	solaris(t_node *end, bool *good)
{
  *good = true;
  while (end->father)
    {
      end->sol = true;
      end = end->father;
    }
  end->sol = true;
}

