/*
** EPITECH PROJECT, 2018
** my_world : frame
** File description:
** handle the "frame rate independant" requirement
*/

#include "my_world.h"

int display(maps_t *maps, buttons_t *buttons)
{
	maps->window = display_info_button(maps->window);
	sfSprite_setTextureRect(buttons->left->sprite, buttons->left->rect);
	sfSprite_setTextureRect(buttons->mid->sprite, buttons->mid->rect);
	sfSprite_setTextureRect(buttons->right->sprite, buttons->right->rect);
	sfRenderWindow_drawSprite(maps->window, buttons->left->sprite, NULL);
	sfRenderWindow_drawSprite(maps->window, buttons->mid->sprite, NULL);
	sfRenderWindow_drawSprite(maps->window, buttons->right->sprite, NULL);
	sfRenderWindow_display(maps->window);
	sfRenderWindow_clear(maps->window, sfBlack);
	return (0);
}

int frame_loop(maps_t *maps, buttons_t *buttons, frame_t *frame)
{
	sfVector2i cnt;

	frame->time = sfClock_getElapsedTime(frame->clock);
	frame->seconds = frame->time.microseconds / 10000;
	if (frame->seconds > 1.0) {
		for (cnt.y = 0; cnt.y < MAP_Y; cnt.y++)
			maps->window = \
display_each_row(maps, &cnt, maps->fx);
		if (maps->window == NULL)
			return (84);
		maps = trigger_events(maps, buttons);
		display(maps, buttons);
		sfClock_restart(frame->clock);
	}
	return (0);
}
