/*
** utils.c for utils in /home/lokoum/prog/dante/generateur/src
** 
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Thu May 05 09:10:38 2016 Lucas Troncy
** Last update Thu May 05 09:48:58 2016 Lucas Troncy
*/

#include <stdlib.h>

int	my_little_pony(int a, int b)
{
  return (a < b ? a : b);
}

int	my_big(int a, int b)
{
  return (a < b ? b : a);
}

int	rand_coef(int x, int y)
{
  int	res;

  res = rand() % (x + y) + 1;
  if (res <= my_little_pony(x, y))
    return (1);
  return (0);
}

void	modifier(int *a, int *b, int *x, int *y)
{
  int	nb;

  nb = rand_coef(*x, *y);
  if (my_little_pony(*x, *y) == *y)
    {
      if (nb && *a < *y - 1)
	++*a;
      else if (!nb &&  *b < *x - 1)
	++*b;
    }
  else
    {
      if (!nb && *a < *y - 1)
	++*a;
      else if (nb &&  *b < *x - 1)
	++*b;
    }
}
