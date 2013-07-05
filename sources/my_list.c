/*
** my_list.c for sources in /Volumes/Jazalizil/Utilisateurs/jazalizil/allum1/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Wed Jun 05 14:39:20 2013 jalil dabbech
** Last update Ven jul 05 23:38:44 2013 jalil dabbech
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_printf.h"
#include "my_allum1.h"
#include "my.h"

void		my_put_in_list(t_triangle **my_list, int abs, int ord)
{
  t_triangle	*new;

  if (!(new = my_malloc(sizeof(t_triangle), "malloc t_triangle.\n")))
    return;
  new->x = abs;
  new->y = ord;
  new->del = 0;
  new->next = NULL;
  if (!(*my_list))
    *my_list = new;
  else
  {
    while ((*my_list)->next)
      my_list = &((*my_list)->next);
    (*my_list)->next = new;
  }
}

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

void		my_free_list(t_triangle *my_list)
{
  if (my_list)
    my_free_list(my_list->next);
  free(my_list);
}
