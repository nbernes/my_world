/*
** EPITECH PROJECT, 2018
** my_world : create_object
** File description:
** create object and init sprite / txt
*/

#include "my_world.h"

object_t *create_object(char *path, sfIntRect rect, sfVector2f move)
{
	object_t *button = malloc(sizeof(object_t));

	button->sprite = sfSprite_create();
	if (!button->sprite)
		return (NULL);
	sfSprite_move(button->sprite, move);
	button->texture = sfTexture_createFromFile(path, NULL);
	if (!button->texture)
		return (NULL);
	sfSprite_setTexture(button->sprite, button->texture, sfTrue);
	button->rect = rect;
	sfSprite_setTextureRect(button->sprite, button->rect);
	return (button);
}
