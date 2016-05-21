/*
** free.c for free in /home/bougon_p/rendu/dante/profondeur
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu May 12 15:23:14 2016 bougon_p
** Last update Fri May 20 21:13:56 2016 Lucas Troncy
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

void		free_file(t_file *root)
{
  t_file	*curr;
  t_file	*tmp;

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
  free_file(graph->road);
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
