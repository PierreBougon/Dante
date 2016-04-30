/*
** get_next_line.c for get_next_line in /home/lokoum/prog/CPE_2015_Lemin/src/lib
** 
** Made by Lucas Troncy
** Login   <troncy_l@epitech.net>
** 
** Started on  Sat Apr 30 19:25:21 2016 Lucas Troncy
** Last update Sat Apr 30 19:25:25 2016 Lucas Troncy
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib.h"

int	check_my_buffer(char *buffer, int option)
{
  int	i;

  i = 0;
  if (option == 0)
    {
      while (buffer[i] && buffer[i] != 0)
        i++;
      return (i);
    }
  else
    {
      if (buffer == NULL)
	return (0);
      while (buffer[i])
	{
	  if (buffer[i] == '\n' || buffer[i] == EOF)
	    return (1);
	  i++;
	}
      return (0);
    }
}

char	*my_gnl_realloc(char *old_string, int nb, int i)
{
  char	*new_string;

  if (nb == 0)
    return (old_string);
  if (old_string == NULL)
    {
      if ((old_string = malloc(sizeof(char) * (nb + 1))) == NULL)
	return (NULL);
      while (i < nb)
	old_string[i++] = 0;
      return (old_string);
    }
  if ((new_string = malloc(sizeof(char) * (check_my_buffer(old_string, 0)
					   + READ_SIZE + 1))) == NULL)
    return (NULL);
  while (old_string[i])
    {
      new_string[i] = old_string[i];
      i++;
    }
  new_string[i] = 0;
  return (new_string);
}

char	*put_to_line(char *buffer)
{
  char	*send;
  int	i;

  i = 0;
  if (buffer == NULL)
    return (NULL);
  if ((send = malloc(sizeof(char) *
		     (check_my_buffer(buffer, 0) + 1))) == NULL)
    return (NULL);
  while (buffer[i] != '\n' && buffer[i] != EOF && buffer[i])
    {
      send[i] = buffer[i];
      i++;
    }
  send[i] = '\0';
  return (send);
}

char	*add_to_buffer(char *buffer, char *tmp_string)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (buffer && buffer[i])
    i++;
  while (tmp_string[j] != '\0')
    {
      buffer[i] = tmp_string[j];
      i++;
      j++;
    }
  buffer[i] = '\0';
  return (buffer);
}

char		*get_next_line(const int fd)
{
  static char	*buffer = NULL;
  char		tmp_string[READ_SIZE + 1];
  char		*line;
  int		readed;

  readed = 1;
  if (fd == -1)
    return ((buffer = NULL));
  while (readed > 0 && (check_my_buffer(buffer, 1)) == 0)
    if ((readed = read(fd, tmp_string, READ_SIZE)) != 0)
      {
	tmp_string[readed] = '\0';
	if ((buffer = my_gnl_realloc(buffer, readed, 0)) == NULL)
	  return (NULL);
	buffer = add_to_buffer(buffer, tmp_string);
      }
  if ((line = put_to_line(buffer)) == NULL)
    return (NULL);
  buffer = &buffer[check_my_buffer(line, 0)];
  buffer = (buffer[0] == '\n' ? &buffer[1] : buffer);
  buffer = (buffer[0] == 0 || buffer[0] == '\0' ? NULL : buffer);
  return (line);
}
