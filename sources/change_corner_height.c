/*
** EPITECH PROJECT, 2018
** change_corner_height.c
** File description:
** ...
*/

#include "my_world.h"

sfVector2f increase_corner_height(sfEvent *event, sfVector2f point)
{
	point.y = event->mouseMove.y;
	return (point);
}

int check_each_pos(sfEvent *event, sfVector2f point)
{
	if (event->mouseButton.x < point.x + 5 &&
		event->mouseButton.x > point.x - 5 &&
		event->mouseButton.y < point.y + 5 &&
		event->mouseButton.y > point.y - 5)
		return (1);
	else
		return (0);
}

sfVector2i get_corner_position(sfEvent *event, maps_t *maps)
{
	int check = 0;
	sfVector2i cnt;

	for (cnt.y = 0; cnt.y < MAP_Y && check == 0; cnt.y++) {
		for (cnt.x = 0; cnt.x < MAP_X && check == 0; cnt.x++)
			check = check_each_pos(event, \
maps->map2d[cnt.y][cnt.x]);
	}
	cnt.y--;
	cnt.x--;
	return (cnt);
}

void unset_corner(maps_t *maps, sfVector2i pos, cam_t *cam)
{
	maps->map3d[pos.y][pos.x] = \
retrieve_z_value(maps->map2d[pos.y][pos.x], pos, cam);
	pos.x = -1;
	pos.y = -1;
	maps->fx = 1;
}

void modif_corner(sfEvent *event, maps_t *maps, sfVector2i pos)
{
	sfVector2f center;

	maps->map2d[pos.y][pos.x] = increase_corner_height(event, \
maps->map2d[pos.y][pos.x]);
	center = maps->map2d[pos.y][pos.x];
	center = increase_corner_height(event, center);
	maps->window = outline_selected_pt(maps->window, center);
}
