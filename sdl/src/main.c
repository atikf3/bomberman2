#include "../lib/lib.h"

int main(int argc, char **argv) {
    map_t *map;
    map = malloc(sizeof(map_t));
    parser(argv[1], map);
    init_wd(map);
    dump_map(map);
    destroyer_map(map);
    return (argc);
}