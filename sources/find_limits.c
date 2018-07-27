/*
** EPITECH PROJECT, 2018
** find_limits
** File description:
** search the limits
*/

#include "my_world.h"

float evaluate_coord(float cmp, float value, int relationship)
{
	if (relationship == 1) {
		if (cmp > value)
			cmp = value;
	} else if (relationship == -1) {
		if (cmp < value)
			cmp = value;
	}
	return (cmp);
}

void find_limits(limits_t *lim, sfVector2f pnt)
{
	lim->x_min = evaluate_coord(lim->x_min, pnt.x, 1);
	lim->y_min = evaluate_coord(lim->y_min, pnt.y, 1);
	lim->x_max = evaluate_coord(lim->x_max, pnt.x, -1);
	lim->y_max = evaluate_coord(lim->y_max, pnt.y, -1);
}
