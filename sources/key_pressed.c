/*
** EPITECH PROJECT, 2018
** my_world : key_pressed
** File description:
** key pressed
*/

#include "my_world.h"

maps_t *trigger_zoom(sfEvent *event, maps_t *maps, cam_t *cam)
{
	if (event->key.code == sfKeyUp && cam->scale.x < 256)
		maps->map2d = apply_zoom(maps->map2d, maps->map3d, \
1, cam);
	else if (event->key.code == sfKeyDown && cam->scale.x > 10)
		maps->map2d = apply_zoom(maps->map2d, maps->map3d, \
-1, cam);
	return (maps);
}

maps_t *key_pressed(sfEvent *event, maps_t *maps, cam_t *cam)
{
	if (event->key.type == sfEvtKeyPressed) {
		trigger_zoom(event, maps, cam);
		quit(event, maps->window);
	}
	return (maps);
}
