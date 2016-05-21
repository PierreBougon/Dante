/*
** my_puterror.c for puterr in /home/bougon_p/rendu/dante/profondeur
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu May 12 15:41:06 2016 bougon_p
** Last update Mon May 16 00:22:08 2016 bougon_p
*/

#include "my.h"

void	puterr(char *err)
{
  if (write(2, "Dante : ", 8) == -1)
    return ;
  if (write(2, err, my_strlen(err)) == -1)
    return ;
  if (write(2, "\n", 1) == -1)
    return ;
}
