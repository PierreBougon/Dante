/*
** main.c for main in /home/bougon_p/rendu/dante/profondeur
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Apr 30 17:25:34 2016 bougon_p
** Last update Thu May 12 15:51:50 2016 bougon_p
*/

#include <stdlib.h>
#include <stdio.h>
#include "dante.h"

char	**parse_map(int fd, t_graph *graph)
{
  char	**tab;
  char	*line;
  int	i;

  i = 0;
  if ((tab = malloc(sizeof(char *) * 1)) == NULL)
    return (NULL);
  tab[0] = NULL;
  while ((line = get_next_line(fd)) != NULL)
    {
      tab = my_realloc_tab(tab, 1);
      tab[i++] = line;
    }
  graph->width = my_strlen(tab[0]);
  graph->height = i;
  close(fd);
  return (tab);
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
    return (puterr(MALLOC_ERR), 1);
  if (!create_graph(map, &graph))
    return (1);

  /*
  ** DEBUG
  */
  aff_map(map);
  aff_graph(graph.tab, &graph);

  free_map(map);
  //SOLVER
  free_graph(&graph);
  return (0);
}
