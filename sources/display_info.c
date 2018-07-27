/*
** EPITECH PROJECT, 2018
** display_info_button.c
** File description:
** ...
*/

#include "my_world.h"

sfRenderWindow *display_info_button(sfRenderWindow *window)
{
	sfIntRect rect = {0, 0, 50, 50};
	sfVector2f pos = {1800, 50};
	object_t *info = create_object("pictures/info_icon.png", rect, pos);

	sfRenderWindow_drawSprite(window, info->sprite, NULL);
	sfSprite_destroy(info->sprite);
	free(info);
	return (window);
}

char *show_info(void)
{
	char *info = "Use the arrow keys Up and Down to zoom in and out of" \
" the map.\n\nClick, drag and drop the selectable (pink) " \
"elements to change\ntheir height.\n";

	return (info);
}
