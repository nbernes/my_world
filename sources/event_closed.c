/*
** EPITECH PROJECT, 2018
** my_world : event_closed
** File description:
** close with events
*/

#include "my_world.h"

void event_closed(maps_t *maps, sfEvent *event)
{
	if (event->type == sfEvtClosed)
		sfRenderWindow_close(maps->window);
}
