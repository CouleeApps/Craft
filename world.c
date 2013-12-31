#include "config.h"
#include "noise.h"
#include "world.h"
#include "item.h"

void create_world(Map *map, int p, int q) {
    int pad = 1;
    for (int dx = -pad; dx < CHUNK_SIZE + pad; dx++) {
        for (int dz = -pad; dz < CHUNK_SIZE + pad; dz++) {
            int flag = 1;
            if (dx < 0 || dz < 0 || dx >= CHUNK_SIZE || dz >= CHUNK_SIZE) {
                flag = -1;
            }
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
            // sand and grass terrain
            for (int y = 0; y < h; y++) {
                if (y > h - l) {
                    if (w == Grass.id && y != h - 1)
                        map_set(map, x, y, z, Dirt.id * flag, 0);
                    else {
                        map_set(map, x, y, z, w, 0);
                        if (w == Grass.id && map_get(map, x, y - 1, z) == Grass.id)
                            map_set(map, x, y - 1, z, Dirt.id * flag, 0);
                    }
                } else
                    map_set(map, x, y, z, Stone.id * flag, 0);
            }
            if (w == Grass.id) {
                if (SHOW_PLANTS) {
                    // grass
                    if (simplex2(-x * 0.1, z * 0.1, 4, 0.8, 2) > 0.6) {
                        map_set(map, x, h, z, TallGrass.id * flag, 0);
                    }
                	// flowers
               		if (simplex2(x * 0.05, -z * 0.05, 4, 0.8, 2) > 0.7) {
            	        int w = YellowFlower.id + simplex2(x * 0.1, z * 0.1, 4, 0.8, 2) * 7;
            	        map_set(map, x, h, z, w * flag, 0);
            	    }
				}
                // trees
                int ok = SHOW_TREES;
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
                                    map_set(map, x + ox, y, z + oz, Leaves.id, 0);
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
            if (SHOW_CLOUDS) {
	            for (int y = 64; y < 72; y++) {
    	            if (simplex3(x * 0.01, y * 0.1, z * 0.01, 8, 0.5, 2) > 0.75) {
        	            map_set(map, x, y, z, Cloud.id * flag, 0);
            	    }
            	}
			}
        }
    }
}
