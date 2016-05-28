/*
** get_next_line.c for gnl in /home/bougon_p/rendu/dante
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat May 28 20:03:45 2016 bougon_p
** Last update Sat May 28 20:05:49 2016 bougon_p
*/

#include <stdio.h>
#include "get_next_line.h"

static char	*my_grealloc(char *str, int size)
{
  char		*tmp;
  int		i;

  if ((tmp = malloc(size + 1)) == NULL)
    return (NULL);
  i = -1;
  while (str && str[++i] && i < size)
    tmp[i] = str[i];
  while (i <= size)
    tmp[i++] = 0;
  if (str != NULL)
    free(str);
  return (tmp);
}

char	*get_last_buff(char *buff, int *ret, int *i, int *j)
{
  int	size;
  char	*str;

  if ((str = malloc(1)) == NULL)
    return (NULL);
  if (*ret == 0)
    {
      free(str);
      return (NULL);
    }
  str[0] = 0;
  size = 0;
  if (*i < READ_SIZE && *i != -1)
    while (buff[++*i] && buff[*i] != '\n' && (size += 1))
      {
	if ((str = my_grealloc(str, size)) == NULL)
	  return (NULL);
	str[++*j] = buff[*i];
      }
  return (str);
}

char		*get_next_line(const int fd)
{
  static char	buf[READ_SIZE + 1];
  static int	i = -1;
  static int	r = -1;
  char		*str;
  int		size;
  int		j;

  str = NULL;
  if ((((fd < 0) || (j = -1) > 0 || READ_SIZE < 1 ||
	!(str = get_last_buff(buf, &r, &i, &j)) ||
	buf[i] == 10)) && buf[i])
    return (str);
  size = j + 1;
  while (buf[i] != 10 && (r = read(fd, buf, READ_SIZE)) > 0 &&
	 (size += r) && !(buf[r] = 0))
    {
      if ((str = my_grealloc(str, size)) == NULL)
	return (NULL);
      i = -1;
      while (buf[++i] && buf[i] != '\n' && (str[++j] = buf[i]));
    }
  if (size)
    return (str);
  free(str);
  return (((i = -1) && (r = -1)) ? NULL : NULL);
}
