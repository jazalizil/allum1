/*
** windows.c for sources in /home/dabbec_j/projets/sysunix/allum1/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Fri Jul 12 03:21:36 2013 jalil dabbech
** Last update Sat Jul 13 06:26:14 2013 jalil dabbech
*/

#include <ncurses.h>
#include "my_allum1.h"
#include "my_printf.h"

char		*draw_getname(int error)
{
  WINDOW	*get_name;
  char		*name;
  static int	player = 1;

  get_name = subwin(stdscr, 10, 25, LINES / 2 - 10, COLS / 2 - 10);
  wbkgd(get_name, COLOR_PAIR(3));
  wmove(get_name, 1, 5);
  waddstr(get_name, player == 1 ? "Welcome Player1 !" : "Welcome Player2 !");
  if (error)
  {
    wmove(get_name, 2, 1);
    wattron(get_name, COLOR_PAIR(6) | A_BOLD);
    waddstr(get_name, "Bad user name\n(max 8 char)");
    wattroff(get_name, COLOR_PAIR(6) | A_BOLD);
  }
  wmove(get_name, 4, 4);
  waddstr(get_name, "enter your name: \n\t");
  box(get_name, ACS_VLINE, ACS_HLINE);
  wrefresh(get_name);
  wgetstr(get_name, name);
  delwin(get_name);
  if (my_strlen(name) > 8 || my_strlen(name) == 0)
    return (NULL);
  player++;
  return (name);
}

void		draw_logo()
{
  int		x;
  int		y;

  attron(A_BOLD);
  move((x = 1), (y = COLS / 2 - 21));
  printw("   ##   #      #      #    # #    #  ##   ");
  move(++x, ++y);
  printw("  #  #  #      #      #    # ##  ## # #   ");
  move(++x, ++y);
  printw(" #    # #      #      #    # # ## #   #   ");
  move(++x, ++y);
  printw(" ###### #      #      #    # #    #   #   ");
  move(++x, ++y);
  printw(" #    # #      #      #    # #    #   #   ");
  move(++x, ++y);
  printw(" #    # ###### ######  ####  #    # ##### ");
  attroff(A_BOLD);
}

char		*get_name()
{
  char		*name;
  int		error;

  name = NULL;
  error = 0;
  while (!name)
  {
    name = draw_getname(error);
    if (!name)
      error++;
    clear();
  }
  return (name);
}

void		draw_window(int *nbr, t_triangle **my_triangle,
    			     t_player **players)
{
  static int	do_getname = 1;
  char		*name;

  bkgd(COLOR_PAIR(1));
  if (do_getname)
  {
    name = get_name();
    add_player(players, name);
    name = (nbr[PLAYERS] == 2 ? get_name() : "Computer");
    add_player(players, name);
  }
  do_getname = 0;
  clear();
  noecho();
  box(stdscr, ACS_VLINE, ACS_HLINE);
  draw_logo();
  move(2, 1);
  printw("Press Escape to quit");
  move(3, 1);
  printw("Press F3 to show help");
  refresh();
  draw_triangle(nbr[ROWS], LINES, COLS, my_triangle);
  chgat(1, A_UNDERLINE, 0, NULL);
}

void		show_rules()
{
  WINDOW	*rules;
  int		key;

  clear();
  rules = subwin(stdscr, LINES - 4, COLS - 4, 2, 2);
  wbkgd(rules, COLOR_PAIR(5));
  box(rules , ACS_VLINE, ACS_HLINE);
  wrefresh(rules);
  wmove(rules, 2, COLS / 2 - 4);
  waddstr(rules, "HELP");
  wmove(rules, 10, 1);
  waddstr(rules, " - Press Enter, Backspace or Del to delete a matchstick");
  wmove(rules, 11, 1);
  waddstr(rules, " - Move the cursor with the arrows");
  wmove(rules, 12, 1);
  waddstr(rules, " - Vim implementation is here ! Press H, J, K, L");
  waddstr(rules, " to respectively move left, down, up, right");
  wmove(rules, 13, 1);
  waddstr(rules, " - Press F3 to show this help window");
  wmove(rules, LINES - 4 - 2, COLS / 2 - 16);
  waddstr(rules, "Press escape to close this window");
  while ((key = getch()) != ESCAPE);
  delwin(rules);
  clear();
}
