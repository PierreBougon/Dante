/*
** main.c for main in /home/bougon_p/rendu/dante/profondeur
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Apr 30 17:25:34 2016 bougon_p
** Last update Sat Apr 30 19:29:16 2016 bougon_p
*/

#include <stdlib.h>
#include <stdio.h>
#include "dante.h"

void	aff_map(char **map)
{
  int	i;

  i = -1;
  while (map[++i])
    {
      printf(map[i]);
    }
}

char	**parse_map(char *file)
{
  char	**tab;
  char	*line;
  int	fd;
  int	i;

  fd = open(file);
  i = 0;
  while ((line = get_next_line(fd)) != NULL)
    {
      tab = my_realloc_tab(tab, 1);
      tab[i++] = line;
    }
  return (tab);
}

int	main(int ac, char **av)
{
  char	**map;

  if (ac == 1)
    {
      dprintf(2, "Dante : Usage : ./exe maze [OPTION]\n");
      return (1);
    }
  map = parse_map(av[1]);
  aff_map(map);
  return (0);
}
