#include <stdio.h>
#include <stdlib.h>
#include "item.h"

#define define_block(d, c, h, b, p, t, s, q, m, y) \
{ item_types[item_count] = (ItemType){item_count, d, c, h, b, p, t, s, q, m, NULL, NULL, 0, y}; item_count ++; }
#define define_item(h, b, p, t, s, q, m, ac, y) \
{\
item_types[item_count] = (ItemType){item_count, 0, 0, h, b, p, t, s, q, m, NULL, NULL, ac, y}; \
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

    //  d = drop, dc = drop count, h = hardness, b = breakable, p = placeable, t = transparent, s = solid, q = max quantity, m = material, y = type
    //  		 define_block(         d,dc,   h, b, p, t, s,  q, m,                     y                 );
    /* -1 */ define_block(item_count, 0, 0.0, 0, 0, 1, 0,  0, ItemMaterialTypeNone,  ItemRenderTypeNone);
    /*  0 */ define_block(item_count, 0, 0.0, 0, 0, 1, 0,  0, ItemMaterialTypeNone,  ItemRenderTypeNone);
    /*  1 */ define_block(         7, 1, 0.6, 1, 1, 0, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    /*  2 */ define_block(item_count, 1, 0.3, 1, 1, 0, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    /*  3 */ define_block(item_count, 1, 2.5, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    /*  4 */ define_block(item_count, 1, 3.5, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    /*  5 */ define_block(item_count, 1, 1.5, 1, 1, 0, 1, 64, ItemMaterialTypeWood,  ItemRenderTypeBlock);
    /*  6 */ define_block(        11, 1, 3.0, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    /*  7 */ define_block(item_count, 1, 0.5, 1, 1, 0, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    /*  8 */ define_block(item_count, 1, 1.0, 1, 1, 0, 1, 64, ItemMaterialTypeWood,  ItemRenderTypeBlock);
    /*  9 */ define_block(         7, 1, 0.6, 1, 1, 0, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    /* 10 */ define_block(         0, 0, 0.7, 1, 1, 1, 1, 64, ItemMaterialTypeSoil,  ItemRenderTypeBlock);
    /* 11 */ define_block(item_count, 1, 4.0, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    /* 12 */ define_block(item_count, 1, 3.5, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    /* 13 */ define_block(item_count, 1, 3.5, 1, 1, 0, 1, 64, ItemMaterialTypeStone, ItemRenderTypeBlock);
    /* 14 */ define_block(         8, 1, 2.0, 1, 1, 0, 1, 64, ItemMaterialTypeWood,  ItemRenderTypeBlock);
    /* 15 */ define_block(item_count, 1, 0.2, 1, 1, 1, 1, 64, ItemMaterialTypePlant, ItemRenderTypeBlock);
    /* 16 */ define_block(         0, 0, 0.0, 0, 0, 1, 0,  0, ItemMaterialTypeNone,  ItemRenderTypeBlock);
    /* 17 */ define_block(item_count, 1, 0.0, 1, 1, 1, 0, 64, ItemMaterialTypePlant, ItemRenderTypePlant);
    /* 18 */ define_block(item_count, 1, 0.0, 1, 1, 1, 0, 64, ItemMaterialTypePlant, ItemRenderTypePlant);
    /* 19 */ define_block(item_count, 1, 0.0, 1, 1, 1, 0, 64, ItemMaterialTypePlant, ItemRenderTypePlant);
    /* 20 */ define_block(item_count, 1, 0.0, 1, 1, 1, 0, 64, ItemMaterialTypePlant, ItemRenderTypePlant);
    /* 21 */ define_block(item_count, 1, 0.0, 1, 1, 1, 0, 64, ItemMaterialTypePlant, ItemRenderTypePlant);
    /* 22 */ define_block(item_count, 1, 0.0, 1, 1, 1, 0, 64, ItemMaterialTypePlant, ItemRenderTypePlant);
    /* 23 */ define_block(item_count, 1, 0.0, 1, 1, 1, 0, 64, ItemMaterialTypePlant, ItemRenderTypePlant);
    /* 24 */ define_block(item_count, 1, 0.0, 1, 1, 1, 0, 64, ItemMaterialTypePlant, ItemRenderTypePlant);
    while (item_count < 256)
        define_item_null();
    define_item(0.0, 0, 0, 0, 0,  1, ItemMaterialTypeNone, 1, ItemRenderTypeItem);
    item_types[item_count - 1].affects[0] = ItemMaterialTypeStone;
    item_types[item_count - 1].affections[0] = 0.3333;
    define_item(0.0, 0, 0, 0, 0,  1, ItemMaterialTypeNone, 1, ItemRenderTypeItem);
    item_types[item_count - 1].affects[0] = ItemMaterialTypeSoil;
    item_types[item_count - 1].affections[0] = 0.3333;
    define_item(0.0, 0, 0, 0, 0,  1, ItemMaterialTypeNone, 1, ItemRenderTypeItem);
    item_types[item_count - 1].affects[0] = ItemMaterialTypeWood;
    item_types[item_count - 1].affections[0] = 0.3333;
    define_item(0.0, 0, 0, 0, 0,  1, ItemMaterialTypeNone, 1, ItemRenderTypeItem);
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

int is_placeable(int w) {
    return item_placeable(w);
}