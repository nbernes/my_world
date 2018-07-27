/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** ...
*/

#include "my_world.h"

int my_strlen(const char *str)
{
	int i = 0;

	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}
