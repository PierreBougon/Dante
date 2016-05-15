/*
** create_node.c for node in /home/bougon_p/rendu/dante/profondeur
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed May 11 22:02:04 2016 bougon_p
** Last update Fri May 13 00:28:18 2016 bougon_p
*/

#include "dante.h"

t_node		*create_east_node(t_node *node)
{
  t_node	*new;

  if (!(new = malloc(sizeof(t_node))))
    return (NULL);
  new->status = BASIC;
  new->west = node;
  new->north = NULL;
  new->east = NULL;
  new->south = NULL;
  return (new);
}

t_node		*create_south_node(t_node *node)
{
  t_node	*new;

  if (!(new = malloc(sizeof(t_node))))
    return (NULL);
  new->status = BASIC;
  new->west = NULL;
  new->north = node;
  new->east = NULL;
  new->south = NULL;
  return (new);
}

t_node		*create_north_node(t_node *node)
{
  t_node	*new;

  if (!(new = malloc(sizeof(t_node))))
    return (NULL);
  new->status = BASIC;
  new->west = NULL;
  new->north = NULL;
  new->east = NULL;
  new->south = node;
  return (new);
}

t_node		*create_west_node(t_node *node)
{
  t_node	*new;

  if (!(new = malloc(sizeof(t_node))))
    return (NULL);
  new->status = BASIC;
  new->west = NULL;
  new->north = NULL;
  new->east = node;
  new->south = NULL;
  return (new);
}

t_node		*create_new_node(t_node ***save, t_pos *pos)
{
  t_node	*new;

  if (!(new = malloc(sizeof(t_node))))
    return (NULL);
  new->status = BASIC;
  new->pos.x = pos->x;
  new->pos.y = pos->y;
  if (pos->x > 0 && save[pos->y][pos->x - 1] != NULL)
    {
      new->west = save[pos->y][pos->x - 1];
      new->west->east = new;
    }
  else
    new->west = NULL;
  if (pos->y > 0 && save[pos->y - 1][pos->x] != NULL)
    {
      new->north = save[pos->y - 1][pos->x];
      new->north->south = new;
    }
  else
    new->north = NULL;
  new->east = NULL;
  new->south = NULL;
  new->checked = false;
  return (new);
}
