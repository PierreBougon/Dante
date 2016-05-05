/*
** maze.c for maze funcs in /home/lokoum/prog/dante/generateur/src
** 
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Sat Apr 30 18:15:59 2016 Lucas Troncy
** Last update Thu May 05 09:49:55 2016 Lucas Troncy
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

int	modifier(int *, int *, int *, int *);

int	solution(int **maze, int x, int y)
{
  int	a;
  int	b;

  a = 0;
  b = 0;
  maze[a][b] = 0;
  while (maze[y - 1][x -1])
    {
      modifier(&a, &b, &x, &y);
      maze[a][b] = 0;
    }
  return (0);
}

int	fill_it(int **maze, int x, int y)
{
  int	a;
  int	b;

  a = -1;
  while (++a < y)
    {
      b = -1;
      if ((maze[a] = malloc(sizeof(int) * x)) == NULL)
	return (1);
      while (++b < x)
	{
	  maze[a][b] = 1;
	}
    }
  return (0);
}

void	disp(int **maze, int x, int y)
{
  int	a;
  int	b;

  a = -1;
  while (++a < y)
    {
      b = -1;
      while (++b < x)
	{
	  if (maze[a][b])
	    write(1, "X", 1);
	  else
	    write(1, "*", 1);
	}
      write(1, "\n", 1);
    }
}
int	randomize(int **maze, int x, int y)
{
  int	a;
  int	b;
  int	nb;

  a = -1;
  while (++a < y)
    {
       b = -1;
       while (++b < x)
	 {
	    nb = rand() % 2;
	    if (!nb)
	      maze[a][b] = 0;
	 }
    }
  return (0);
}

int	maze_it(int **maze, int x, int y)
{
  srand(time(NULL));
  if (fill_it(maze, x, y))
    return (1);
  if (solution(maze, x, y))
    return (1);
  if (randomize(maze, x, y))
    return (1);
  disp(maze, x, y);
  return (0);
}
