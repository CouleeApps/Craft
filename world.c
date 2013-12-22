#include "config.h"
#include "noise.h"
#include "world.h"
#include <stdlib.h>

#define define_block(store, h, b, p, t, s, q, m, y) \
    { item_types[item_count] = store = (ItemType){item_count, h, b, p, t, s, q, m, NULL, NULL, 0, y}; item_count ++; }
#define define_item(store, h, b, p, t, s, q, m, ac, y) \
    {\
    	item_types[item_count] = store = (ItemType){item_count, h, b, p, t, s, q, m, NULL, NULL, ac, y}; \
        item_types[item_count].affects = calloc(ac, sizeof(ItemMaterialType)); \
        item_types[item_count].affections = calloc(ac, sizeof(double)); \
        item_count ++; \
    }
#define define_item_null() \
    { item_types[item_count] = (ItemType){item_count, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, 0, 0}; item_count ++; }

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

static ItemType *item_types;
static int item_count;

void init_items() {
    item_types = calloc(1024, sizeof(ItemType));
    item_count = -1;

//  h = hardness, b = breakable, p = placeable, t = transparent, s = solid, q = max quantity, y = type
//  define_item(Block,         h, b, p, t, s,  q, y                 );
    define_block(Unknown,     0.0, 0, 0, 1, 0,  0, ItemMaterialTypeNone,  ItemRenderTypeNone);
    define_block(Air,         0.0, 0, 0, 1, 0,  0, ItemMaterialTypeNone,  ItemRenderTypeNone);
    define_block(Grass,       0.5, 1, 1, 0, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    define_block(Sand,        0.5, 1, 1, 0, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    define_block(Slab,        2.0, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    define_block(Brick,       3.0, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    define_block(Wood,        1.5, 1, 1, 0, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    define_block(Stone,       3.0, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    define_block(Dirt,        0.5, 1, 1, 0, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    define_block(Plank,       1.0, 1, 1, 0, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    define_block(Snow,        0.5, 1, 1, 0, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    define_block(Glass,       0.5, 1, 1, 1, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    define_block(Cobblestone, 3.5, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    define_block(LightSlab,   3.5, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    define_block(DarkSlab,    3.5, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    define_block(WoodBox,     1.5, 1, 1, 0, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    define_block(Leaf,        0.5, 1, 1, 1, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    define_block(Cloud,       0.0, 0, 0, 1, 0,  0, ItemMaterialTypeNone,  ItemRenderTypeBlock);
    define_block(TallGrass,   0.0, 1, 1, 1, 0, 64, ItemMaterialTypeNone,  ItemRenderTypePlant);
    define_block(Flower1,     0.0, 1, 1, 1, 0, 64, ItemMaterialTypeNone,  ItemRenderTypePlant);
    define_block(Flower2,     0.0, 1, 1, 1, 0, 64, ItemMaterialTypeNone,  ItemRenderTypePlant);
    define_block(Flower3,     0.0, 1, 1, 1, 0, 64, ItemMaterialTypeNone,  ItemRenderTypePlant);
    define_block(Flower4,     0.0, 1, 1, 1, 0, 64, ItemMaterialTypeNone,  ItemRenderTypePlant);
    define_block(Flower5,     0.0, 1, 1, 1, 0, 64, ItemMaterialTypeNone,  ItemRenderTypePlant);
    define_block(Flower6,     0.0, 1, 1, 1, 0, 64, ItemMaterialTypeNone,  ItemRenderTypePlant);
    define_block(Flower7,     0.0, 1, 1, 1, 0, 64, ItemMaterialTypeNone,  ItemRenderTypePlant);
    while (item_count < 256)
        define_item_null();
    define_item(Pickaxe,      0.0, 0, 0, 0, 0,  1, ItemMaterialTypeNone, 1, ItemRenderTypeItem);
    item_types[item_count - 1].affects[0] = ItemMaterialTypeStone;
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
