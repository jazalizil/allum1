##
## Makefile for allum1 in /home/dabbec_j/projets/allum1
## 
## Made by jalil dabbech
## Login   <dabbec_j@epitech.net>
## 
## Started on  Thu Jun 06 16:16:01 2013 jalil dabbech
## Last update Tue Jul 09 19:03:42 2013 jalil dabbech
##

NAME	=	allum1

SRC	=	sources/main.c \
		sources/manage_options.c \
		sources/putch.c \
		sources/allum1.c \
		sources/my_list.c \
		sources/manage_movment.c \
		sources/my_ia.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -Iincludes/

CFLAGS	=	-W -Werror -Wall -Wextra -pedantic -ansi

LIB_DIR	=	my

MK_LIB	=	@(cd $(LIB_DIR) && make)

MK_CLIB	=	@(cd $(LIB_DIR) && make clean)

MK_FLIB	=	@(cd $(LIB_DIR) && make fclean)

LIB	=	-lncurses -lmy -L.

RM	=	rm -f

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(MK_LIB)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

clean	:
		$(RM) $(OBJ)
		$(MK_CLIB)

fclean	:	clean
		$(RM) $(NAME)
		$(MK_FLIB)

re	:	fclean all
