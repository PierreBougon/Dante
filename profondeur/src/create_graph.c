/*
** create_graph.c for graph in /home/bougon_p/rendu/dante/profondeur
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed May 11 22:02:55 2016 bougon_p
** Last update Thu May 12 15:48:24 2016 bougon_p
*/

#include "dante.h"

int	nb_inter(char **map, t_pos *pos, t_graph *graph)
{
  int	inters;

  inters = 0;
  if (pos->y > 0 && map[pos->y - 1][pos->x] != WALL)
    inters++;
  if (pos->x > 0 && map[pos->y][pos->x - 1] != WALL)
    inters++;
  if (pos->y < graph->height - 1 && map[pos->y + 1][pos->x] != WALL)
    inters++;
  if (pos->x < graph->width - 1 && map[pos->y][pos->x + 1] != WALL)
    inters++;
  return (inters);
}

t_node		***init_save(t_graph *graph)
{
  int		i;
  int		n;
  t_node	***tab;

  if (!(tab = malloc(sizeof(t_node **) * graph->height)))
    return (NULL);
  i = -1;
  while (++i < graph->height)
    {
      if (!(tab[i] = malloc(sizeof(t_node *) * graph->width)))
	return (NULL);
      n = -1;
      while (++n < graph->width)
	tab[i][n] = NULL;
    }
  return (tab);
}

t_node		***init_graph(t_graph *graph)
{
  t_node	***tab;

  if (!(tab = init_save(graph)))
    return (NULL);
  if (!(graph->root = malloc(sizeof(t_node))))
    return (NULL);
  graph->length = 1;
  graph->root->status = START;
  graph->root->pos.x = 0;
  graph->root->pos.y = 0;
  graph->root->north = NULL;
  graph->root->west = NULL;
  graph->root->east = NULL;
  graph->root->south = NULL;
  tab[0][0] = graph->root;
  return (tab);
}

int	new_node(t_graph *graph, t_node ***save, t_pos *pos)
{
  t_node	*node;

  if (pos->x == 0 && pos->y == 0)
    return (0);
  if (!(node = create_new_node(save, pos)))
    return (1);
  save[pos->y][pos->x] = node;
  if (pos->x == graph->width - 1 && pos->y == graph->height - 1)
    node->status = END;
  return (0);
}

t_graph		*create_graph(char **map, t_graph *graph)
{
  t_pos		pos;
  t_node	***save;

  pos.y = -1;
  if (!(save = init_graph(graph)))
    return (puterr(MALLOC_ERR), NULL);
  while (map[++pos.y])
    {
      pos.x = -1;
      while (map[pos.y][++pos.x])
	{
	  if (map[pos.y][pos.x] != WALL
	      && map[pos.y][pos.x] != EMPTY)
	    return (puterr(PARS_ERR), NULL);
	  if (nb_inter(map, &pos, graph) > 0
	      && map[pos.y][pos.x] == EMPTY)
	    if (new_node(graph, save, &pos) == 1)
	      return (puterr(MALLOC_ERR), NULL);
	}
    }
  graph->tab = save;
  return (graph);
}
