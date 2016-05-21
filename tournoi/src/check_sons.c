/*
** check_sons.c for sons in /home/bougon_p/rendu/dante/astar
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sun May 15 02:51:25 2016 bougon_p
** Last update Mon May 16 13:31:14 2016 bougon_p
*/

#include "dante.h"

int	check_east(t_pile *curr_pile, t_pile **open)
{
  t_node	*father;

  father = curr_pile->node;
  if (father->east != NULL &&
      !father->east->checked &&
      !is_on_open(father->east, *open))
    {
      father->east->father = father;
      if (add_to_open(open, father->east) == 1)
	return (1);
    }
  return (0);
}

int	check_south(t_pile *curr_pile, t_pile **open)
{
  t_node	*father;

  father = curr_pile->node;
  if (father->south != NULL &&
      !father->south->checked &&
      !is_on_open(father->south, *open))
    {
      father->south->father = father;
      if (add_to_open(open, father->south) == 1)
	return (1);
    }
  return (0);
}

int	check_north(t_pile *curr_pile, t_pile **open)
{
  t_node	*father;

  father = curr_pile->node;
  if (father->north != NULL &&
      !father->north->checked &&
      !is_on_open(father->north, *open))
    {
      father->north->father = father;
      if (add_to_open(open, father->north) == 1)
	return (1);;
    }
  return (0);
}

int	check_west(t_pile *curr_pile, t_pile **open)
{
  t_node	*father;

  father = curr_pile->node;
  if (father->west != NULL &&
      !father->west->checked &&
      !is_on_open(father->west, *open))
    {
      father->west->father = father;
      if (add_to_open(open, father->west) == 1)
	return (1);
    }
  return (0);
}

int	check_sons(t_pile *curr_pile, t_pile **open)
{
  if (check_east(curr_pile, open) == 1 ||
      check_south(curr_pile, open) == 1 ||
      check_north(curr_pile, open) == 1 ||
      check_west(curr_pile, open) == 1)
    return (1);
  return (0);
}
