/*
** get_next_line.h for gnl
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Jan  4 10:37:28 2016 marc brout
** Last update Mon May  9 13:33:00 2016 bougon_p
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
# include <stdlib.h>
# include <unistd.h>
# include "lapin.h"
# ifndef READ_SIZE
#  define READ_SIZE (4096)
# endif /* !READ_SIZE_H_ */

static char *my_realloc(char *, int);
char *get_next_line(const int fd);
char *get_last_buff(char *, int *, int *, int *);

#endif /* !GET_NEXT_LINE_H_ */
