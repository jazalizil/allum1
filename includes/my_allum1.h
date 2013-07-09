/*
** my_allum1.h for includes in /home/dabbec_j/projets/allum1/includes
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Tue Jul 02 12:53:36 2013 jalil dabbech
** Last update Tue Jul 09 18:51:14 2013 jalil dabbech
*/

#ifndef ALLUM1_H_
# define ALLUM1_H_
# define ESCAPE 27
# define SPACE 32
# define VI_UP 106
# define VI_DOWN 107
# define VI_LEFT 104
# define VI_RIGHT 108

typedef struct		s_opt
{
  char			*short_str;
  char			*long_str;
  void			(*fct)(int *, int *, int);
}			t_opt;

typedef struct		s_triangle
{
  int			x;
  int			y;
  int			del;
  struct s_triangle	*next;
  struct s_triangle	*prev;
}			t_triangle;

typedef struct		s_keys
{
  int			key;
  void			(*fct)(t_triangle **);
}			t_keys;

void			show_help(int *, int *, int);
void			set_nbrows(int *, int *, int);
void			set_nbplayer(int *, int *, int);
int			putch(int);
void			my_allum(int, int);
void			my_put_in_list(t_triangle **, int, int);
void			my_free_list(t_triangle *);
int			is_in_list(t_triangle **, int, int);
void			set_del(t_triangle **, int, int);
int			is_del(t_triangle **, int, int);
void			move_cursor(int, t_triangle **);
void			move_down(t_triangle **);
void			move_up(t_triangle **);
void			move_right(t_triangle **);
void			move_left(t_triangle **);
void			do_the_ia(t_triangle **);
void			del_char(t_triangle **);

#endif /* !ALLUM1_H_ */
