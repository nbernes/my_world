/*
** EPITECH PROJECT, 2018
** unset_objects
** File description:
** ...
*/

#include "my_world.h"

void unset_objects(maps_t *maps, sfRenderWindow *window)
{
	sfRenderWindow_close(window);
	for (int cnt = 0; cnt < MAP_Y; cnt++) {
		free(maps->map2d[cnt]);
		free(maps->map3d[cnt]);
	}
	free(maps->map2d);
	free(maps->map3d);
}
