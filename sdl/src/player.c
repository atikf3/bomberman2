#include "../lib/lib.h"

void move_player(map_t *map, sdl_helper_t *wd_handler, entity_t *player, char dir)
{
    SDL_Rect rect;
    rect.x = player->pos.x;
    rect.y = player->pos.y;
    rect.w = BASICPIX;
    rect.h = BASICPIX;
    SDL_RenderFillRect(wd_handler->bg, &rect);
    switch (dir)
    {
    case 'z':
        player->pos.y -= 32;
        break;
    case 's':
        player->pos.y += 32;
        break;
    case 'q':
        player->pos.x -= 32;
        break;
    case 'd':
        player->pos.x += 32;
        break;
    
    default:
        break;
    }
    SDL_RenderCopy(wd_handler->bg, player->texture,NULL, &player->pos);
    SDL_RenderPresent(wd_handler->bg);
}

void place_bomb(map_t *map, sdl_helper_t *wd_handler, entity_t *player)
{
    entity_t *bomb = malloc(sizeof(entity_t));
    create_texture(init_bomb_image(wd_handler),wd_handler, bomb);
    init_position(bomb->texture, wd_handler, bomb);
    designer(bomb, player->pos.x, player->pos.y, wd_handler);
    SDL_RenderCopy(wd_handler->bg, bomb->texture,NULL, &player->pos);
    SDL_RenderPresent(wd_handler->bg);
}