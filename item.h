#ifndef item_h
#define item_h

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

int is_plant(int w);
int is_item(int w);
int is_obstacle(int w);
int is_transparent(int w);
int is_destructable(int w);
int is_selectable(int w);

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
static ItemType Shovel;
static ItemType Axe;
static ItemType Sword;

#endif /* item_h */