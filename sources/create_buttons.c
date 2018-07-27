/*
** EPITECH PROJECT, 2018
** my_world : create_buttons
** File description:
** create the buttons structures with the 3 buttons
*/

#include "my_world.h"

buttons_t *create_buttons(sfIntRect rect)
{
	sfVector2f mv = {0, 927};
	buttons_t *buttons = malloc(sizeof(buttons_t));
	object_t *left = create_object("pictures/pink-red.bmp", rect, mv);
	object_t *mid = NULL;
	object_t *right = NULL;

	if (buttons == NULL)
		return (NULL);
	buttons->left = left;
	mv.x = 810;
	mid = create_object("pictures/pink-red.bmp", rect, mv);
	buttons->mid = mid;
	mv.x = 1620;
	right = create_object("pictures/pink-red.bmp", rect, mv);
	buttons->right = right;
	if (!right || !left || !mid)
		return (NULL);
	return (buttons);
}
