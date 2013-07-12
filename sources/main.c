/*
** main.c for sources in /home/dabbec_j/projets/sysunix/allum1/sources
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Tue Jul 02 12:18:27 2013 jalil dabbech
** Last update Fri Jul 12 05:13:36 2013 jalil dabbech
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_printf.h"
#include "my_allum1.h"
#include "my.h"

t_opt	g_opt[] =
{
  {"-r", "--rows", &set_nbrows},
  {"-p", "--player", &set_nbplayer},
  {"-h", "--help", &show_help}
};

void	check_option(char *str, int j)
{
  if (str[0] == '-' && j == 3)
    {
      write(2, "./allum1: Unknow option ", 24);
      write(2, str, my_strlen(str));
      write(2, "\n", 1);
      exit(EXIT_FAILURE);
    }
}

void	check_args(int *nbr, char **av)
{
  int	j;
  int	i;

  i = 1;
  while (av[i])
  {
    j = 0;
    while (j < 3)
    {
      if (my_strcmp(av[i], g_opt[j].short_str) == 0 ||
	  my_strcmp(av[i], g_opt[j].long_str) == 0)
      {
	g_opt[j].fct(nbr, my_getnbr(av[i + 1]));
	j = 4;
      }
      j++;
    }
    check_option(av[i], j);
    i++;
  }
}

int		main(int ac, char **av)
{
  int		*nbr;

  if (!(nbr = malloc(2 * sizeof(int))))
    return (-1);
  nbr[ROWS] = 4;
  nbr[PLAYERS] = 1;
  if (ac > 1)
    check_args(nbr, av);
  my_allum(nbr);
  return (0);
}
