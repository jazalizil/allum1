/*
** windows.c for sources in /home/dabbec_j/projets/sysunix/allum1/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Fri Jul 12 03:21:36 2013 jalil dabbech
** Last update Fri Jul 12 14:55:25 2013 jalil dabbech
*/

#include <ncurses.h>
#include "my_allum1.h"

char		*draw_getname()
{
  WINDOW	*get_name;
  char		*name;
  static int	player = 1;

  get_name = subwin(stdscr, 10, 25, LINES / 2 - 10, COLS / 2 - 10);
  wbkgd(get_name, COLOR_PAIR(3));
  wmove(get_name, 1, 5);
  waddstr(get_name, player == 1 ? "Welcome Player1 !" : "Welcome Player2 !");
  wmove(get_name, 4, 4);
  waddstr(get_name, "enter your name: \n\t");
  player++;
  box(get_name, ACS_VLINE, ACS_HLINE);
  wrefresh(get_name);
  wgetstr(get_name, name);
  wrefresh(get_name);
  delwin(get_name);
  return (name);
}

WINDOW		*draw_window(int *nbr, t_triangle **my_triangle,
    			     t_player **players)
{
  WINDOW	*ret;
  static int	do_getname = 1;
  char		*name;

  bkgd(COLOR_PAIR(1));
  if (do_getname)
  {
    name = draw_getname();
    add_player(players, name);
    name = (nbr[PLAYERS] == 2 ? draw_getname() : "Computer");
    add_player(players, name);
  }
  do_getname = 0;
  clear();
  noecho();
  ret = draw_menubar();
  move(2, 0);
  printw("Press Escape to quit");
  refresh();
  draw_triangle(nbr[ROWS], LINES, COLS, my_triangle);
  chgat(1, A_UNDERLINE, 0, NULL);
  return (ret);
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
  waddstr(rules, "RULES"); 
  wmove(rules, 3, 1);
  waddstr(rules, " - The loser is the player who choose the last matchstick");
  key = getch();
  delwin(rules);
  clear();
}

WINDOW		*draw_menubar()
{
  WINDOW	*menubar;

  menubar = subwin(stdscr, 1, COLS, 0, 0);
  wbkgd(menubar, COLOR_PAIR(4));
  waddstr(menubar, "Rules (F3)");
  return (menubar);
}