#include "config.h"
#include "noise.h"
#include "world.h"
#include <stdlib.h>

#define define_block(store, d, c, h, b, p, t, s, q, m, y) \
    { item_types[item_count] = store = (ItemType){item_count, d, c, h, b, p, t, s, q, m, NULL, NULL, 0, y}; item_count ++; }
#define define_item(store, h, b, p, t, s, q, m, ac, y) \
    {\
    	item_types[item_count] = store = (ItemType){item_count, 0, 0, h, b, p, t, s, q, m, NULL, NULL, ac, y}; \
        item_types[item_count].affects = calloc(ac, sizeof(ItemMaterialType)); \
        item_types[item_count].affections = calloc(ac, sizeof(double)); \
        item_count ++; \
    }
#define define_item_null() \
    { item_types[item_count] = (ItemType){item_count, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, 0, 0}; item_count ++; }

/* BLOCKS */
static ItemType Unknown;
static ItemType Air;
static ItemType Grass;
static ItemType Sand;
static ItemType Slab;
static ItemType Brick;
static ItemType Wood;
static ItemType Stone;
static ItemType Dirt;
static ItemType Plank;
static ItemType Snow;
static ItemType Glass;
static ItemType Cobblestone;
static ItemType LightSlab;
static ItemType DarkSlab;
static ItemType WoodBox;
static ItemType Leaf;
static ItemType Cloud;
static ItemType TallGrass;
static ItemType Flower1;
static ItemType Flower2;
static ItemType Flower3;
static ItemType Flower4;
static ItemType Flower5;
static ItemType Flower6;
static ItemType Flower7;
/* ITEMS */
static ItemType Pickaxe;
static ItemType Shovel;
static ItemType Axe;
static ItemType Sword;

static ItemType *item_types;
static int item_count;

