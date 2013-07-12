/*
** my_printw.c for sources in /home/dabbec_j/projets/sysunix/allum1/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Fri Jul 12 04:37:31 2013 jalil dabbech
** Last update Fri Jul 12 04:40:29 2013 jalil dabbech
*/

#include <ncurses.h>

void	my_printw(char *str, int x)
{
  x >= 0 ? attron(COLOR_PAIR(x)) : x ;
  printw(str);
  x >= 0 ? attroff(COLOR_PAIR(x)) : x ;
} 
