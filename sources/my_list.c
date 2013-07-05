/*
** my_list.c for sources in /home/dabbec_j/projets/allum1/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Wed Jun 05 14:39:20 2013 jalil dabbech
** Last update Thu Jul 04 17:08:28 2013 jalil dabbech
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
