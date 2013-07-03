/*
** putch.c for sources in /home/dabbec_j/projets/allum1/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Sat Jun 22 05:47:23 2013 jalil dabbech
** Last update Tue Jul 02 14:59:41 2013 jalil dabbech
*/

#include <unistd.h>

int	putch(int i)
{
  write(2, &i, 1);
  return (i);
}
