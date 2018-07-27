/*
** EPITECH PROJECT, 2018
** my_world : create_map
** File description:
** create the world map
*/

#include "my_world.h"

cam_t set_cam(void)
{
	cam_t cam;

	cam.angle.x = 45 * M_PI / 180;
	cam.angle.y = 35 * M_PI / 180;
	cam.scale.x = 64;
	cam.scale.y = 64;
	cam.scale.z = 10;
	return (cam);
}

sfVector2f **change_2d_map(int **map3d, sfVector2f **map2d, cam_t *cam)
{
	sfVector2i cnt;

	for (cnt.y = 0; cnt.y < MAP_Y; cnt.y++) {
		for (cnt.x = 0; cnt.x < MAP_X; cnt.x++)
			map2d[cnt.y][cnt.x] = \
project_iso_point(cnt.x * cam->scale.x, cnt.y * cam->scale.y, \
map3d[cnt.y][cnt.x] * cam->scale.z, cam);
	}
	return (map2d);
}

sfVector2f **create_2d_map(int **map3d)
{
	sfVector2f **map2d = NULL;
	sfVector2i cnt = {0, 0};
	cam_t cam = set_cam();

	map2d = (sfVector2f **) malloc(sizeof(sfVector2f *) * (MAP_Y + 1));
	if (map2d == NULL)
		return (NULL);
	map2d[MAP_Y] = NULL;
	for (cnt.y = 0; cnt.y < MAP_Y; cnt.y++) {
		map2d[cnt.y] = (sfVector2f *) malloc(sizeof(sfVector2f) * \
(MAP_X + 1));
		if (map2d[cnt.y] == NULL)
			return (NULL);
	}
	map2d = change_2d_map(map3d, map2d, &cam);
	return (map2d);
}