void init_items() {
    item_types = calloc(1024, sizeof(ItemType));
    item_count = -1;

//  h = hardness, b = breakable, p = placeable, t = transparent, s = solid, q = max quantity, y = type
//  define_item(Block,         h, b, p, t, s,  q, y                 );
    /* -1 */ define_block(Unknown,     item_count, 0, 0.0, 0, 0, 1, 0,  0, ItemMaterialTypeNone,  ItemRenderTypeNone);
    /*  0 */ define_block(Air,         item_count, 0, 0.0, 0, 0, 1, 0,  0, ItemMaterialTypeNone,  ItemRenderTypeNone);
    /*  1 */ define_block(Grass,                7, 1, 0.5, 1, 1, 0, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    /*  2 */ define_block(Sand,        item_count, 1, 0.5, 1, 1, 0, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    /*  3 */ define_block(Slab,        item_count, 1, 2.0, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    /*  4 */ define_block(Brick,       item_count, 1, 3.0, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    /*  5 */ define_block(Wood,        item_count, 1, 1.5, 1, 1, 0, 1, 64, ItemMaterialTypeWood,  ItemRenderTypeBlock);
    /*  6 */ define_block(Stone,               11, 1, 3.0, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    /*  7 */ define_block(Dirt,        item_count, 1, 0.5, 1, 1, 0, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    /*  8 */ define_block(Plank,       item_count, 1, 1.0, 1, 1, 0, 1, 64, ItemMaterialTypeWood,  ItemRenderTypeBlock);
    /*  9 */ define_block(Snow,                 7, 1, 0.5, 1, 1, 0, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    /* 10 */ define_block(Glass,                0, 0, 0.5, 1, 1, 1, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    /* 11 */ define_block(Cobblestone, item_count, 1, 3.5, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    /* 12 */ define_block(LightSlab,   item_count, 1, 3.5, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    /* 13 */ define_block(DarkSlab,    item_count, 1, 3.5, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    /* 14 */ define_block(WoodBox,              8, 1, 1.5, 1, 1, 0, 1, 64, ItemMaterialTypeWood,  ItemRenderTypeBlock);
    /* 15 */ define_block(Leaf,        item_count, 1, 0.5, 1, 1, 1, 1, 64, ItemMaterialTypePlant, ItemRenderTypeBlock);
    /* 16 */ define_block(Cloud,                0, 0, 0.0, 0, 0, 1, 0,  0, ItemMaterialTypeNone,  ItemRenderTypeBlock);
    /* 17 */ define_block(TallGrass,   item_count, 1, 0.0, 1, 1, 1, 0, 64, ItemMaterialTypePlant, ItemRenderTypePlant);
    /* 18 */ define_block(Flower1,     item_count, 1, 0.0, 1, 1, 1, 0, 64, ItemMaterialTypePlant, ItemRenderTypePlant);
    /* 19 */ define_block(Flower2,     item_count, 1, 0.0, 1, 1, 1, 0, 64, ItemMaterialTypePlant, ItemRenderTypePlant);
    /* 20 */ define_block(Flower3,     item_count, 1, 0.0, 1, 1, 1, 0, 64, ItemMaterialTypePlant, ItemRenderTypePlant);
    /* 21 */ define_block(Flower4,     item_count, 1, 0.0, 1, 1, 1, 0, 64, ItemMaterialTypePlant, ItemRenderTypePlant);
    /* 22 */ define_block(Flower5,     item_count, 1, 0.0, 1, 1, 1, 0, 64, ItemMaterialTypePlant, ItemRenderTypePlant);
    /* 23 */ define_block(Flower6,     item_count, 1, 0.0, 1, 1, 1, 0, 64, ItemMaterialTypePlant, ItemRenderTypePlant);
    /* 24 */ define_block(Flower7,     item_count, 1, 0.0, 1, 1, 1, 0, 64, ItemMaterialTypePlant, ItemRenderTypePlant);
    while (item_count < 256)
        define_item_null();
    define_item(Pickaxe,      0.0, 0, 0, 0, 0,  1, ItemMaterialTypeNone, 1, ItemRenderTypeItem);
    item_types[item_count - 1].affects[0] = ItemMaterialTypeStone;
    item_types[item_count - 1].affections[0] = 0.3333;
    define_item(Shovel,       0.0, 0, 0, 0, 0,  1, ItemMaterialTypeNone, 1, ItemRenderTypeItem);
    item_types[item_count - 1].affects[0] = ItemMaterialTypeSoil;
    item_types[item_count - 1].affections[0] = 0.3333;
    define_item(Axe,          0.0, 0, 0, 0, 0,  1, ItemMaterialTypeNone, 1, ItemRenderTypeItem);
    item_types[item_count - 1].affects[0] = ItemMaterialTypeWood;
    item_types[item_count - 1].affections[0] = 0.3333;
    define_item(Sword,        0.0, 0, 0, 0, 0,  1, ItemMaterialTypeNone, 1, ItemRenderTypeItem);
    item_types[item_count - 1].affects[0] = ItemMaterialTypePlant;
    item_types[item_count - 1].affections[0] = 0.3333;
}

ItemType get_item(int id) {
    ItemType blank;
    if (id > item_count)
        return blank;
    return item_types[id];
}

int item_breakable(int id) {
    return get_item(id).breakable;
}

int item_placeable(int id) {
    return get_item(id).placable;
}

int item_transparent(int id) {
    return get_item(id).transparent;
}

int item_type(int id) {
    return get_item(id).type;
}

int item_solid(int id) {
    return get_item(id).solid;
}

int item_max_quantity(int id) {
    return get_item(id).max_quantity;
}

int item_drop(int id) {
    return get_item(id).drops;
}

int item_drop_count(int id) {
    return get_item(id).drop_count;
}

int item_affects_index(int id, ItemMaterialType material) {
    ItemType item = get_item(id);
    for (int type = 0; type < item.affection_count; type ++) {
        if (item.affects[type] == material)
            return type;
    }
    return -1;
}

double item_affection(int item_id, ItemMaterialType material) {
    int index;
    if ((index = item_affects_index(item_id, material)) != -1)
        return get_item(item_id).affections[index];
    return 1.0;
}

double item_affection_id(int item_id, int affected_id) {
    return item_affection(item_id, get_item(affected_id).material);
}

void create_world(Map *map, int p, int q) {
    int pad = 1;
    for (int dx = -pad; dx < CHUNK_SIZE + pad; dx++) {
        for (int dz = -pad; dz < CHUNK_SIZE + pad; dz++) {
            int x = p * CHUNK_SIZE + dx;
            int z = q * CHUNK_SIZE + dz;
            float f = simplex2(x * 0.01, z * 0.01, 4, 0.5, 2);
            float g = simplex2(-x * 0.01, -z * 0.01, 2, 0.9, 2);
            int mh = g * 32 + 16;
            int h = f * mh;
            int w = Grass.id;
            int t = 12;
            int l = 4;
            if (h <= t) {
                h = t;
                w = Sand.id;
            }
            if (dx < 0 || dz < 0 || dx >= CHUNK_SIZE || dz >= CHUNK_SIZE) {
                w = -1;
            }
            // sand and grass terrain
            for (int y = 0; y < h; y++) {
                if (y > h - l) {
                    if (w == Grass.id && y != h - 1)
                        map_set(map, x, y, z, Dirt.id, 0);
                    else {
                        map_set(map, x, y, z, w, 0);
                        if (w == Grass.id && map_get(map, x, y - 1, z) == Grass.id)
                            map_set(map, x, y - 1, z, Dirt.id, 0);
                    }
                } else
                    map_set(map, x, y, z, Stone.id, 0);
            }
            // TODO: w = -1 if outside of chunk
            if (w == Grass.id) {
                // grass
                if (simplex2(-x * 0.1, z * 0.1, 4, 0.8, 2) > 0.6) {
                    map_set(map, x, h, z, Grass.id, 0);
                }
                // flowers
                if (simplex2(x * 0.05, -z * 0.05, 4, 0.8, 2) > 0.7) {
                    int w = Flower1.id + simplex2(x * 0.1, z * 0.1, 4, 0.8, 2) * 7;
                    map_set(map, x, h, z, w, 0);
                }
                // trees
                int ok = 1;
                if (dx - 4 < 0 || dz - 4 < 0 ||
                    dx + 4 >= CHUNK_SIZE || dz + 4 >= CHUNK_SIZE)
                {
                    ok = 0;
                }
                if (ok && simplex2(x, z, 6, 0.5, 2) > 0.84) {
                    for (int y = h + 3; y < h + 8; y++) {
                        for (int ox = -3; ox <= 3; ox++) {
                            for (int oz = -3; oz <= 3; oz++) {
                                int d = (ox * ox) + (oz * oz) +
                                    (y - (h + 4)) * (y - (h + 4));
                                if (d < 11) {
                                    map_set(map, x + ox, y, z + oz, Leaf.id, 0);
                                }
                            }
                        }
                    }
                    for (int y = h; y < h + 7; y++) {
                        map_set(map, x, y, z, Wood.id, 0);
                    }
                }
            }
            // clouds
            for (int y = 64; y < 72; y++) {
                if (simplex3(x * 0.01, y * 0.1, z * 0.01, 8, 0.5, 2) > 0.75) {
                    map_set(map, x, y, z, Cloud.id, 0);
                }
                if (simplex3(-x * 0.01, -y * 0.1, -z * 0.01, 8, 0.5, 2) > 0.75) {
                    map_set(map, x, y + 20, z, Cloud.id, 0);
                }
            }
        }
    }
}
