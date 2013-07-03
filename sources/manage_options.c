/*
** manage_options.c for sources in /home/dabbec_j/projets/allum1/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Tue Jul 02 12:52:27 2013 jalil dabbech
** Last update Wed Jul 03 17:39:28 2013 jalil dabbech
*/

#include "my_printf.h"
#include <stdlib.h>

void	show_help(int *nb_allum, int *nb_rows, int *nb_player, int useless)
{
  my_printf("Usage: ./allum1 [options] args\n");
  my_printf("Options:\n\t-n --number\tset allums number\n");
  my_printf("\t-r --rows\tset rows number\n");
  my_printf("\t-p --player\tset number of player\n");
  my_printf("By default, nb_rows = 4 and nb_allum = 16\n");
  my_printf("nb_allum must be equal to square of nb_rows.\n");
  my_printf("Rules:\teach player choose one matchstick, the looser is the ");
  my_printf("player who choose the last one\n");
  if (useless || *nb_allum || *nb_rows || *nb_player)
    exit(EXIT_SUCCESS);
}

void	set_nballum(int *nb_allum, int *nb_rows, int *nb_player, int to_set)
{
  if (*nb_rows || !(*nb_rows) || *nb_player)
    *nb_allum = to_set;
}

void	set_nbrows(int *nb_allum, int *nb_rows, int *nb_player, int to_set)
{
  if (*nb_allum || !(*nb_allum) || *nb_player)
    *nb_rows = to_set;
}

void	set_nbplayer(int *nb_allum, int *nb_rows, int *nb_player, int to_set)
{
  if (*nb_allum || *nb_rows || !(*nb_allum))
    *nb_player = to_set;
}
