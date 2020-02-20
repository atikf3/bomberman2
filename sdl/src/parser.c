#include "../lib/lib.h"

void parser(char *path, map_t *map) {
    FILE *fp;
    char str[MAXCHAR];
    char* filename = path;
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s\n",filename);
        exit(1);
    }
    map->line = (int)ct_line(fp);
    if (map->line == -1) {
        printf("Map corrupted, column mismatch.\n");
        exit (1);
    }  
    map->tab = malloc(sizeof(char *) * map->line);
    rewind(fp);
    while (fgets(str, MAXCHAR, fp) != NULL) {
        map->col = (int)strlen(str);
        map->tab[i] = malloc(sizeof(char) * (map->col));
        for(int j = 0; j < (int)strlen(str); j++) {
            map->tab[i][j] = str[j];
        }
        i++;
    }
    fclose(fp);
}

int ct_line(FILE *fp)
{
    int lines = 0;
    int prev, cur;
    prev = cur = 0;
    char ch;
    char prevline[MAXCHAR];
    while(!feof(fp)) {
        ch = fgetc(fp);
        cur++;
        if(ch == '\n') {
            if (lines > 0 && prev != cur)
                return -1;
            prev = cur;
            cur = 0;
            lines++;
        }
    }
    return lines;
}

void dump_map(map_t *map)
{
    for(int i = 0; i < map->line; i++)
        for(int j = 0; j < map->col; j++)
            printf("%c",map->tab[i][j]);
}
void destroyer_map(map_t *map)
{
    for(int i = 0; i < map->line; i++)
        free(map->tab[i]);
    free(map->tab);
}