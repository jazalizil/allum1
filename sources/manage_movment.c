/*
** manage_movment.c for sources in /home/dabbec_j/projets/sysunix/allum1/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Mon Jul 08 15:47:57 2013 jalil dabbech
** Last update Fri Jul 12 04:32:20 2013 jalil dabbech
*/

#include <ncurses.h>
#include <unistd.h>
#include "my_allum1.h"

t_keys	g_keys[] =
{
  {KEY_UP, &move_up},
  {KEY_DOWN, &move_down},
  {KEY_LEFT, &move_left},
  {KEY_RIGHT, &move_right},
  {VI_UP, &move_up},
  {VI_DOWN, &move_down},
  {VI_LEFT, &move_left},
  {VI_RIGHT, &move_right}
};

void	move_cursor(int key_input, t_triangle **my_triangle)
{
  int	i;

  i = 0;
  while (i < 8)
  {
    if (key_input == g_keys[i].key)
      g_keys[i].fct(my_triangle);
    i++;
  }
}

void	move_up(t_triangle **my_triangle)
{
  int	x;
  int	y;

  getyx(stdscr, y, x);
  if (is_in_list(my_triangle, y - 1, x))
  {
    chgat(1, !A_UNDERLINE, 0, NULL);
    if (!(is_del(my_triangle, y, x)))
    {
      attron(COLOR_PAIR(2));
      printw("|");
      attroff(COLOR_PAIR(2));
    }
    else
    {
      attron(COLOR_PAIR(1));
      printw(" ");
      attroff(COLOR_PAIR(1));
    }
    move(--y, x);
    chgat(1, A_UNDERLINE, 0, NULL);
  }
}

void	move_down(t_triangle **my_triangle)
{
  int	x;
  int	y;

  getyx(stdscr, y, x);
  if (is_in_list(my_triangle, y + 1, x))
  {
    chgat(1, !A_UNDERLINE, 0, NULL);
    if (!(is_del(my_triangle, y, x)))
    {
      attron(COLOR_PAIR(2));
      printw("|");
      attroff(COLOR_PAIR(2));
    }
    else
    {
      attron(COLOR_PAIR(1));
      printw(" ");
      attroff(COLOR_PAIR(1));
    }
    move(++y, x);
    chgat(1, A_UNDERLINE, 0, NULL);
  }
}

void	move_left(t_triangle **my_triangle)
{
  int	x;
  int	y;

  getyx(stdscr, y, x);
  if (is_in_list(my_triangle, y, x - 1))
  {
    chgat(1, !A_UNDERLINE, 0, NULL);
    if (!(is_del(my_triangle, y, x)))
    {
      attron(COLOR_PAIR(2));
      printw("|");
      attroff(COLOR_PAIR(2));
    }
    else
    {
      attron(COLOR_PAIR(1));
      printw(" ");
      attroff(COLOR_PAIR(1));
    }
    move(y, --x);
    chgat(1, A_UNDERLINE, 0, NULL);
  }
}

void	move_right(t_triangle **my_triangle)
{
  int	x;
  int	y;

  getyx(stdscr, y, x);
  if (is_in_list(my_triangle, y, x + 1))
  {
    chgat(1, !A_UNDERLINE, 0, NULL);
    if (!(is_del(my_triangle, y, x)))
    {
      attron(COLOR_PAIR(2));
      printw("|");
      attroff(COLOR_PAIR(2));
    }
    else
    {
      attron(COLOR_PAIR(1));
      printw(" ");
      attroff(COLOR_PAIR(1));
    }
    move(y, ++x);
    chgat(1, A_UNDERLINE, 0, NULL);
  }
}
