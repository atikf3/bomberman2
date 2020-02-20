#include "../lib/lib.h"


void lauch_game(map_t *map, sdl_helper_t *wd_helper, entity_t *player)
{
    int loop = 1;

    while(loop == 1) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            switch (event.type)
            {
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                    case SDLK_z:
                        move_player(map, wd_helper, player, 'z');
                        break;
                    case SDLK_s:
                        move_player(map, wd_helper, player, 's');
                        break;
                    case SDLK_q:
                        move_player(map, wd_helper, player, 'q');
                        break;
                    case SDLK_d:
                        move_player(map, wd_helper, player, 'd');
                        break;
                    case SDLK_r:
                        place_bomb(map, wd_helper, player);
                        break;
                    
                    default:
                        break;
                    }
                    break;
                case SDL_QUIT:
                    loop = 0;
                    break;
                
                default:
                    break;
            }
        }
    }
}