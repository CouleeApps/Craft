#ifndef _world_h_
#define _world_h_

#include "map.h"

//Grass,
//Sand,
//Slab,
//Brick,
//Wood,
//Stone,
//Dirt,
//Plank,
//Snow,
//Glass,
//Cobblestone,
//
//Head = 14,
//Leaf,
//Cloud,
//TallGrass,
//Flower1,
//Flower2,
//Flower3,
//Flower4,
//Flower5,
//Flower6,
//Flower7

typedef enum {
    ItemRenderTypeNone,
    ItemRenderTypeBlock,
    ItemRenderTypePlant,
    ItemRenderTypeItem,
} ItemRenderType;

typedef enum {
    ItemMaterialTypeNone,
    ItemMaterialTypeSoil,
    ItemMaterialTypeStone,
    ItemMaterialTypeWood,
    ItemMaterialTypePlant,
} ItemMaterialType;

typedef struct {
    int id;
    int drops;
    int drop_count;
    float break_duration;
    int breakable;
    int placable;
    int transparent;
    int solid;
    int max_quantity;
    ItemMaterialType material;
    ItemMaterialType *affects;
    double *affections;
    int affection_count;
    ItemRenderType type;
} ItemType;

void init_items();
ItemType get_item(int id);
int item_drop(int id);
int item_drop_count(int id);
int item_breakable(int id);
int item_placeable(int id);
int item_transparent(int id);
int item_type(int id);
int item_solid(int id);
int item_max_quantity(int id);
double item_affection(int item_id, ItemMaterialType material);
double item_affection_id(int item_id, int affected_id);

void create_world(Map *map, int p, int q);

#endif
