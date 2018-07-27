/*
** EPITECH PROJECT, 2018
** my_world : create_line
** File description:
** create a line
*/

#include "my_world.h"

sfVertexArray *create_line(sfVector2f point1, sfVector2f point2)
{
	sfVertexArray *vertex_array = sfVertexArray_create();
	sfVertex vertex1 = {.position = point1, .color = sfBlack};
	sfVertex vertex2 = {.position = point2, .color = sfBlack};

	if (vertex_array == NULL)
		return (NULL);
	sfVertexArray_append(vertex_array, vertex1);
	sfVertexArray_append(vertex_array, vertex2);
	sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);
	return (vertex_array);
}
