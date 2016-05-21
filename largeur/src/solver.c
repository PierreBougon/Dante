/*
** solver.c for solve in /home/bougon_p/rendu/dante/profondeur
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri May 13 00:05:57 2016 bougon_p
** Last update Sat May 21 13:24:48 2016 Lucas Troncy
*/

#include <stdio.h>
#include <stdbool.h>
#include "dante.h"

t_file		*init_file()
{
  t_file	*new;

  if (!(new = malloc(sizeof(t_file))))
    return (NULL);
  new->next = NULL;
  new->prev = NULL;
  return (new);
}

int	add_to_file(t_file **root, t_node *node, bool *good)
{
  t_file	*new;
  t_file	*tmp;

  if (node->checked)
    return (0);
  if (!(new = malloc(sizeof(t_file))))
    return (1);
  tmp = (*root);
  while (tmp->next)
    tmp = tmp->next;
  new->next = NULL;
  new->prev = tmp;
  tmp->next = new;
  new->node = node;
  new->node->father = (*root)->node;
  if (node->status == END)
    return (solaris(node, good), 2);
  return (0);
}

void		remove_from_file(t_file **root)
{
  t_file	*tmp;

  if ((*root)->next)
    {
      tmp = *root;
      *root = (*root)->next;
      (*root)->prev = NULL;
      free(tmp);
    }
  else
    {
      free(*root);
      *root = NULL;
    }
}

int		go_deeper(t_file **root, bool *good)
{
  t_file	*tmp;

  tmp = (*root);
  while (tmp)
    {
      tmp->node->checked = true;
      if (tmp->node->east != NULL && !tmp->node->east->checked)
	add_to_file(root, tmp->node->east, good);
      if (tmp->node->west != NULL && !tmp->node->west->checked)
	add_to_file(root, tmp->node->west, good);
      if (tmp->node->north != NULL && !tmp->node->north->checked)
	add_to_file(root, tmp->node->north, good);
      if (tmp->node->south != NULL && !tmp->node->south->checked)
	add_to_file(root, tmp->node->south, good);
      remove_from_file(root);
      tmp = (*root);
    }
  return (0);
}

int		breadth_first_search(t_graph *graph)
{
  t_file	*root_file;
  bool		good;

  if (!(root_file = init_file()))
    return (1);
  root_file->node = graph->root;
  root_file->node->father = NULL;
  graph->road = root_file;
  good = false;
  go_deeper(&root_file, &good);
  if (!good)
    return (puterr(UNSOLV_ERR), -1);
  return (0);
}
