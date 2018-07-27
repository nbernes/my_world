/*
** EPITECH PROJECT, 2018
** retrieve_height_value
** File description:
** ...
*/

#include "my_world.h"

int retrieve_z_value(sfVector2f point_2d, sfVector2i cnt, cam_t *cam)
{
	int z;

	cnt.y *= cam->scale.y;
	cnt.x *= cam->scale.x;
	z = CENTER_Y(cam->scale.y) + sin(cam->angle.y) * cnt.y + \
sin(cam->angle.y) * cnt.x - point_2d.y;
	z /= cam->scale.z;
	return (z);
}

maps_t *retrieve_height_values(maps_t *maps, cam_t *cam, sfVector2i pos)
{
	maps->map3d[pos.y][pos.x] = \
retrieve_z_value(maps->map2d[pos.y][pos.x], pos, cam);
	pos.y++;
	maps->map3d[pos.y][pos.x] = \
retrieve_z_value(maps->map2d[pos.y][pos.x], pos, cam);
	pos.x++;
	maps->map3d[pos.y][pos.x] = \
retrieve_z_value(maps->map2d[pos.y][pos.x], pos, cam);
	pos.y--;
	maps->map3d[pos.y][pos.x] = \
retrieve_z_value(maps->map2d[pos.y][pos.x], pos, cam);
	return (maps);
}
