#include "config.h"
#include "noise.h"
#include "world.h"
#include <stdlib.h>

static BlockType Unknown;
static BlockType Air;
static BlockType Grass;
static BlockType Sand;
static BlockType Slab;
static BlockType Brick;
static BlockType Wood;
static BlockType Stone;
static BlockType Dirt;
static BlockType Plank;
static BlockType Snow;
static BlockType Glass;
static BlockType Cobblestone;
static BlockType LightSlab;
static BlockType DarkSlab;
static BlockType WoodBox;
static BlockType Leaf;
static BlockType Cloud;
static BlockType TallGrass;
static BlockType Flower1;
static BlockType Flower2;
static BlockType Flower3;
static BlockType Flower4;
static BlockType Flower5;
static BlockType Flower6;
static BlockType Flower7;
static BlockType *block_types;
static int block_count;

void init_blocks() {
    block_types = calloc(25, sizeof(BlockType));
    block_count = -1;

// w = id, h = hardness, b = breakable, p = placeable, t = transparent, y = type
//  block_types[block_count ++] = Block       = (BlockType){ w,   h, b, p, t, y                   };
    block_types[block_count ++] = Unknown     = (BlockType){-1, 0.0, 0, 0, 1, BlockRenderTypeNone };
    block_types[block_count ++] = Air         = (BlockType){ 0, 0.0, 0, 0, 1, BlockRenderTypeNone };
    block_types[block_count ++] = Grass       = (BlockType){ 1, 0.5, 1, 1, 0, BlockRenderTypeBlock};
    block_types[block_count ++] = Sand        = (BlockType){ 2, 0.5, 1, 1, 0, BlockRenderTypeBlock};
    block_types[block_count ++] = Slab        = (BlockType){ 3, 2.0, 1, 1, 0, BlockRenderTypeBlock};
    block_types[block_count ++] = Brick       = (BlockType){ 4, 3.0, 1, 1, 0, BlockRenderTypeBlock};
    block_types[block_count ++] = Wood        = (BlockType){ 5, 1.5, 1, 1, 0, BlockRenderTypeBlock};
    block_types[block_count ++] = Stone       = (BlockType){ 6, 3.0, 1, 1, 0, BlockRenderTypeBlock};
    block_types[block_count ++] = Dirt        = (BlockType){ 7, 0.5, 1, 1, 0, BlockRenderTypeBlock};
    block_types[block_count ++] = Plank       = (BlockType){ 8, 1.0, 1, 1, 0, BlockRenderTypeBlock};
    block_types[block_count ++] = Snow        = (BlockType){ 9, 0.5, 1, 1, 0, BlockRenderTypeBlock};
    block_types[block_count ++] = Glass       = (BlockType){10, 0.5, 1, 1, 1, BlockRenderTypeBlock};
    block_types[block_count ++] = Cobblestone = (BlockType){11, 3.5, 1, 1, 0, BlockRenderTypeBlock};
    block_types[block_count ++] = LightSlab   = (BlockType){12, 3.5, 1, 1, 0, BlockRenderTypeBlock};
    block_types[block_count ++] = DarkSlab    = (BlockType){13, 3.5, 1, 1, 0, BlockRenderTypeBlock};
    block_types[block_count ++] = WoodBox     = (BlockType){14, 1.5, 1, 1, 0, BlockRenderTypeBlock};
    block_types[block_count ++] = Leaf        = (BlockType){15, 0.5, 1, 1, 1, BlockRenderTypeBlock};
    block_types[block_count ++] = Cloud       = (BlockType){16, 0.0, 0, 0, 0, BlockRenderTypeBlock};
    block_types[block_count ++] = TallGrass   = (BlockType){17, 0.0, 1, 1, 1, BlockRenderTypePlant};
    block_types[block_count ++] = Flower1     = (BlockType){18, 0.0, 1, 1, 1, BlockRenderTypePlant};
    block_types[block_count ++] = Flower2     = (BlockType){19, 0.0, 1, 1, 1, BlockRenderTypePlant};
    block_types[block_count ++] = Flower3     = (BlockType){20, 0.0, 1, 1, 1, BlockRenderTypePlant};
    block_types[block_count ++] = Flower4     = (BlockType){21, 0.0, 1, 1, 1, BlockRenderTypePlant};
    block_types[block_count ++] = Flower5     = (BlockType){22, 0.0, 1, 1, 1, BlockRenderTypePlant};
    block_types[block_count ++] = Flower6     = (BlockType){23, 0.0, 1, 1, 1, BlockRenderTypePlant};
    block_types[block_count ++] = Flower7     = (BlockType){24, 0.0, 1, 1, 1, BlockRenderTypePlant};
}

BlockType get_block(int id) {
    return block_types[id];
}

int block_breakable(int id) {
    return get_block(id).breakable;
}

int block_placeable(int id) {
    return get_block(id).placable;
}

int block_transparent(int id) {
    return get_block(id).transparent;
}

int block_type(int id) {
    return get_block(id).type;
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
