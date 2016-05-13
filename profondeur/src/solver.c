/*
** solver.c for solve in /home/bougon_p/rendu/dante/profondeur
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri May 13 00:05:57 2016 bougon_p
** Last update Fri May 13 16:56:25 2016 bougon_p
*/

#include "dante.h"

t_pile		*init_pile()
{
  t_pile	*new;

  if (!(new = malloc(sizeof(t_node))))
    return (NULL);
  new->next = NULL;
  new->prev = NULL;
  return (new);
}

int	add_to_pile(t_pile **curr_pile, t_node *node)
{
  t_pile	*new;

  if (!(new = malloc(sizeof(t_node))))
    return (1);
  new->next = NULL;
  new->prev = *curr_pile;
  (*curr_pile)->next = new;
  new->node = node;
  *curr_pile = new;
  return (0);
}

int	go_deeper(t_pile **curr_pile)
{
  (*curr_pile)->node->checked = true;
  if ((*curr_pile)->node->east != NULL &&
      !(*curr_pile)->node->east->checked)
    add_to_pile(curr_pile, (*curr_pile)->node->east);
  else if ((*curr_pile)->node->south != NULL &&
	   !(*curr_pile)->node->south->checked)
    add_to_pile(curr_pile, (*curr_pile)->node->south);
  else if ((*curr_pile)->node->north != NULL &&
	   !(*curr_pile)->node->north->checked)
    add_to_pile(curr_pile, (*curr_pile)->node->north);
  else if ((*curr_pile)->node->west != NULL &&
	   !(*curr_pile)->node->west->checked)
    add_to_pile(curr_pile, (*curr_pile)->node->west);
  else
    return (2);
  return (0);
}

void		remove_from_lifo(t_pile **lifo)
{
  t_pile	*tmp;

  if ((*lifo)->prev)
    {
      tmp = *lifo;
      *lifo = (*lifo)->prev;
      (*lifo)->next = NULL;
      free(tmp);
    }
  else
    {
      free(*lifo);
      *lifo = NULL;
    }
}

int		depth_first_search(t_graph *graph)
{
  t_pile	*root_pile;
  t_pile	*curr_pile;
  bool		back;
  int		ret;

  back = false;
  if (!(root_pile = init_pile()))
    return (1);
  root_pile->node = graph->root;
  curr_pile = root_pile;
  graph->road = root_pile;
  while (curr_pile)
    {
      if (curr_pile->node->status == END)
	return (0);
      else if ((ret = go_deeper(&curr_pile)) == 2)
	back = true;
      else if (ret == 1)
	return (puterr(MALLOC_ERR), 1);
      if (back)
	{
	  remove_from_lifo(&curr_pile);
	  back = false;
	}
    }
  return (puterr(UNSOLV_ERR), -1);
}
