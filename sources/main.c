/*
** EPITECH PROJECT, 2018
** my_world : main
** File description:
** main program
*/

#include "my_world.h"

int assign_map3d(maps_t *maps, sfVector2i *cnt)
{
	maps->map3d = (int **)malloc(sizeof(int *) * MAP_Y);
	CHECK_ERROR(maps->map3d);
	for (cnt->y = 0; cnt->y < MAP_Y; cnt->y++) {
		maps->map3d[cnt->y] = (int *)malloc(sizeof(int) * MAP_X);
		CHECK_ERROR(maps->map3d[cnt->y]);
	}
	for (cnt->y = 0; cnt->y < MAP_Y; cnt->y ++)
		for (cnt->x = 0; cnt->x < MAP_X; cnt->x++)
			maps->map3d[cnt->y][cnt->x] = 0;
	return (0);
}

sfRenderWindow *assign_window(void)
{
	sfVideoMode mode;
	sfRenderWindow *window;

	mode.width = 1920;
	mode.height = 1080;
	mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(mode, "M Y    W O R L D.", \
sfResize | sfClose, NULL);
	return (window);
}

int assign_map(void)
{
	maps_t maps;
	sfVector2i cnt;

	maps.fx = 1;
	maps.window = assign_window();
	assign_map3d(&maps, &cnt);
	maps.map2d = create_2d_map(maps.map3d);
	if (maps.window == NULL || maps.map2d == NULL)
		return (84);
	if (draw_2d_map(&maps) == 84)
		return (84);
	return (0);
}

int main(void)
{
	if (assign_map() == 84)
		return (84);
	return (0);
}
