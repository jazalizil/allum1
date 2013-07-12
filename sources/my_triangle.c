/*
** my_triangle.c for sources in /home/dabbec_j/projets/sysunix/allum1/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Fri Jul 12 03:59:45 2013 jalil dabbech
** Last update Fri Jul 12 04:01:05 2013 jalil dabbech
*/

#include "my_allum1.h"

void		set_del(t_triangle **my_list, int abs, int ord)
{
  while ((*my_list))
  {
    if (abs == (*my_list)->x && ord == ((*my_list)->y) && !((*my_list)->del))
    {
      (*my_list)->del = 1;
      return ;
    }
    my_list = &((*my_list)->next);
  }
}

int		is_del(t_triangle **my_list, int abs, int ord)
{
  while ((*my_list))
  {
    if (abs == (*my_list)->x && ord == (*my_list)->y)
    {
      if ((*my_list)->del)
	return (1);
      else
	return (0);
    }
    my_list = &((*my_list)->next);
  }
  return (0);
}

int		is_in_list(t_triangle **my_list, int abs, int ord)
{
  while ((*my_list))
  {
    if (abs == (*my_list)->x && ord == (*my_list)->y)
      return (1);
    my_list = &((*my_list)->next);
  }
  return (0);
}
