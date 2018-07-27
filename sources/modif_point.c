/*
** EPITECH PROJECT, 2018
** my_world: modif_point 
** File description:
** modif point
*/

#include "my_world.h"

sfVector2f modif_point(sfVector2f pnt, int diff)
{
	pnt.y += diff;
	return (pnt);
}
