/*
** maze.h for maze in /home/lokoum/prog/dante/generateur_parfait/include
** 
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Thu May 12 13:26:43 2016 Lucas Troncy
** Last update Fri May 20 13:24:04 2016 Lucas Troncy
*/

#ifndef MAZE_H_
# define MAZE_H_

# include <stdbool.h>

typedef struct		s_all
{
  int			x;
  int			y;
  int			hunt_x;
  int			hunt_y;
  char			**table;
}			t_all;

int			verify(t_all *);
int			do_generation(t_all *);
void			rand_tab(int *, int, int);
int			check_up(t_all *all, int *, int *);
int			check_down(t_all *all, int *, int *);
int			check_left(t_all *all, int *, int *);
int			check_right(t_all *all, int *, int *);
bool			is_continuable(t_all *, int, int);
int			all_hunt(t_all *, int, int);

#endif /* MAZE_H_ */
