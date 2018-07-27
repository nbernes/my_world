/*
** EPITECH PROJECT, 2018
** my_world : outline_corners
** File description:
** deal with the outline_corners
*/

#include "my_world.h"

sfRenderWindow *set_all_circles(sfRenderWindow *window, sfVector2f center)
{
	sfColor pink = sfColor_fromRGB(235, 92, 216);
	sfCircleShape *circle = sfCircleShape_create();

	if (circle == NULL)
		return (NULL);
	center.x -= 5;
	center.y -= 5;
	sfCircleShape_setPosition(circle, center);
	sfCircleShape_setRadius(circle, 5);
	sfCircleShape_setFillColor(circle, pink);
	sfRenderWindow_drawCircleShape(window, circle, NULL);
	return (window);
}

sfRenderWindow *outline_selected_pt(sfRenderWindow *window, sfVector2f center)
{
	sfCircleShape *circle = sfCircleShape_create();
	sfColor pink = sfColor_fromRGB(235, 92, 216);

	center.x -= 10;
	center.y -= 10;
	sfCircleShape_setPosition(circle, center);
	sfCircleShape_setRadius(circle, 10);
	sfCircleShape_setFillColor(circle, sfTransparent);
	sfCircleShape_setOutlineColor(circle, pink);
	sfCircleShape_setOutlineThickness(circle, 1);
	sfRenderWindow_drawCircleShape(window, circle, NULL);
	return (window);
}
