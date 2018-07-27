/*
** EPITECH PROJECT, 2018
** project_iso_point
** File description:
** ...
*/

#include "my_world.h"

sfVector2f project_iso_point(int x, int y, int z, cam_t *cam)
{
	sfVector2f point;

	point.x = CENTER_X + (cos(cam->angle.x) * x - cos(cam->angle.x) * y);
	point.y = CENTER_Y(cam->scale.y) + (sin(cam->angle.y) * y + \
sin(cam->angle.y) * x - z);
	return (point);
}
