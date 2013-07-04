/*
** allum1.c for sources in /home/dabbec_j/projets/allum1/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Tue Jul 02 14:12:31 2013 jalil dabbech
** Last update Thu Jul 04 17:08:27 2013 jalil dabbech
*/

#include <ncurses.h>
#include <signal.h>
#include "my_allum1.h"

int	rows;

void	init_curse()
{
  initscr();
  start_color();
  init_pair(1,COLOR_YELLOW, COLOR_BLUE);
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

WINDOW		*draw_window(int nb_rows, t_triangle **my_triangle)
{
  int		many_col;
  int		many_row;
  WINDOW	*menubar;

  bkgd(COLOR_PAIR(1));
  getmaxyx(stdscr, many_row, many_col);
  menubar = subwin(stdscr, 1, many_col, 0, 0);
  draw_menubar(menubar);
  move(2, 0);
  printw("Press Escape to quit");
  refresh();
  draw_triangle(nb_rows, many_row, many_col, my_triangle);
  return (menubar);
}

void		my_allum(int nb_allum, int nb_rows, int nb_player)
{
  int		key;
  int		x;
  int		y;
  t_triangle	*my_triangle;
  WINDOW	*menubar;

  my_triangle = NULL;
  key = 0;
  init_curse();
  chgat(1, A_REVERSE | A_BOLD, 0, NULL);
  menubar = draw_window(nb_rows, &my_triangle);
  raw();
  while (key != ESCAPE)
  {
    key = getch();
    getyx(stdscr, y, x);
    if (key == KEY_UP)
      move(--y, x);
    else if (key == KEY_DOWN)
      move(++y, x);
    else if (key == KEY_LEFT)
      move(y, --x);
    else if (key == KEY_RIGHT)
      move(y, ++x);
    if (is_in_list(&my_triangle, y, x))
      chgat(1, A_NORMAL, 0, NULL);
    else
      chgat(1, A_REVERSE, 0, NULL);
    refresh();
  }
  delwin(menubar);
  endwin();
}
