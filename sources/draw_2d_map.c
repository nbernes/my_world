/*
** EPITECH PROJECT, 2018
** draw_2d_map
** File description:
** ...
*/

#include "my_world.h"

sfRenderWindow *create_vertex_array(sfRenderWindow *window, \
sfVector2f **map_2d, sfVector2i *cnt, int opt)
{
	sfVertexArray *vertex_array = NULL;

	if (opt == 1)
		vertex_array = create_line(map_2d[cnt->y][cnt->x], \
map_2d[cnt->y + 1][cnt->x]);
	else if (opt == 2)
		vertex_array = create_line(map_2d[cnt->y][cnt->x], \
map_2d[cnt->y][cnt->x + 1]);
	else
		vertex_array = create_line(map_2d[cnt->y][cnt->x], \
map_2d[cnt->y][cnt->x + 1]);
	if (vertex_array == NULL)
		return (NULL);
	sfRenderWindow_drawVertexArray(window, vertex_array, NULL);
	sfVertexArray_destroy(vertex_array);
	return (window);
}

sfRenderWindow *draw_vertex_arrays(sfRenderWindow *window, \
sfVector2f **map_2d, sfVector2i *cnt)
{
	if (cnt->y < MAP_Y - 1) {
		window = create_vertex_array(window, map_2d, cnt, 1);
		if (cnt->x < MAP_X - 1)
			window = create_vertex_array(window, map_2d, cnt, 2);
	} else if (cnt->y == MAP_Y - 1) {
		if (cnt->x < MAP_X - 1)
			window = create_vertex_array(window, map_2d, cnt, 3);
	}
	return (window);
}

sfRenderWindow *display_each_row(maps_t *maps, sfVector2i *cnt, int flag)
{
	for (cnt->x = 0; cnt->x < MAP_X; cnt->x++) {
		maps->window = set_tiles(maps, cnt);
		maps->window = draw_vertex_arrays(maps->window, maps->map2d, \
cnt);
		switch (flag) {
		case 1: maps->window = set_all_circles(maps->window, \
maps->map2d[cnt->y][cnt->x]);
			break;
		case 2: maps->window = highlight_tiles(maps->window, \
maps->map2d, cnt);
			break;
		}
	}
	return (maps->window);
}

maps_t *trigger_events(maps_t *maps, buttons_t *buttons)
{
	static cam_t cam = {{45 * M_PI / 180, 35 * M_PI / 180}, {64, 64, 10}};
	sfEvent event;
	static int flag = 0;

	while (sfRenderWindow_pollEvent(maps->window, &event)) {
		event_closed(maps, &event);
		if (event.type == sfEvtMouseMoved || event.type == \
sfEvtMouseButtonPressed) {
			check_mouse_pos(maps, &event, buttons);
			check_mouse_hover(&event, buttons);
			check_mouse_clic(maps, &event, buttons);
		}
		maps = key_pressed(&event, maps, &cam);
		maps = change_height(&event, maps, &cam);
		maps = change_tile_height(&event, maps, &cam);
		maps = reinit_map(maps, &cam);
		flag = select_help_txtbox(&event, flag);
	}
	maps->window = display_help(maps->window, flag);
	return (maps);
}

int draw_2d_map(maps_t *maps)
{
	frame_t frame;
	sfIntRect rect = {0, 0, 300, 100};
	buttons_t *buttons = create_buttons(rect);

	frame.clock = sfClock_create();
	if (frame.clock == NULL || buttons == NULL)
		return (84);
	while (sfRenderWindow_isOpen(maps->window))
		if (frame_loop(maps, buttons, &frame) == 84)
			return (84);
	unset_objects(maps, maps->window);
	sfRenderWindow_destroy(maps->window);
	return (0);
}
