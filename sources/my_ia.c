/*
** my_ia.c for sources in /home/dabbec_j/projets/allum1/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Tue Jul 09 17:28:25 2013 jalil dabbech
** Last update Tue Jul 09 19:04:23 2013 jalil dabbech
*/

#include <ncurses.h>
#include <unistd.h>
#include "my_allum1.h"

void		clean(t_triangle **my_triangle)
{
  int		x;
  int		y;

  getyx(stdscr, y, x);
  if (is_del(my_triangle, y, x))
  {
    attron(COLOR_PAIR(1));
    printw(" ");
    attroff(COLOR_PAIR(1));
  }
  else
  {
    attron(COLOR_PAIR(2));
    printw("|");
    attroff(COLOR_PAIR(2));
  }
  refresh();
}

t_triangle	*explore_line(t_triangle *my_triangle, int *flag)
{
  t_triangle	*tmp;
  int		count;

  count = 0;
  tmp = my_triangle;
  while (tmp->next && tmp->next->x == tmp->x)
  {
    if (tmp->del == 0)
      count++;
    tmp = tmp->next;
  }
  if (count % 2 != 0)
    while (my_triangle && !(*flag))
    {
      move(my_triangle->x, my_triangle->y);
      if (my_triangle->del == 0)
      {
	del_char(&my_triangle);
	*flag = 1;
      }
      my_triangle = my_triangle->next;
    }
  return (my_triangle);
}

void		do_the_ia(t_triangle **my_triangle)
{
  int		flag;
  int		x;
  int		y;
  t_triangle	*tmp;

  flag = 0;
  getyx(stdscr, y, x);
  while ((*my_triangle) && !flag)
  {
    if ((*my_triangle)->prev && (*my_triangle)->prev->x != (*my_triangle)->x)
    {
      tmp = explore_line(*my_triangle, &flag);
      my_triangle = &tmp;
    }
    my_triangle = &((*my_triangle)->next);
  }
  clean(my_triangle);
  move(y, x);
}
