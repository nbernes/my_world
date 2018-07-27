/*
** EPITECH PROJECT, 2018
** my_world : change_tile_height
** File description:
** change the height of tiles
*/

#include "my_world.h"

tile_t reload_cmp_struct(sfVector2f pt1, sfVector2f pt2, sfVector2f pt3, \
sfVector2f pt4)
{
	tile_t cmp;

	cmp.c1 = pt1;
	cmp.c2 = pt2;
	cmp.c3 = pt3;
	cmp.c4 = pt4;
	return (cmp);
}

int check_each_tile(tile_t *cmp, sfVector2f mouse)
{
	limits_t lim = {0, 0, 0, 0};

	lim.x_min = mouse.x;
	lim.x_max = mouse.x;
	lim.y_min = mouse.y;
	lim.y_max = mouse.y;
	find_limits(&lim, cmp->c2);
	find_limits(&lim, cmp->c3);
	find_limits(&lim, cmp->c4);
	if (mouse.x > lim.x_min && mouse.x < lim.x_max &&\
mouse.y > lim.y_min && mouse.y < lim.y_max)
		return (0);
	else
		return (1);
}

tile_t get_tile_pos(sfVector2f **map, sfVector2f mouse)
{
	sfVector2i i = {0, 0};
	tile_t cmp;

	cmp.pos.x = 1;
	cmp.last_pos = mouse;
	for (i.y = 0; i.y < MAP_Y - 1 && cmp.pos.x != 0; i.y++) {
		for (i.x = 0; i.x < MAP_X - 1 && cmp.pos.x != 0; i.x++) {
			cmp = reload_cmp_struct(map[i.y][i.x], \
map[i.y][i.x + 1], map[i.y + 1][i.x], map[i.y + 1][i.x + 1]);
			cmp.pos.x = check_each_tile(&cmp, mouse);
		}
	}
	cmp.pos.x = i.x - 1;
	cmp.pos.y = i.y - 1;
	return (cmp);
}

sfVector2f **calc_tile_nuheight(sfVector2f **map2d, tile_t *tile, int mouse)
{
	int diff = mouse - tile->last_pos.y;

	map2d[tile->pos.y][tile->pos.x] = modif_point(tile->c1, diff);
	map2d[tile->pos.y][tile->pos.x + 1] = modif_point(tile->c2, diff);
	map2d[tile->pos.y + 1][tile->pos.x] = modif_point(tile->c3, diff);
	map2d[tile->pos.y + 1][tile->pos.x + 1] = modif_point(tile->c4, diff);
	return (map2d);
}

maps_t *change_tile_height(sfEvent *event, maps_t *maps, cam_t *cam)
{
	static tile_t tile = {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, \
{-1, -1}, {-1, -1}};

	if (event->type == sfEvtMouseButtonPressed && \
event->mouseButton.button == sfMouseLeft && maps->fx == 2) {
		tile.last_pos.x = event->mouseButton.x;
		tile.last_pos.y = event->mouseButton.y;
		tile = get_tile_pos(maps->map2d, tile.last_pos);
		maps->fx = -2;
	} else if (event->type == sfEvtMouseButtonReleased && maps->fx == -2) {
		maps->fx = 2;
		maps = retrieve_height_values(maps, cam, tile.pos);
	} else {
		if (maps->fx == -2)
			maps->map2d = calc_tile_nuheight(maps->map2d, &tile, \
event->mouseMove.y);
	}
	return (maps);
}
