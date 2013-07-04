/*
** my_allum1.h for includes in /home/dabbec_j/projets/allum1/includes
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Tue Jul 02 12:53:36 2013 jalil dabbech
** Last update Thu Jul 04 17:08:29 2013 jalil dabbech
*/

#ifndef ALLUM1_H_
# define ALLUM1_H_
# define ESCAPE 27

typedef struct		s_opt
{
  char			*short_str;
  char			*long_str;
  void			(*fct)(int *, int *, int *, int);
}			t_opt;

typedef struct		s_triangle
{
  int			x;
  int			y;
  struct s_triangle	*next;
}			t_triangle;

void			show_help(int *, int *, int *, int);
void			set_nballum(int *, int *, int *, int);
void			set_nbrows(int *, int *, int *, int);
void			set_nbplayer(int *, int *, int *, int);
int			putch(int);
void			my_allum(int, int, int);
void			my_put_in_list(t_triangle **, int, int);
void			my_free_list(t_triangle *);
int			is_in_list(t_triangle **, int, int);

#endif /* !ALLUM1_H_ */
