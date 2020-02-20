#include "../lib/lib.h"

entity_t *init_map(sdl_helper_t *wd_handler, map_t *map)
{
    entity_t *wall = malloc(sizeof(entity_t));
    entity_t *wood = malloc(sizeof(entity_t));
    entity_t *player = malloc(sizeof(entity_t));
    
    create_texture(init_wall_image(wd_handler),wd_handler, wall);
    create_texture(init_wood_image(wd_handler),wd_handler, wood);
    create_texture(init_perso_image(wd_handler),wd_handler, player);
    
    init_position(wall->texture, wd_handler, wall);
    init_position(wood->texture, wd_handler, wood);
    init_position(player->texture, wd_handler, player);
    
    for(int i = 0;i < map->line; i++) {
        for(int j = 0; j < map->col; j++) {
            if(map->tab[i][j] == 'O') { //tableau de lookup
                designer(wall, j, i, wd_handler);
            } else if(map->tab[i][j] == 'X') {
                designer(wood, j, i, wd_handler);
            } else if(map->tab[i][j] == 'P') {
                designer(player, j, i, wd_handler);
            }
        }
    }
    SDL_RenderPresent(wd_handler->bg);
    return player;
}
int init_renderer(sdl_helper_t *wd_handler, map_t *map)
{
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = 32 * map->col;
    rect.h = 32 * map->line;
    if(SDL_SetRenderDrawColor(wd_handler->bg, 98, 168, 50, 100) != 0)
        destroyer("Error setting color render\n", wd_handler, 1);
    if(SDL_RenderFillRect(wd_handler->bg,&rect) != 0)
        destroyer("Error setting color render\n", wd_handler, 1);
    SDL_RenderPresent(wd_handler->bg);
    return wd_handler->bg == NULL ? 1 : 0;
}
SDL_Surface *init_image(char *path, sdl_helper_t *wd_handler)
{
    //if path does not maych
    SDL_Surface *image = NULL;
    image = SDL_LoadBMP(path);
    if(image == NULL)
        destroyer("Error loading wall bmp\n", wd_handler, 1);
    return image;
}
SDL_Surface *init_wall_image(sdl_helper_t *wd_handler)
{
    return init_image("./res/wall.bmp",wd_handler);
}
SDL_Surface *init_bomb_image(sdl_helper_t *wd_handler)
{
    return init_image("./res/bomb.bmp",wd_handler);
}
SDL_Surface *init_wood_image(sdl_helper_t *wd_handler)
{
    return init_image("./res/wood.bmp",wd_handler);
}
SDL_Surface *init_perso_image(sdl_helper_t *wd_handler)
{
    return init_image("./res/captainA.bmp",wd_handler);
}
void create_texture(SDL_Surface *surface, sdl_helper_t *wd_handler, entity_t *entity)
{
    entity->texture = SDL_CreateTextureFromSurface(wd_handler->bg, surface);
    SDL_FreeSurface(surface);
    if(entity->texture == NULL)
        destroyer("Error loading wall texture surface\n", wd_handler, 1);
    SDL_Rect texture_pos;
    if(SDL_QueryTexture(entity->texture, NULL, NULL, &texture_pos.w, &texture_pos.h) != 0)
        destroyer("Error loading wall rect\n", wd_handler, 1);
}

SDL_Rect init_position(SDL_Texture *texture, sdl_helper_t *wd_handler, entity_t *entity)
{
    if(SDL_QueryTexture(texture, NULL, NULL, &entity->pos.w, &entity->pos.h) != 0)
        destroyer("Error loading wood texture\n", wd_handler, 1);
    return entity->pos;
}

void designer(entity_t *entity, int x, int y, sdl_helper_t *wd_handler)
{
    entity->pos.x = x * BASICPIX;
    entity->pos.y = y * BASICPIX;
    if(SDL_RenderCopy(wd_handler->bg, entity->texture, NULL, &entity->pos) != 0)
        destroyer("Error render copy entity z\n", wd_handler, 1);
}