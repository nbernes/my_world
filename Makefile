##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

NAME	=	my_world

SOURCES	=	sources/main.c				\
		sources/project_iso_point.c		\
		sources/create_line.c			\
		sources/event_closed.c			\
		sources/create_2d_map.c			\
		sources/draw_2d_map.c			\
		sources/frame.c				\
		sources/key_pressed.c			\
		sources/more_key_pressed.c		\
		sources/unset_objects.c			\
		sources/apply_zoom.c			\
		sources/change_height.c			\
		sources/outline_corners.c		\
		sources/change_corner_height.c		\
		sources/change_tile_height.c		\
		sources/retrieve_height_values.c	\
		sources/find_limits.c			\
		sources/modif_point.c			\
		sources/reinit_map.c			\
		sources/set_tiles.c			\
		sources/create_buttons.c		\
		sources/check_mouse.c			\
		sources/create_object.c			\
		sources/display_help.c			\
		sources/my_strlen.c			\
		sources/display_info.c			\
		sources/highlight_tiles.c

OBJS	=	$(SOURCES:.c=.o)

LIB	=	-l c_graph_prog -lm

INCLUDE	=	-I./include/

CFLAGS	=	$(INCLUDE) -Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJS)
		gcc -o $(NAME) $(OBJS) $(LIB)
clean:
		rm -rf $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
