/*
** EPITECH PROJECT, 2018
** my_world : check_mouse_coords
** File description:
** check if the mouse is pointing a button
*/

#include "my_world.h"

void check_mouse_pos(maps_t *maps, sfEvent *event, buttons_t *buttons)
{
	int x = event->mouseMove.x;
	int y = event->mouseMove.y;

	if ((x > 300 && x < 810) || (x > 1110 && x < 1620) || y < 927 ) {
		buttons->left->rect.left = 0;
		buttons->right->rect.left = 0;
	}
	if (maps->fx != 2)
		buttons->mid->rect.left = 0;
	if (maps->fx == 4)
		maps->fx = 1;
}

void check_mouse_hover(sfEvent *event, buttons_t *buttons)
{
	int x = event->mouseMove.x;
	int y = event->mouseMove.y;

	if (x < 300 && y > 927 && x >= 0) {
		buttons->left->rect.left = 300;
	} else if (x > 810 && x < 1110 && y > 927) {
		buttons->mid->rect.left = 300;
	} else if (x > 1620 && y > 927) {
		buttons->right->rect.left = 300;
	}
}

int mid_button(maps_t *maps, sfEvent *event, buttons_t *buttons)
{
	int x = event->mouseButton.x;
	int y = event->mouseButton.y;
	static int i = 1;

	if (i != 2 && x > 810 && x < 1110 && y > 927) {
		buttons->mid->rect.left = 600;
		maps->fx = 2;
		i = 2;
		return (0);
	}
	if (i == 2 && x > 810 && x < 1110 && y > 927) {
		buttons->mid->rect.left = 600;
		maps->fx = 1;
		i = 1;
		return (0);
	}
	return (1);
}

int first_last_buttons(maps_t *maps, sfEvent *event, buttons_t *buttons)
{
	int x = event->mouseButton.x;
	int y = event->mouseButton.y;

	if (x < 300 && y > 927) {
		buttons->left->rect.left = 600;
		maps->fx = 4;
		return (0);
	}
	if (x > 1620 && y > 927) {
		buttons->right->rect.left = 600;
		maps->fx = 3;
		return (0);
	}
	return (1);
}

void check_mouse_clic(maps_t *maps, sfEvent *event, buttons_t *buttons)
{
	if (event->type != sfEvtMouseButtonPressed)
		return;
	if (first_last_buttons(maps, event, buttons) == 0)
		return;
	else if (mid_button(maps, event, buttons) == 0)
		return;
}
