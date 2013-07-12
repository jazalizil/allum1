/*
** my_list.c for sources in /home/dabbec_j/projets/sysunix/allum1/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Wed Jun 05 14:39:20 2013 jalil dabbech
** Last update Fri Jul 12 13:40:47 2013 jalil dabbech
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
    return ;
  new->x = abs;
  new->y = ord;
  new->del = 0;
  new->next = NULL;
  new->prev = NULL;
  if (!(*my_list))
    *my_list = new;
  else
  {
    while ((*my_list)->next)
    {
      new->prev = *my_list;
      my_list = &((*my_list)->next);
    }
    (*my_list)->next = new;
  }
}

void		add_player(t_player **my_list, char *name)
{
  t_player	*new;

  if (!(new = my_malloc(sizeof(t_player), "malloc t_player.\n")))
    return ;
  new->name = name;
  if (!(*my_list))
  {
    new->next = NULL;
    *my_list = new;
  }
  else
  {
    new->next = *my_list;
    my_list = &((*my_list)->next);
    *my_list = new;
  }
}

void		my_free_list(t_triangle *triangle, t_player *players)
{
  if (triangle)
    my_free_list(triangle->next, NULL);
  if (players)
    my_free_list(NULL, players->next);
  free(triangle);
  free(players);
}
