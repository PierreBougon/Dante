/*
** free.c for free in /home/bougon_p/rendu/dante/profondeur
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu May 12 15:23:14 2016 bougon_p
** Last update Mon May 16 13:10:24 2016 bougon_p
*/

#include "dante.h"

void	free_save(t_node ***save, t_graph *graph)
{
  int	i;

  i = -1;
  while (++i < graph->height)
    {
      free(save[i]);
    }
  free(save);
}

void		free_pile(t_pile *root)
{
  t_pile	*curr;
  t_pile	*tmp;

  curr = root;
  while (curr)
    {
      tmp = curr;
      curr = curr->next;
      free(tmp);
    }
}

void	free_graph(t_graph *graph)
{
  int	i;
  int	j;

  j = -1;
  while (++j < graph->height)
    {
      i = -1;
      while (++i < graph->width)
	{
	  if (graph->tab[j][i])
	    free(graph->tab[j][i]);
	}
    }
  free_save(graph->tab, graph);
}

void	free_map(char **map)
{
  int	i;

  i = -1;
  while (map[++i] != NULL)
    {
      free(map[i]);
    }
  free(map);
}
