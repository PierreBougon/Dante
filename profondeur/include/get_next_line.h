/*
** get_next_line.h for gnl in /home/bougon_p/rendu/dante/profondeur
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri May 20 19:46:02 2016 bougon_p
** Last update Sat May 28 20:15:49 2016 bougon_p
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
# include <stdlib.h>
# include <unistd.h>
# ifndef READ_SIZE
#  define READ_SIZE (4096)
# endif /* !READ_SIZE_H_ */

static char *my_grealloc(char *, int);
char *get_next_line(const int fd);
char *get_last_buff(char *, int *, int *, int *);

#endif /* !GET_NEXT_LINE_H_ */
