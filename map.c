#include <stdlib.h>
#include "map.h"

int hash_int(int key) {
    key = ~key + (key << 15);
    key = key ^ (key >> 12);
    key = key + (key << 2);
    key = key ^ (key >> 4);
    key = key * 2057;
    key = key ^ (key >> 16);
    return key;
}

int hash(int x, int y, int z) {
    x = hash_int(x);
    y = hash_int(y);
    z = hash_int(z);
    return x ^ y ^ z;
}

void map_alloc(Map *map) {
    map->mask = 0xfff;
    map->size = 0;
    map->data = (Entry *)calloc(map->mask + 1, sizeof(Entry));
    map->orig = (Entry *)calloc(map->mask + 1, sizeof(Entry));
}

void map_free(Map *map) {
    free(map->data);
    free(map->orig);
}

void map_set(Map *map, int x, int y, int z, int w, int o) {
    if (w == -1 && o == 0)
        w = map_get_orig(map, x, y, z);

    unsigned int index = hash(x, y, z) & map->mask;
    Entry *entry = map->data + index;
    Entry *orig  = map->orig + index;
    int overwrite = 0;
    while (!EMPTY_ENTRY(entry)) {
        if (entry->x == x && entry->y == y && entry->z == z) {
            overwrite = 1;
            break;
        }
        index = (index + 1) & map->mask;
        entry = map->data + index;
        orig  = map->orig + index;
    }
    if (overwrite) {
        entry->w = w;
    }
    else if (w) {
        entry->x = x;
        entry->y = y;
        entry->z = z;
        entry->w = w;
        orig->x = x;
        orig->y = y;
        orig->z = z;
        if (o)
            orig->w = w;
        else
            orig->w = 0;
        map->size++;
        if (map->size * 2 > map->mask) {
            map_grow(map);
        }
    }
}

int map_get(Map *map, int x, int y, int z) {
    unsigned int index = hash(x, y, z) & map->mask;
    Entry *entry = map->data + index;
    while (!EMPTY_ENTRY(entry)) {
        if (entry->x == x && entry->y == y && entry->z == z) {
            return entry->w;
        }
        index = (index + 1) & map->mask;
        entry = map->data + index;
    }
    return 0;
}

int map_get_orig(Map *map, int x, int y, int z) {
    unsigned int index = hash(x, y, z) & map->mask;
    Entry *entry = map->orig + index;
    while (!EMPTY_ENTRY(entry)) {
        if (entry->x == x && entry->y == y && entry->z == z) {
            return entry->w;
        }
        index = (index + 1) & map->mask;
        entry = map->orig + index;
    }
    return 0;
}

void map_grow(Map *map) {
    Map new_map;
    new_map.mask = (map->mask << 1) | 1;
    new_map.size = 0;
    new_map.data = (Entry *)calloc(new_map.mask + 1, sizeof(Entry));
    new_map.orig = (Entry *)calloc(new_map.mask + 1, sizeof(Entry));
    MAP_FOR_EACH(map, entry) {
        map_set(&new_map, entry->x, entry->y, entry->z, entry->w, 1);
    } END_MAP_FOR_EACH;
    free(map->data);
    map->mask = new_map.mask;
    map->orig = new_map.orig;
    map->size = new_map.size;
    map->data = new_map.data;
}
