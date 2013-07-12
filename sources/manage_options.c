/*
** manage_options.c for sources in /home/dabbec_j/projets/sysunix/allum1/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Tue Jul 02 12:52:27 2013 jalil dabbech
** Last update Fri Jul 12 04:54:37 2013 jalil dabbech
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_printf.h"
#include "my_allum1.h"

void	show_help(int *nbr, int useless)
{
  my_printf("Usage: ./allum1 [options] args\n");
  my_printf("Options:\n");
  my_printf("\t-r --rows\tset rows number\n");
  my_printf("\t-p --player\tset number of player (max 2 players)\n");
  my_printf("By default, nb_rows = 4 and nb_allum = 16\n");
  my_printf("nb_allum must be equal to square of nb_rows.\n");
  my_printf("Rules:\teach player choose one matchstick, the looser is the ");
  my_printf("player who choose the last one\n");
  if (useless || nbr)
    exit(EXIT_SUCCESS);
}

void	set_nbrows(int *nbr, int to_set)
{
  nbr[ROWS] = to_set;
}

void	set_nbplayer(int *nbr, int to_set)
{
  nbr[PLAYERS] = to_set;
  if (nbr[PLAYERS] > 2)
  {
    write(2, "./allum1: Too much player\n", 26);
    exit(EXIT_FAILURE);
  }
  free(nbr);
}
