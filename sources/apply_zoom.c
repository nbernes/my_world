/*
** EPITECH PROJECT, 2018
** my_world : apply_zoom
** File description:
** apply zoom to the map
*/

#include "my_world.h"

sfVector2f **apply_zoom(sfVector2f **map2d, int **map3d, int value, \
cam_t *cam)
{
	if (value > 0) {
		cam->scale.x += 1.28;
		cam->scale.y += 1.28;
		cam->scale.z += 0.20;
	} else {
		cam->scale.x -= 1.28;
		cam->scale.y -= 1.28;
		cam->scale.z -= 0.20;
	}
	map2d = change_2d_map(map3d, map2d, cam);
	return (map2d);
}
