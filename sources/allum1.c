/*
** allum1.c for sources in /home/dabbec_j/projets/sysunix/allum1/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Tue Jul 02 14:12:31 2013 jalil dabbech
** Last update Fri Jul 12 05:13:37 2013 jalil dabbech
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_allum1.h"

void	my_init()
{
  initscr();
  start_color();
  init_pair(1,COLOR_WHITE, COLOR_BLUE);
  init_pair(2,COLOR_WHITE, COLOR_MAGENTA);
  init_pair(3,COLOR_BLUE, COLOR_WHITE);
  init_pair(4,COLOR_BLUE, COLOR_WHITE);
  init_pair(5,COLOR_RED, COLOR_BLACK);
  curs_set(0);
  keypad(stdscr,TRUE);
}

void	draw_triangle(int nb_rows, int many_row, int many_col,
    			t_triangle **my_triangle)
{
  int	x;
  int	i;
  int	j;
  int	del;

  i = many_row / 2 - nb_rows;
  x = many_col / 2;
  many_col /= 2;
  while (i <= many_row / 2)
  {
    j = many_col;
    while (j <= x)
    {
      move(i, j);
      my_put_in_list(my_triangle, i, j);
      del = is_del(my_triangle, i, j);
      my_printw(del ? " " : "|", del ? 1 : 2);
      j++;
    }
    x++;
    many_col--;
    i++;
  }
  move(i - 1, j - 1);
}

void		del_char(t_triangle **my_triangle)
{
  int		x;
  int		y;

  getyx(stdscr, y, x);
  chgat(1, !A_UNDERLINE, 0, NULL);
  my_printw(" ", 1);
  set_del(my_triangle, y, x);
  if (is_in_list(my_triangle, y, x - 1))
    move(y, x - 1);
  else if (is_in_list(my_triangle, y, x + 1))
    move(y, x + 1);
  else if (is_in_list(my_triangle, y - 1, x))
    move(y - 1, x);
  else
    move(y + 1, x);
  chgat(1, A_UNDERLINE, 0, NULL);
}

WINDOW		*manage_key(int key, int *nbr, t_triangle **my_triangle,
    			    t_player **players)
{
  WINDOW	*win;

  win = NULL;
  if (key == SPACE || key == KEY_BACKSPACE || key == KEY_DC)
  {
    del_char(my_triangle);
    if (nbr[PLAYERS] == 1)
      do_the_ia(my_triangle);
  }
  else if (key == RULES)
  {
    show_rules();
    clear();
    win = draw_window(nbr, my_triangle, players);
  }
  else
    move_cursor(key, my_triangle);
  return (win);
}

void		my_allum(int *nbr)
{
  int		key;
  t_triangle	*my_triangle;
  WINDOW	*win;
  WINDOW	*tmp;
  t_player	*players;

  my_triangle = NULL;
  players = NULL;
  key = 0;
  my_init();
  win = draw_window(nbr, &my_triangle, &players);
  refresh();
  raw();
  while ((key = getch()) != ESCAPE)
  {
    if ((tmp = manage_key(key, nbr, &my_triangle, &players)))
      win = tmp;
    refresh();
    players = players->next;
  }
  delwin(win);
  endwin();
}
