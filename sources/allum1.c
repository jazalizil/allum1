/*
** allum1.c for sources in /home/dabbec_j/projets/allum1/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Tue Jul 02 14:12:31 2013 jalil dabbech
** Last update Tue Jul 09 18:58:07 2013 jalil dabbech
*/

#include <ncurses.h>
#include <unistd.h>
#include "my_allum1.h"

void	init_curse()
{
  initscr();
  start_color();
  init_pair(1,COLOR_WHITE, COLOR_BLUE);
  init_pair(2,COLOR_WHITE, COLOR_MAGENTA);
  init_pair(3,COLOR_RED, COLOR_WHITE);
  init_pair(4,COLOR_BLUE, COLOR_WHITE);
  curs_set(0);
  noecho();
  keypad(stdscr,TRUE);
}

void	draw_menubar(WINDOW *menubar)
{
  wbkgd(menubar, COLOR_PAIR(4));
  waddstr(menubar, "Help");
}

void	draw_triangle(int nb_rows, int many_row, int many_col,
    			t_triangle **my_triangle)
{
  int	x;
  int	i;
  int	j;

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
      attron(COLOR_PAIR(2));
      printw("|");
      attroff(COLOR_PAIR(2));
      j++;
    }
    x++;
    many_col--;
    i++;
  }
  move(i - 1, j - 1);
}

WINDOW		*draw_window(int nb_rows, int nb_player,
    				t_triangle **my_triangle)
{
  WINDOW	*menubar;

  bkgd(COLOR_PAIR(1));
  menubar = subwin(stdscr, 1, COLS, 0, 0);
  draw_menubar(menubar);
  move(2, 0);
  printw("Press Escape to quit");
  refresh();
  draw_triangle(nb_rows, LINES, COLS, my_triangle);
  return (menubar);
}

void		del_char(t_triangle **my_triangle)
{
  int		x;
  int		y;

  getyx(stdscr, y, x);
  chgat(1, !A_UNDERLINE, 0, NULL);
  attron(COLOR_PAIR(1));
  printw(" ");
  attroff(COLOR_PAIR(1));
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

void		my_allum(int nb_rows, int nb_player)
{
  int		key;
  t_triangle	*my_triangle;
  WINDOW	*menubar;

  my_triangle = NULL;
  key = 0;
  init_curse();
  menubar = draw_window(nb_rows, nb_player, &my_triangle);
  chgat(1, A_UNDERLINE, 0, NULL);
  refresh();
  raw();
  while ((key = getch()) != ESCAPE)
  {
    if (key == SPACE || key == KEY_BACKSPACE || key == KEY_DC)
    {
      del_char(&my_triangle);
      if (nb_player == 1)
	do_the_ia(&my_triangle);
    }
    else
      move_cursor(key, &my_triangle);
    refresh();
  }
  delwin(menubar);
  endwin();
}
