/*
** EPITECH PROJECT, 2018
** highlight_tiles.c
** File description:
** ...
*/

#include "my_world.h"

sfRenderWindow *set_pink_hue(sfRenderWindow *window, tile_t *tile)
{
	sfConvexShape *shape = sfConvexShape_create();
	int value = 0;

	if (shape == NULL)
		return (NULL);
	sfConvexShape_setPointCount(shape, 4);
	sfConvexShape_setPoint(shape, value, tile->c1);
	sfConvexShape_setPoint(shape, ++value, tile->c2);
	sfConvexShape_setPoint(shape, ++value, tile->c3);
	sfConvexShape_setPoint(shape, ++value, tile->c4);
	sfConvexShape_setFillColor(shape, \
sfColor_fromRGBA(235, 92, 216, 100));
	sfConvexShape_setOutlineColor(shape, sfBlack);
	value = 2;
	sfConvexShape_setOutlineThickness(shape, value);
	sfRenderWindow_drawConvexShape(window, shape, NULL);
	sfConvexShape_destroy(shape);
	return (window);
}

sfRenderWindow *highlight_tiles(sfRenderWindow *window, sfVector2f **map2d, \
sfVector2i *cnt)
{
	tile_t tile;

	if (cnt->y < MAP_Y - 1 && cnt->x < MAP_X - 1) {
		tile.c1 = map2d[cnt->y][cnt->x];
		tile.c4 = map2d[cnt->y][cnt->x + 1];
		tile.c2 = map2d[cnt->y + 1][cnt->x];
		tile.c3 = map2d[cnt->y + 1][cnt->x + 1];
		window = set_pink_hue(window, &tile);
	}
	return (window);
}
