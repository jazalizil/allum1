/*
** my_allum1.h for includes in /home/dabbec_j/projets/allum1/includes
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Tue Jul 02 12:53:36 2013 jalil dabbech
** Last update Tue Jul 02 18:53:23 2013 jalil dabbech
*/

#ifndef ALLUM1_H_
# define ALLUM1_H_
# define ESCAPE 27
# define UP 259
# define DOWN 258
# define RIGHT 261
# define LEFT 260

typedef struct	s_opt
{
  char		*short_str;
  char		*long_str;
  void		(*fct)(int *, int *, int *, int);
}		t_opt;

void		show_help(int *, int *, int *, int);
void		set_nballum(int *, int *, int *, int);
void		set_nbrows(int *, int *, int *, int);
void		set_nbplayer(int *, int *, int *, int);
int		putch(int);
void		my_allum(int, int, int);

#endif /* !ALLUM1_H_ */
