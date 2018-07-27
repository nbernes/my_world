/*
** EPITECH PROJECT, 2017
** my_world
** File description:
** include : my_world
*/

#ifndef __MY_H__
#define __MY_H__
#define MAP_X 10
#define MAP_Y 10
#define SCALING_X 64
#define SCALING_Y 64
#define SCALING_Z 10
#define CENTER_X 960
#define CENTER_Y(y) (540 - (y) * MAP_Y / 2)
#define CHECK_ERROR(x) if (x == NULL) return (84);

#include <SFML/Graphics.h>
#include <SFML/Window/Export.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <stddef.h>

struct object {
	sfSprite *sprite;
	sfTexture *texture;
	sfIntRect rect;
};

typedef struct object object_t;

struct buttons {
	object_t *left;
	object_t *mid;
	object_t *right;
};

typedef struct buttons buttons_t;

struct limits {
	float x_min;
	float y_min;
	float x_max;
	float y_max;
};

typedef struct limits limits_t;

struct tile {
	sfVector2f c1;
	sfVector2f c2;
	sfVector2f c3;
	sfVector2f c4;
	sfVector2f last_pos;
	sfVector2i pos;
};

typedef struct tile tile_t;

struct frame {
	sfClock *clock;
	sfTime time;
	float seconds;
};

typedef struct frame frame_t;

struct camera {
	sfVector2f angle;
	sfVector3f scale;
};

typedef struct camera cam_t;

struct maps {
	sfRenderWindow *window;
	int **map3d;
	sfVector2f **map2d;
	int fx;
};

typedef struct maps maps_t;

float evaluate_coord(float cmp, float value, int relationship);
sfRenderWindow *highlight_tiles(sfRenderWindow *window, sfVector2f **map2d, \
sfVector2i *cnt);
sfRenderWindow *set_pink_hue(sfRenderWindow *window, tile_t *tile);
sfRenderWindow *display_info_button(sfRenderWindow *window);
char *show_info(void);
int my_strlen(const char *str);
sfText *create_text(sfText *txt, const char *str);
sfRenderWindow *display_help(sfRenderWindow *window, int flag);
int identify_x_coord(int x);
int select_help_txtbox(sfEvent *evt, int flag);
sfRenderWindow *set_tiles(maps_t *maps, sfVector2i *cnt);
sfRenderWindow *set_each_tile(maps_t *maps, tile_t *tile);
buttons_t *create_buttons(sfIntRect rect);
void event_closed(maps_t *maps, sfEvent *event);
void check_mouse_pos(maps_t *maps, sfEvent *event, buttons_t *buttons);
void check_mouse_hover(sfEvent *event, buttons_t *buttons);
void check_mouse_clic(maps_t *maps, sfEvent *event, buttons_t *buttons);
int first_last_buttons(maps_t *maps, sfEvent *event, buttons_t *buttons);
int mid_button(maps_t *maps, sfEvent *event, buttons_t *buttons);
object_t *create_object(char *path, sfIntRect rect, sfVector2f move);
int **set_rand(int **map3d);
int **set_zeros(int **map3d);
maps_t *reinit_map(maps_t *maps, cam_t *cam);
void find_limits(limits_t *lim, sfVector2f pnt);
sfVector2f modif_point(sfVector2f pnt, int diff);
maps_t *retrieve_height_values(maps_t *maps, cam_t *cam, sfVector2i pos);
maps_t *change_tile_height(sfEvent *event, maps_t *maps, cam_t *cam);
sfVector2f **calc_tile_nuheight(sfVector2f **map2d, tile_t *tile, int mouse);
tile_t get_tile_pos(sfVector2f **map, sfVector2f mouse);
int check_each_tile(tile_t *cmp, sfVector2f mouse);
tile_t reload_cmp_struct(sfVector2f pt1, sfVector2f pt2, sfVector2f pt3, \
sfVector2f pt4);
sfVector2f **create_2d_map(int **map3d);
sfVector2f **change_2d_map(int **map3d, sfVector2f **map2d, cam_t *cam);
cam_t set_cam(void);
sfVector2f project_iso_point(int x, int y, int z, cam_t *cam);
sfVector2f **apply_zoom(sfVector2f **map2d, int **map3d, int value,
cam_t *cam);
maps_t *change_height(sfEvent *event, maps_t *maps, cam_t *cam);
sfRenderWindow *create_vertex_array(sfRenderWindow *window, sfVector2f\
**map_2d, sfVector2i *cnt, int opt);
sfRenderWindow *draw_vertex_arrays(sfRenderWindow *window, \
sfVector2f **map_2d, sfVector2i *cnt);
sfRenderWindow *display_each_row(maps_t *maps, sfVector2i *cnt, int flag);
maps_t *trigger_events(maps_t *maps, buttons_t *buttons);
int draw_2d_map(maps_t *maps);
int frame_loop(maps_t *maps, buttons_t *buttons, frame_t *frame);
maps_t *trigger_zoom(sfEvent *event, maps_t *maps, cam_t *cam);
maps_t *key_pressed(sfEvent *event, maps_t *maps, cam_t *cam);
int assign_map3d(maps_t *maps, sfVector2i *cnt);
sfRenderWindow *assign_window(void);
int assign_map(void);
maps_t *quit(sfEvent *event, sfRenderWindow *window);
sfRenderWindow *outline_selected_pt(sfRenderWindow *window, sfVector2f center);
sfRenderWindow *outline_corners(sfRenderWindow *window, sfVector2f **map2d);
sfRenderWindow *set_all_circles(sfRenderWindow *window, sfVector2f center);
int retrieve_z_value(sfVector2f point_2d, sfVector2i cnt, cam_t *cam);
void unset_objects(maps_t *maps, sfRenderWindow *window);
sfVertexArray *create_line(sfVector2f point1, sfVector2f point2);
sfVector2f increase_corner_height(sfEvent *event, sfVector2f point);
int check_each_pos(sfEvent *event, sfVector2f point);
sfVector2i get_corner_position(sfEvent *event, maps_t *maps);
void unset_corner(maps_t *maps, sfVector2i pos, cam_t *cam);
void modif_corner(sfEvent *event, maps_t *maps, sfVector2i pos);

#endif
