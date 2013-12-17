#ifndef _db_h_
#define _db_h_

#include "map.h"
#include "util.h"

void db_enable();
void db_disable();
int get_db_enabled();
int db_init(char *path);
void db_close();
void db_begin_transaction();
void db_commit_transaction();
void db_commit();
void db_save_state(float x, float y, float z, float rx, float ry, Inventory inventory);
int db_load_state(float *x, float *y, float *z, float *rx, float *ry, Inventory *inventory);
void db_insert_block(int p, int q, int x, int y, int z, int w);
void db_load_map(Map *map, int p, int q);
int db_get_key(int p, int q);
void db_set_key(int p, int q, int key);
Item db_get_slot(int slot);
void db_set_slot(int w, int slot, int count);

#endif
