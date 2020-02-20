##
## ETNA PROJECT  by group
## Makefile
## File description:
##      This file compiles
##

CC 		= gcc-8
CCDBG	= $(CC) -ggdb -g3 -std=c17
RM		= /bin/rm -rf
MAKE	= /usr/bin/make

CFLAGS	=  -std=c17
LDFLAGS = -export-dynamic $(shell sdl2-config --libs)

NAME	= bomberman

SRC	= src/main.c \
      src/window.c \
	  src/renderer.c \
	  src/parser.c \
	  src/player.c \
	  src/game.c 

OBJ	= $(SRC:.c=.o)

debug:
	$(CCDBG) $(CFLAGS) -o $(NAME) $(SRC) $(LDFLAGS)

lazyd:
	$(CCDBG) -o $(NAME) $(SRC) $(LDFLAGS)

lazy:
	$(CC) -o $(NAME) $(SRC) $(LDFLAGS)

all $(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all $(NAME) clean fclean re debug lazy
