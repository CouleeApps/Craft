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
    BlockRenderTypeNone,
    BlockRenderTypeBlock,
    BlockRenderTypePlant
} BlockRenderType;

typedef struct {
    int id;
    float break_duration;
    int breakable;
    int placable;
    int transparent;
    BlockRenderType type;
} BlockType;

void init_blocks();
BlockType get_block(int id);
int block_breakable(int id);
int block_placeable(int id);
int block_transparent(int id);
int block_type(int id);

void create_world(Map *map, int p, int q);

#endif
