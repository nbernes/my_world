/*
** EPITECH PROJECT, 2018
** set_tiles.c
** File description:
** ...
*/

#include "my_world.h"

sfRenderWindow *set_each_tile(maps_t *maps, tile_t *tile)
{
	sfConvexShape *shape = sfConvexShape_create();
	sfTexture *text = sfTexture_createFromFile("pictures/ground.png", \
NULL);

	if (!shape || !text)
		return (NULL);
	sfConvexShape_setPointCount(shape, 4);
	sfConvexShape_setPoint(shape, 0, tile->c1);
	sfConvexShape_setPoint(shape, 1, tile->c2);
	sfConvexShape_setPoint(shape, 2, tile->c3);
	sfConvexShape_setPoint(shape, 3, tile->c4);
	sfConvexShape_setTexture(shape, text, sfTrue);
	sfRenderWindow_drawConvexShape(maps->window, shape, NULL);
	sfConvexShape_destroy(shape);
	sfTexture_destroy(text);
	return (maps->window);
}

sfRenderWindow *set_tiles(maps_t *maps, sfVector2i *cnt)
{
	tile_t tile;

	if (cnt->y < MAP_Y - 1 && cnt->x < MAP_X - 1) {
		tile.c1 = maps->map2d[cnt->y][cnt->x];
		tile.c4 = maps->map2d[cnt->y][cnt->x + 1];
		tile.c2 = maps->map2d[cnt->y + 1][cnt->x];
		tile.c3 = maps->map2d[cnt->y + 1][cnt->x + 1];
		maps->window = set_each_tile(maps, &tile);
	}
	return (maps->window);
}
