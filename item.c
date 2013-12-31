#include <stdio.h>
#include <stdlib.h>
#include "item.h"

#define define_block(d, c, h, b, p, t, s, q, m, y) \
{ item_types[item_count] = (ItemType){item_count, d, c, h, b, p, t, s, q, m, NULL, NULL, 0, y}; item_count ++; }
#define define_item(q, ac) \
{\
item_types[item_count] = (ItemType){item_count, 0, 0, 0.0, 0, 0, 0, 0, q, ItemMaterialTypeNone, NULL, NULL, ac, ItemRenderTypeItem}; \
item_types[item_count].affects = calloc(ac, sizeof(ItemMaterialType)); \
item_types[item_count].affections = calloc(ac, sizeof(double)); \
item_count ++; \
}
#define define_item_null() \
{ item_types[item_count] = (ItemType){item_count, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, 0, 0}; item_count ++; }

static ItemType *item_types;
int item_count;

void init_items() {
    item_types = calloc(1024, sizeof(ItemType));
    item_count = -1;

    //  d = drop, dc = drop count, h = hardness, b = breakable, p = placeable, t = transparent, s = solid, q = max quantity, m = material, y = type
    //  		     define_block(         d,dc,   h, b, p, t, s,  q, m,                     y                 );
    /* -1 Unknown */ define_block(item_count, 0, 0.0, 0, 0, 1, 0,  0, ItemMaterialTypeNone,  ItemRenderTypeNone);
    /*  0 Air     */ define_block(item_count, 0, 0.0, 0, 0, 1, 0,  0, ItemMaterialTypeNone,  ItemRenderTypeNone);
    /*  1 Grass   */ define_block(         7, 1, 0.6, 1, 1, 0, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    /*  2 Sand    */ define_block(item_count, 1, 0.3, 1, 1, 0, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    /*  3 Stone   */ define_block(item_count, 1, 2.5, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    /*  4 Brick   */ define_block(item_count, 1, 3.5, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    /*  5 Log     */ define_block(item_count, 1, 1.5, 1, 1, 0, 1, 64, ItemMaterialTypeWood,  ItemRenderTypeBlock);
    /*  6 Cement  */ define_block(        11, 1, 3.0, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    /*  7 Dirt    */ define_block(item_count, 1, 0.5, 1, 1, 0, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    /*  8 Plank   */ define_block(item_count, 1, 1.0, 1, 1, 0, 1, 64, ItemMaterialTypeWood,  ItemRenderTypeBlock);
    /*  9 Snow    */ define_block(         7, 1, 0.6, 1, 1, 0, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    /* 10 Glass   */ define_block(         0, 0, 0.7, 1, 1, 1, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    /* 11 Cobble  */ define_block(item_count, 1, 4.0, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    /* 12 Lstone  */ define_block(item_count, 1, 3.5, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    /* 13 Dstone  */ define_block(item_count, 1, 3.5, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    /* 14 Chest   */ define_block(         8, 1, 2.0, 1, 1, 0, 1, 64, ItemMaterialTypeWood,  ItemRenderTypeBlock);
    /* 15 Leaf    */ define_block(item_count, 1, 0.2, 1, 1, 1, 1, 64, ItemMaterialTypePlant, ItemRenderTypeBlock);
    /* 16 Cloud   */ define_block(         0, 0, 0.0, 0, 0, 1, 0,  0, ItemMaterialTypeNone,  ItemRenderTypeBlock);
    /* 17 TGrass  */ define_block(item_count, 1, 0.0, 1, 1, 1, 0, 64, ItemMaterialTypePlant, ItemRenderTypePlant);
    /* 18 YFlower */ define_block(item_count, 1, 0.0, 1, 1, 1, 0, 64, ItemMaterialTypePlant, ItemRenderTypePlant);
    /* 19 RFlower */ define_block(item_count, 1, 0.0, 1, 1, 1, 0, 64, ItemMaterialTypePlant, ItemRenderTypePlant);
    /* 20 PFlower */ define_block(item_count, 1, 0.0, 1, 1, 1, 0, 64, ItemMaterialTypePlant, ItemRenderTypePlant);
    /* 21 SFlower */ define_block(item_count, 1, 0.0, 1, 1, 1, 0, 64, ItemMaterialTypePlant, ItemRenderTypePlant);
    /* 22 WFlower */ define_block(item_count, 1, 0.0, 1, 1, 1, 0, 64, ItemMaterialTypePlant, ItemRenderTypePlant);
    /* 23 BFlower */ define_block(item_count, 1, 0.0, 1, 1, 1, 0, 64, ItemMaterialTypePlant, ItemRenderTypePlant);
    /* 24 RWool   */ define_block(item_count, 1, 1.0, 1, 1, 0, 1, 64, ItemMaterialTypePlant, ItemRenderTypeBlock);
    /* 25 GWool   */ define_block(item_count, 1, 1.0, 1, 1, 0, 1, 64, ItemMaterialTypePlant, ItemRenderTypeBlock);
    /* 26 BWool   */ define_block(item_count, 1, 1.0, 1, 1, 0, 1, 64, ItemMaterialTypePlant, ItemRenderTypeBlock);
    /* 27 OWool   */ define_block(item_count, 1, 1.0, 1, 1, 0, 1, 64, ItemMaterialTypePlant, ItemRenderTypeBlock);
    /* 28 PWool   */ define_block(item_count, 1, 1.0, 1, 1, 0, 1, 64, ItemMaterialTypePlant, ItemRenderTypeBlock);
    /* 29 BWool   */ define_block(item_count, 1, 1.0, 1, 1, 0, 1, 64, ItemMaterialTypePlant, ItemRenderTypeBlock);
    /* 30 Furnace */ define_block(item_count, 1, 3.0, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    /* 31 WBench  */ define_block(item_count, 1, 2.5, 1, 1, 0, 1, 64, ItemMaterialTypeWood,  ItemRenderTypeBlock);
    while (item_count < 256)
        define_item_null();

    // q = max quantity, ac = affection count
    //                define_item( q,ac);
    /* 256 Pickaxe */ define_item( 1, 1);
    item_types[item_count - 1].affects[0] = ItemMaterialTypeStone;
    item_types[item_count - 1].affections[0] = 0.3333;
    /* 257 Shovel  */ define_item( 1, 1);
    item_types[item_count - 1].affects[0] = ItemMaterialTypeSoil;
    item_types[item_count - 1].affections[0] = 0.3333;
    /* 258 Axe     */ define_item( 1, 1);
    item_types[item_count - 1].affects[0] = ItemMaterialTypeWood;
    item_types[item_count - 1].affections[0] = 0.3333;
    /* 259 Sword   */ define_item( 1, 1);
    item_types[item_count - 1].affects[0] = ItemMaterialTypePlant;
    item_types[item_count - 1].affections[0] = 0.3333;
    /* 260 Stick   */ define_item(64, 0);
}

ItemType get_item(int id) {
    if (id > item_count || id < 0)
        return (ItemType){0};
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

int is_plant(int w) {
    return item_type(w) == ItemRenderTypePlant;
}

int is_item(int w) {
    return item_type(w) == ItemRenderTypeItem;
}

int is_obstacle(int w) {
    return item_solid(w);
}

int is_transparent(int w) {
    return item_transparent(w);
}

int is_destructable(int w) {
    return item_breakable(w);
}

int is_selectable(int w) {
    return item_placeable(w);
}

int is_placeable(int w) {
    return item_placeable(w);
}

#include "item.h"
#include "util.h"

const int items[] = {
    // items the user can build
    GRASS,
    SAND,
    STONE,
    BRICK,
    WOOD,
    CEMENT,
    DIRT,
    PLANK,
    SNOW,
    GLASS,
    COBBLE,
    LIGHT_STONE,
    DARK_STONE,
    CHEST,
    LEAVES,
    TALL_GRASS,
    YELLOW_FLOWER,
    RED_FLOWER,
    PURPLE_FLOWER,
    SUN_FLOWER,
    WHITE_FLOWER,
    BLUE_FLOWER,
    // RED_WOOL,
    // GREEN_WOOL,
    // BLUE_WOOL,
    // ORANGE_WOOL,
    // PURPLE_WOOL,
    // BEIGE_WOOL
};

const int blocks[256][6] = {
    // w => (left, right, top, bottom, front, back) tiles
    {0, 0, 0, 0, 0, 0}, // 0 - empty
    {16, 16, 32, 0, 16, 16}, // 1 - grass
    {1, 1, 1, 1, 1, 1}, // 2 - sand
    {2, 2, 2, 2, 2, 2}, // 3 - stone
    {3, 3, 3, 3, 3, 3}, // 4 - brick
    {20, 20, 36, 4, 20, 20}, // 5 - wood
    {5, 5, 5, 5, 5, 5}, // 6 - cement
    {6, 6, 6, 6, 6, 6}, // 7 - dirt
    {7, 7, 7, 7, 7, 7}, // 8 - plank
    {24, 24, 40, 8, 24, 24}, // 9 - snow
    {9, 9, 9, 9, 9, 9}, // 10 - glass
    {10, 10, 10, 10, 10, 10}, // 11 - cobble
    {11, 11, 11, 11, 11, 11}, // 12 - light stone
    {12, 12, 12, 12, 12, 12}, // 13 - dark stone
    {13, 13, 13, 13, 13, 13}, // 14 - chest
    {14, 14, 14, 14, 14, 14}, // 15 - leaves
    {15, 15, 15, 15, 15, 15}, // 16 - cloud
    {0, 0, 0, 0, 0, 0}, // 17
    {0, 0, 0, 0, 0, 0}, // 18
    {0, 0, 0, 0, 0, 0}, // 19
    {0, 0, 0, 0, 0, 0}, // 20
    {0, 0, 0, 0, 0, 0}, // 21
    {0, 0, 0, 0, 0, 0}, // 22
    {0, 0, 0, 0, 0, 0}, // 23
    {17, 17, 17, 17, 17, 17}, // 24 - red wool
    {18, 18, 18, 18, 18, 18}, // 25 - green wool
    {19, 19, 19, 19, 19, 19}, // 26 - blue wool
    {33, 33, 33, 33, 33, 33}, // 27 - orange wool
    {34, 34, 34, 34, 34, 34}, // 28 - purple wool
    {35, 35, 35, 35, 35, 35}, // 29 - beige wool
    {0, 0, 0, 0, 0, 0}, // 30
    {0, 0, 0, 0, 0, 0}, // 31
};

const int plants[256] = {
    // w => tile
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 0 - 16
    48, // 17 - tall grass
    49, // 18 - yellow flower
    50, // 19 - red flower
    51, // 20 - purple flower
    52, // 21 - sun flower
    53, // 22 - white flower
    54, // 23 - blue flower
};
