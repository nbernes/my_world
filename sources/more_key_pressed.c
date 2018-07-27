/*
** EPITECH PROJECT, 2018
** my_world : more_key_pressed
** File description:
** check other key pressed
*/

#include "my_world.h"

maps_t *quit(sfEvent *event, sfRenderWindow *window)
{
	if (event->key.code == sfKeyEscape || event->key.code == sfKeyQ)
		sfRenderWindow_close(window);
	return (NULL);
}
