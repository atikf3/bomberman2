#ifndef _LIB_H
#define _LIB_H

#include <stdio.h>
#include <SDL2/SDL.h>
#define MAXCHAR 1024
#define BASICPIX 32

typedef struct sdl_helper_s {
    SDL_Window *wd;
    SDL_Renderer *bg;
    int height;
    int width;
    int err;
} sdl_helper_t;

typedef struct map_s {
    char **tab;
    int line;
    int col;
} map_t;

typedef struct entity_s {
    SDL_Texture *texture;
    SDL_Rect pos;
} entity_t;

//TODO structure to stock map information , real map, int line, int col

int init_wd(map_t *map);
int init_renderer(sdl_helper_t *wd_handler, map_t *map);
int destroyer(char *str, sdl_helper_t *wd_handler, int st);
void parser(char *path, map_t *map);
void dump_map(map_t *map);
void destroyer_map(map_t *map);
int ct_line(FILE *fp);
entity_t *init_map(sdl_helper_t *wd_handler, map_t *map);
SDL_Surface *init_image(char *path, sdl_helper_t *wd_handler);
SDL_Surface *init_wall_image(sdl_helper_t *wd_handler);
SDL_Surface *init_wood_image(sdl_helper_t *wd_handler);
SDL_Surface *init_perso_image(sdl_helper_t *wd_handler);
void create_texture(SDL_Surface *surface, sdl_helper_t *wd_handler, entity_t *entity);
SDL_Rect init_position(SDL_Texture *texture, sdl_helper_t *wd_handler, entity_t *entity);
void lauch_game(map_t *map, sdl_helper_t *wd_helper, entity_t *player);
void save(map_t *map);
void place_bomb(map_t *map, sdl_helper_t *wd_handler, entity_t *player);
SDL_Surface *init_bomb_image(sdl_helper_t *wd_handler);
void move_player(map_t *map, sdl_helper_t *wd_handler, entity_t *player, char dir);
void designer(entity_t *entity, int x, int y, sdl_helper_t *wd_handler);

#endif