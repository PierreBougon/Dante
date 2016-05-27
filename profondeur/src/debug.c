/*
** debug.c for debug in /home/bougon_p/rendu/dante/profondeur
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu May 12 15:24:48 2016 bougon_p
** Last update Fri May 27 15:09:07 2016 bougon_p
*/

#include "dante.h"
#include <stdio.h>

void		aff_pile(t_graph *graph)
{
  t_pile        *curr;
  int           i;

  curr = graph->road;
  i = 0;
  while (curr->node->status != END)
    {
      printf("%d \n", i++);
      curr = curr->next;
    }
}

void	aff_node(t_node *curr)
{
  if (curr->north)
    printf(" |N");
  else
    printf("   ");
  if (curr->west)
    printf(" -W");
  else
    printf("   ");
  if (curr->east)
    printf(" -E");
  else
    printf("   ");
  if (curr->south)
    printf(" |S");
  else
    printf("   ");
  printf("  NODE");
}

void		aff_graph(t_node ***save, t_graph *graph)
{
  int		i;
  int		j;
  t_node	*curr;

  j = -1;
  while (++j < graph->height)
    {
      i = -1;
      while (++i < graph->width)
	{
	  curr = save[j][i];
	  if (curr == NULL)
	    printf("              NULL");
	  else
	    aff_node(curr);
	}
      printf("\n");
    }
}

void	aff_map(char **map)
{
  int	i;

  i = -1;
  while (map[++i])
    {
      printf("%s\n", map[i]);
    }
}
