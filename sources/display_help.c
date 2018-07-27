/*
** EPITECH PROJECT, 2018
** display_help.c
** File description:
** ...
*/

#include "my_world.h"

sfText *create_text(sfText *txt, const char *str)
{
	sfVector2f pos = {1850, 110};
	sfVector2f origin = {0, 0};
	sfFont *font = sfFont_createFromFile("pictures/Bitter-Regular.otf");

	sfText_setFont(txt, font);
	sfText_setColor(txt, sfColor_fromRGB(150, 150, 150));
	sfText_setCharacterSize(txt, 17);
	sfText_setString(txt, str);
	origin = sfText_findCharacterPos(txt, my_strlen(str) - 1);
	sfText_setOrigin(txt, origin);
	sfText_setPosition(txt, pos);
	return (txt);
}

sfRenderWindow *display_help(sfRenderWindow *window, int flag)
{
	sfText *txt = sfText_create();

	switch (flag) {
	case 1: txt = create_text(txt, \
"Sets corners' height to random values.");
		break;
	case 2: txt = create_text(txt, \
"Switches between tile and corner selection.");
		break;
	case 3: txt = create_text(txt, "Reinitializes the tiles' altitude.");
		break;
	case 4: txt = create_text(txt, show_info());
		break;
	}
	sfRenderWindow_drawText(window, txt, NULL);
	sfText_destroy(txt);
	return (window);
}

int identify_x_coord(int x)
{
	int flag = 0;

	if ((x < 300) && (x >= 0))
		flag = 1;
	else if ((x > 810) && (x < 1110))
		flag = 2;
	else {
		if ((x > 1620) && (x <= 1920))
			flag = 3;
	}
	return (flag);
}

int select_help_txtbox(sfEvent *evt, int flag)
{
	int x = evt->mouseMove.x;

	if ((evt->type == sfEvtMouseMoved) && (evt->mouseMove.y > 927)) {
		flag = identify_x_coord(x);
	} else if (evt ->type == sfEvtMouseMoved) {
		if (evt->mouseMove.x > 1800 && evt->mouseMove.x < 1850 && \
evt->mouseMove.y > 50 && evt->mouseMove.y < 100)
			flag = 4;
		else
			flag = 0;
	}
	return (flag);
}
