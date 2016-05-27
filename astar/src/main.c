/*
** main.c for main in /home/bougon_p/rendu/dante/profondeur
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Apr 30 17:25:34 2016 bougon_p
** Last update Fri May 27 16:20:34 2016 bougon_p
*/

#include <stdlib.h>
#include <stdio.h>
#include "dante.h"

char	**parse_map(int fd, t_graph *graph)
{
  char	**tab;
  char	*line;
  int	i;
  int	size;

  i = 0;
  if ((tab = malloc(sizeof(char *) * 1)) == NULL)
    return (puterr(MALLOC_ERR), NULL);
  tab[0] = NULL;
  size = -1;
  while ((line = get_next_line(fd)) != NULL)
    {
      if (!(tab = my_realloc_tab(tab, 1)))
	return (puterr(MALLOC_ERR), NULL);
      tab[i++] = line;
      if (size == -1)
	size = my_strlen(tab[0]);
      if (my_strlen(tab[i - 1]) != size)
	return (puterr(PARS_ERR), NULL);
    }
  graph->width = my_strlen(tab[0]);
  graph->height = i;
  close(fd);
  return (tab);
}

void	aff_case(t_graph *graph, int j, int i)
{
  if (graph->tab[j][i] == NULL)
    {
      if (write(1, "X", 1) == -1)
	return ;
    }
  else if (graph->tab[j][i]->status == S_ROAD
	   || graph->tab[j][i]->status == START)
    {
      if (write(1, "o", 1) == -1)
	return ;
    }
  else
    {
      if (write(1, "*", 1) == -1)
	return ;
    }
}

void		write_map_solved(t_graph *graph)
{
  int		i;
  int		j;

  j = -1;
  while (++j < graph->height)
    {
      i = -1;
      while (++i < graph->width)
	{
	  aff_case(graph, j, i);
	}
      if (j != graph->height - 1 && write(1, "\n", 1) == -1)
	return ;
    }
}

void		mark_road(t_graph *graph)
{
  t_node	*node;

  node = graph->tab[graph->height - 1][graph->width - 1];
  while (node->status != START)
    {
      node->status = S_ROAD;
      node = node->father;
    }
}

int		main(int ac, char **av)
{
  char		**map;
  int		fd;
  t_graph	graph;

  if (ac == 1)
    return (puterr(USAGE), 1);
  if ((fd = open(av[1], O_RDONLY)) == -1)
    return (1);
  if (!(map = parse_map(fd, &graph)))
    return (1);
  if (!create_graph(map, &graph))
    return (1);
  free_map(map);
  if (astar_search(&graph) != 0)
    return (1);
  mark_road(&graph);
  write_map_solved(&graph);
  free_graph(&graph);
  return (0);
}
