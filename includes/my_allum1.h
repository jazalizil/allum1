/*
** my_allum1.h for includes in /home/dabbec_j/projets/sysunix/allum1/includes
** 
** Made by jalil dabbech
** Login   <dabbec_j@epitech.net>
** 
** Started on  Tue Jul 02 12:53:36 2013 jalil dabbech
** Last update Sat Jul 13 05:26:07 2013 jalil dabbech
*/

#ifndef ALLUM1_H_
# define ALLUM1_H_
# define ROWS 0
# define PLAYERS 1
# define ESCAPE 27
# define SPACE 32
# define ENTER 10
# define VI_UP 106
# define VI_DOWN 107
# define VI_LEFT 104
# define VI_RIGHT 108

#include <ncurses.h>

typedef struct		s_opt
{
  char			*short_str;
  char			*long_str;
  void			(*fct)(int *, int);
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

typedef struct		s_player
{
  char			*name;
  int			is_turn;
  struct s_player	*next;
}			t_player;

void			show_help(int *, int);
void			set_nbrows(int *, int);
void			set_nbplayer(int *, int);
void			my_allum(int *);
void			my_put_in_list(t_triangle **, int, int);
void			my_free_list(t_triangle *, t_player *);
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
void			show_rules();
void			draw_window(int *, t_triangle **, t_player **);
char			*draw_getname();
void			draw_triangle(int, int, int, t_triangle **);
void			add_player(t_player **, char *);
void			my_printw(char *, int);

#endif /* !ALLUM1_H_ */
