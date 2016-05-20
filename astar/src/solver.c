/*
** solver.c for solve in /home/bougon_p/rendu/dante/profondeur
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri May 13 00:05:57 2016 bougon_p
** Last update Mon May 16 13:30:18 2016 bougon_p
*/

#include "dante.h"

int	endx;
int	endy;

t_pile		*init_pile()
{
  t_pile	*new;

  if (!(new = malloc(sizeof(t_node))))
    return (NULL);
  new->next = NULL;
  new->prev = NULL;
  return (new);
}

int	calc_cost(t_node *node)
{
  return (ABS(node->pos.x - endx) + ABS(node->pos.y - endy));
}

int		astar_search(t_graph *graph)
{
  t_pile	*open_pile;
  t_pile	*curr_pile;

  if (!(open_pile = init_pile()))
    return (1);
  endx = graph->width - 1;
  endy = graph->height - 1;
  open_pile->node = graph->root;
  open_pile->node->cost = 0;
  while (open_pile)
    {
      curr_pile = open_pile;
      curr_pile->node->checked = true;
      depop_root(&open_pile);
      if (curr_pile->node->status == END)
	{
	  free_pile(open_pile);
	  free(curr_pile);
	  return (0);
	}
      else if (check_sons(curr_pile, &open_pile) == 1)
	return (1);
      free(curr_pile);
    }
  return (puterr(UNSOLV_ERR), -1);
}
