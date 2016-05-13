/*
** dante.h for dante in /home/bougon_p/rendu/dante/profondeur
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Apr 30 18:15:26 2016 bougon_p
** Last update Fri May 13 16:56:05 2016 bougon_p
*/

#ifndef DANTE_H_
# define DANTE_H_

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include "my.h"

# define MALLOC_ERR "Could not perform malloc"
# define PARS_ERR "Invalid MAP"
# define USAGE "Usage : ./exec maze [OPTION]"
# define UNSOLV_ERR "Could not resolve the maze"

# define WALL 'X'
# define EMPTY '*'
# define ROAD 'O'

typedef	enum		e_satus
  {
    START,
    BASIC,
    END
  }			t_status;

typedef	struct		s_pos
{
  int			x;
  int			y;
}			t_pos;

typedef	struct	s_node	t_node;

typedef	struct		s_node
{
  t_node		*west;
  t_node		*east;
  t_node		*north;
  t_node		*south;
  int			status;
  t_pos			pos;
  bool			checked;
}			t_node;

typedef	struct	s_pile	t_pile;

typedef	struct		s_pile
{
  t_pile		*next;
  t_pile		*prev;
  t_node		*node;
}			t_pile;

typedef	struct		s_graph
{
  t_node		*root;
  t_node		***tab;
  int			length;
  int			width;
  int			height;
  t_pile		*road;
}			t_graph;

/*
** Prototypes
*/

t_graph		*create_graph(char **, t_graph *);
t_node		*create_east_node(t_node *);
t_node		*create_south_node(t_node *);
t_node		*create_new_node(t_node ***, t_pos *);
void		free_map(char **);
void		free_graph(t_graph *);
int		depth_first_search(t_graph *);

void		aff_graph(t_node ***, t_graph *);
void		aff_map(char **);

#endif /*!DANTE_H_ */
