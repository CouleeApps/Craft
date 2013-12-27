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
    map->data = (MapEntry *)calloc(map->mask + 1, sizeof(MapEntry));
}

void map_free(Map *map) {
    free(map->data);
}

void map_set(Map *map, int x, int y, int z, int w, int b) {
    unsigned int index = hash(x, y, z) & map->mask;
    MapEntry *entry = map->data + index;
    int overwrite = 0;
    while (!EMPTY_ENTRY(entry)) {
        if (entry->x == x && entry->y == y && entry->z == z) {
            overwrite = 1;
            break;
        }
        index = (index + 1) & map->mask;
        entry = map->data + index;
    }
    if (overwrite) {
        entry->w = w;
        entry->b = b;
    }
    else if (w) {
        entry->x = x;
        entry->y = y;
        entry->z = z;
        entry->w = w;
        entry->b = b;
        map->size++;
        if (map->size * 2 > map->mask) {
            map_grow(map);
        }
    }
}

int map_get(Map *map, int x, int y, int z) {
    unsigned int index = hash(x, y, z) & map->mask;
    MapEntry *entry = map->data + index;
    while (!EMPTY_ENTRY(entry)) {
        if (entry->x == x && entry->y == y && entry->z == z) {
            return entry->w;
        }
        index = (index + 1) & map->mask;
        entry = map->data + index;
    }

    return 0;
}

int entry_compare(Entry entry1, Entry entry2) {
    return entry1.x == entry2.x && entry1.y == entry2.y && entry1.z == entry2.z;
}

Entry map_get_entry(Map *map, int x, int y, int z) {
    unsigned int index = hash(x, y, z) & map->mask;
    Entry *entry = map->data + index;
    while (!EMPTY_ENTRY(entry)) {
        if (entry->x == x && entry->y == y && entry->z == z) {
            return *entry;
        }
        index = (index + 1) & map->mask;
        entry = map->data + index;
    }

    Entry ret;
    ret.x = 0;
    ret.y = 0;
    ret.z = 0;
    ret.w = 0;
    ret.b = 0;
    return ret;
}

void map_grow(Map *map) {
    Map new_map;
    new_map.mask = (map->mask << 1) | 1;
    new_map.size = 0;
    new_map.data = (MapEntry *)calloc(new_map.mask + 1, sizeof(MapEntry));
    MAP_FOR_EACH(map, entry) {
        map_set(&new_map, entry->x, entry->y, entry->z, entry->w, entry->b);
    } END_MAP_FOR_EACH;
    free(map->data);
    map->mask = new_map.mask;
    map->size = new_map.size;
    map->data = new_map.data;
}
