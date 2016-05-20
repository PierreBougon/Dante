/*
** open_list.c for open in /home/bougon_p/rendu/dante/astar
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun May 15 02:54:27 2016 bougon_p
** Last update Mon May 16 13:30:43 2016 bougon_p
*/

#include "dante.h"

int	add_to_open(t_pile **open_pile, t_node *node)
{
  t_pile	*new;
  t_pile	*tmp;
  int		i;

  if (!(new = malloc(sizeof(t_node))))
    return (1);
  new->node = node;
  node->cost = calc_cost(node);
  if (*open_pile == NULL)
    {
      new->next = NULL;
      new->prev = NULL;
      (*open_pile) = new;
      return (0);
    }
  tmp = *open_pile;
  i = 0;
  while (tmp->next && new->node->cost >= tmp->node->cost)
    {
      tmp = tmp->next;
      i++;
    }
  if (i == 0 && tmp->node->cost > new->node->cost)
    {
      new->prev = NULL;
      new->next = tmp;
      tmp->prev = new;
      (*open_pile) = new;
    }
  else if (tmp->next == NULL && tmp->node->cost <= new->node->cost)
    {
      new->next = NULL;
      new->prev = tmp;
      tmp->next = new;
    }
  else
    {
      tmp = tmp->prev;
      new->next = tmp->next;
      new->prev = tmp;
      tmp->next->prev = new;
      tmp->next = new;
    }
  return (0);
}

void		depop_root(t_pile **open)
{
  if ((*open)->next)
    {
      (*open)->next->prev = NULL;
      (*open) = (*open)->next;
    }
  else
    (*open) = NULL;
}

bool		is_on_open(t_node *node, t_pile *open)
{
  t_pile	*tmp;

  tmp = open;
  while (tmp)
    {
      if (tmp->node == node)
	return (true);
      tmp = tmp->next;
    }
  return (false);
}
