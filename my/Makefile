##
## Makefile for my in /home/dabbec_j/projets/allum1/my
## 
## Made by jalil dabbech
## Login   <dabbe_j@epitech.net>
## 
## Started on  Sun Apr 28 16:22:29 2013 jalil dabbech
## Last update Tue Jul 02 12:42:39 2013 jalil dabbech
##


NAME	=	../libmy.a

SRC	=	flag_u.c \
		flags_nbr.c \
		flags_str.c \
		my_printf.c \
		my_put_addr.c \
		my_put_unbr.c \
		my_put_unbrbase.c \
		my_putchar.c \
		my_putstr.c \
		my_puterror.c \
		my_strlen.c \
		my_strcmp.c \
		get_next_line.c \
		my_malloc.c \
		my_get_nbr.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -I../includes -c

AR	=	ar rc

RANLIB	=	ranlib

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(SRC)	
		$(CC) $(SRC)
		$(AR) $(NAME) $(OBJ)
		$(RANLIB) $(NAME)

clean:	
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
