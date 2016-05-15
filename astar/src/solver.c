/*
** solver.c for solve in /home/bougon_p/rendu/dante/profondeur
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri May 13 00:05:57 2016 bougon_p
** Last update Mon May 16 00:15:05 2016 bougon_p
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

void		print_open(t_pile *open)
{
  int		i;
  t_pile	*tmp;

  tmp = open;
  /* printf("\n=====\n"); */
  i = 0;
  while (tmp)
    {
      /* printf("\nPILE %d | POSX = %d POSY = %d & COST = %d\n", i, */
      /* 	     tmp->node->pos.x, tmp->node->pos.y, tmp->node->cost); */
      i++;
      tmp = tmp->next;
    }
  /* printf("\n=====\n\n\n"); */
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
      /* print_open(open_pile); */
      depop_root(&open_pile);
      /* printf("CURRENT FATHER -> POSX = %d && POSY = %d && cost = %d\n", */
      /* 	     curr_pile->node->pos.x, curr_pile->node->pos.y, curr_pile->node->cost); */
      if (curr_pile->node->status == END)
	{
	  /* printf("FINIIIIIII !!\n"); */
	  return (0);
	}
      else if (check_sons(curr_pile, &open_pile) == 1)
	return (1);
    }
  return (puterr(UNSOLV_ERR), -1);
}
