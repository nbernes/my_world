/*
** EPITECH PROJECT, 2018
** my_world : change_height
** File description:
** modify_height
*/

#include "my_world.h"

maps_t *change_height(sfEvent *event, maps_t *maps, cam_t *cam)
{
	static sfVector2i pos = {- 1, - 1};

	switch (maps->fx) {
	case 1: if (event->type == sfEvtMouseButtonPressed && \
event->mouseButton.button == sfMouseLeft) {
			pos = get_corner_position(event, maps);
			maps->fx = -1;
		}
		break;
	case -1: if (event->type == sfEvtMouseButtonReleased && pos.x != -1)
			unset_corner(maps, pos, cam);
		else
			modif_corner(event, maps, pos);
		break;
	}
	return (maps);
}
