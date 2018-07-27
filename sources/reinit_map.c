/*
** EPITECH PROJECT, 2018
** reinit_map.c
** File description:
** ...
*/

#include "my_world.h"

int **set_rand(int **map3d)
{
	static unsigned int seed = 5;
	sfVector2i cnt;

	for (cnt.y = 0; cnt.y < MAP_Y; cnt.y++) {
		for (cnt.x = 0; cnt.x < MAP_X; cnt.x++) {
			srand(seed);
			map3d[cnt.y][cnt.x] = rand() % 10;
			seed += 23;
		}
	}
	return (map3d);
}

int **set_zeros(int **map3d)
{
	sfVector2i cnt;

	for (cnt.y = 0; cnt.y < MAP_Y; cnt.y++) {
		for (cnt.x = 0; cnt.x < MAP_X; cnt.x++)
			map3d[cnt.y][cnt.x] = 0;
	}
	return (map3d);
}

maps_t *reinit_map(maps_t *maps, cam_t *cam)
{
	if (maps->fx == 3) {
		maps->map3d = set_zeros(maps->map3d);
		maps->map2d = change_2d_map(maps->map3d, maps->map2d, cam);
	} else if (maps->fx == 4) {
		maps->map3d = set_rand(maps->map3d);
		maps->map2d = change_2d_map(maps->map3d, maps->map2d, cam);
	}
	return (maps);
}
