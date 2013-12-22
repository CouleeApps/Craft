#include <stdio.h>
#include <stdlib.h>
#include "item.h"

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

static ItemType *item_types;
static int item_count;

void init_items() {
    item_types = calloc(1024, sizeof(ItemType));
    item_count = -1;

    //  h = hardness, b = breakable, p = placeable, t = transparent, s = solid, q = max quantity, y = type
    //  define_item(Block,         h, b, p, t, s,  q, y                 );
    /* -1 */ define_block(Unknown,     item_count, 0, 0.0, 0, 0, 1, 0,  0, ItemMaterialTypeNone,  ItemRenderTypeNone);
    /*  0 */ define_block(Air,         item_count, 0, 0.0, 0, 0, 1, 0,  0, ItemMaterialTypeNone,  ItemRenderTypeNone);
    /*  1 */ define_block(Grass,                7, 1, 0.6, 1, 1, 0, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    /*  2 */ define_block(Sand,        item_count, 1, 0.3, 1, 1, 0, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    /*  3 */ define_block(Slab,        item_count, 1, 2.5, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    /*  4 */ define_block(Brick,       item_count, 1, 3.5, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    /*  5 */ define_block(Wood,        item_count, 1, 1.5, 1, 1, 0, 1, 64, ItemMaterialTypeWood,  ItemRenderTypeBlock);
    /*  6 */ define_block(Stone,               11, 1, 3.0, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    /*  7 */ define_block(Dirt,        item_count, 1, 0.5, 1, 1, 0, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    /*  8 */ define_block(Plank,       item_count, 1, 1.0, 1, 1, 0, 1, 64, ItemMaterialTypeWood,  ItemRenderTypeBlock);
    /*  9 */ define_block(Snow,                 7, 1, 0.6, 1, 1, 0, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    /* 10 */ define_block(Glass,                0, 0, 0.7, 1, 1, 1, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    /* 11 */ define_block(Cobblestone, item_count, 1, 4.0, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    /* 12 */ define_block(LightSlab,   item_count, 1, 3.5, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    /* 13 */ define_block(DarkSlab,    item_count, 1, 3.5, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    /* 14 */ define_block(WoodBox,              8, 1, 2.0, 1, 1, 0, 1, 64, ItemMaterialTypeWood,  ItemRenderTypeBlock);
    /* 15 */ define_block(Leaf,        item_count, 1, 0.2, 1, 1, 1, 1, 64, ItemMaterialTypePlant, ItemRenderTypeBlock);
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