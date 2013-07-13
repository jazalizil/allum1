/*
** allum1.c for sources in /home/dabbec_j/projets/sysunix/allum1/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Tue Jul 02 14:12:31 2013 jalil dabbech
** Last update Sat Jul 13 06:26:15 2013 jalil dabbech
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_allum1.h"

void	my_init()
{
  initscr();
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLUE);
  init_pair(2, COLOR_WHITE, COLOR_MAGENTA);
  init_pair(3, COLOR_BLUE, COLOR_WHITE);
  init_pair(4, COLOR_MAGENTA, COLOR_BLUE);
  init_pair(5, COLOR_RED, COLOR_BLACK);
  init_pair(6, COLOR_RED, COLOR_WHITE);
  curs_set(0);
  keypad(stdscr, TRUE);
}

void		draw_triangle(int nb_rows, int many_row, int many_col,
    			t_triangle **my_triangle)
{
  int	x;
  int	i;
  int	j;
  int	del;
  int	xline;

  i = 0;
  x = many_col / 2;
  many_col /= 2;
  while (i < nb_rows)
  {
    j = many_col;
    while (j <= x)
    {
      move((xline = i + LINES / 2 - nb_rows / 2), j);
      my_put_in_list(my_triangle, xline, j);
      del = is_del(my_triangle, xline, j);
      my_printw(del ? " " : "|", del ? 1 : 2);
      j++;
    }
    x++;
    many_col--;
    i++;
  }
  move(xline, j - 1);
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

int		is_arrow(int key)
{
  int		keys[4] =
  {
    KEY_LEFT, KEY_RIGHT, VI_LEFT, VI_RIGHT
  };
  int		i;

  i = 0;
  while (i < 4)
  {
    if (key == keys[i])
      return (i);
    i++;
  }
  return (0);
}

void		select_and_del(t_triangle **my_triangle)
{
  int		key;
  int		mov;
  int		x;
  int		y;

  getyx(stdscr, y, x);
  while ((key = getch()) != SPACE)
    if ((mov = is_arrow(key)))
    {
      if (mov % 2 == 0 && is_in_list(my_triangle, y, x - 1))
      {
	move(y, --x);
	chgat(1, A_UNDERLINE, 0, NULL);
      }
      else if (mov % 2 == 1 && is_in_list(my_triangle, y, x + 1))
      {
	move(y, ++x);
	chgat(1, A_UNDERLINE, 0, NULL);
      }
    }
}

void		manage_key(int key, int *nbr, t_triangle **my_triangle,
    			    t_player **players)
{
  if (key == ENTER || key == KEY_BACKSPACE || key == KEY_DC)
  {
    del_char(my_triangle);
    if (nbr[PLAYERS] == 1)
      do_the_ia(my_triangle);
  }
  else if (key == KEY_F(3))
  {
    show_rules();
    clear();
    draw_window(nbr, my_triangle, players);
  }
  else if (key == SPACE)
    select_and_del(my_triangle);
  else
    move_cursor(key, my_triangle);
}

void		my_allum(int *nbr)
{
  int		key;
  t_triangle	*my_triangle;
  t_player	*players;

  my_triangle = NULL;
  players = NULL;
  key = 0;
  my_init();
  draw_window(nbr, &my_triangle, &players);
  refresh();
  raw();
  while ((key = getch()) != ESCAPE)
  {
    manage_key(key, nbr, &my_triangle, &players);
    refresh();
    players = players->next;
  }
  endwin();
  /*
  my_free_list(my_triangle, players);
  */
}
