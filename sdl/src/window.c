#include "../lib/lib.h"

int init_wd(map_t *map) {
    sdl_helper_t *wd_handler = malloc(sizeof(sdl_helper_t));
    SDL_Init(SDL_INIT_VIDEO);
    if (SDL_CreateWindowAndRenderer((map->col - 1) * BASICPIX,
                                    map->line * BASICPIX,
                                    0, 
                                    &wd_handler->wd,
                                    &wd_handler->bg) != 0)
        return destroyer("creation window and renderer failed, did you specified the right $DISPLAY variable or started your x server?", wd_handler, 1);

    init_renderer(wd_handler,map);
    lauch_game(map, wd_handler, init_map(wd_handler, map));
    // SDL_Delay(5000); // pause 5s
    save(map);
    destroyer("FIN DU PROGRAMME", wd_handler, 0);
    return 0;
}

    /*
    *  @func    destroyer(char *str, sdl_helper_t *wd_handler, int st) 
    *  @params  str: the message to pass, wd_hanlder: the sdl struct, st: the status, 0 normal, 1 err
    *  @return  
    */
int destroyer(char *str, sdl_helper_t *wd_handler, int st)
{
    printf("\nSDL: %s.\nBomberman: %s\n", str, st > 0 ? SDL_GetError() : "", str);
    if(SDL_RenderClear(wd_handler->bg) != 0) {
        printf("Bomberman SDL fail:\nFailed to erase renderer, cleaning manually...\n");
        SDL_DestroyWindow(wd_handler->wd);
        SDL_Quit();
        free(wd_handler);
        return 1;
    }
    SDL_DestroyRenderer(wd_handler->bg);
    SDL_DestroyWindow(wd_handler->wd);
    free(wd_handler);
    SDL_Quit();

    return 0;
}

void save(map_t *map)
{
    FILE * file;
    file = fopen( "res/bomberman_save.txt", "w" );
    if ( file == NULL ) {
        printf("Cannot create savefile!\n");
        exit( 0 );
    }
    for(int i=0;i<map->line;i++) {
        for(int j=0;j<map->col;j++) {
            fprintf(file,"%c",map->tab[i][j]);
        }
    }
    fclose( file );
}