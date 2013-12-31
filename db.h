#ifndef _db_h_
#define _db_h_

#include "map.h"
#include "util.h"
#include "sign.h"

void db_enable();
void db_disable();
int get_db_enabled();
int db_init(char *path);
void db_close();
void db_commit();
void db_save_state(float x, float y, float z, float rx, float ry, Inventory inventory);
int db_load_state(float *x, float *y, float *z, float *rx, float *ry, Inventory *inventory);
void db_insert_block(int p, int q, int x, int y, int z, int w);
void db_insert_sign(
    int p, int q, int x, int y, int z, int face, const char *text);
void db_delete_sign(int x, int y, int z, int face);
void db_delete_signs(int x, int y, int z);
void db_load_map(Map *map, int p, int q);
void db_load_signs(SignList *list, int p, int q);
int db_get_key(int p, int q);
void db_set_key(int p, int q, int key);
Item db_get_slot(int slot);
void db_set_slot(int w, int slot, int count);
void db_worker_start();
void db_worker_stop();
int db_worker_run(void *arg);

#endif
