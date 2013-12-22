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
#define Unknown     get_item(-1)
#define Air         get_item( 0)
#define Grass       get_item( 1)
#define Sand        get_item( 2)
#define Slab        get_item( 3)
#define Brick       get_item( 4)
#define Wood        get_item( 5)
#define Stone       get_item( 6)
#define Dirt        get_item( 7)
#define Plank       get_item( 8)
#define Snow        get_item( 9)
#define Glass       get_item(10)
#define Cobblestone get_item(11)
#define LightSlab   get_item(12)
#define DarkSlab    get_item(13)
#define WoodBox     get_item(14)
#define Leaf        get_item(15)
#define Cloud       get_item(16)
#define TallGrass   get_item(17)
#define Flower1     get_item(18)
#define Flower2     get_item(19)
#define Flower3     get_item(20)
#define Flower4     get_item(21)
#define Flower5     get_item(22)
#define Flower6     get_item(23)
#define Flower7     get_item(24)
/* ITEMS */
#define Pickaxe     get_item(256)
#define Shovel      get_item(257)
#define Axe         get_item(258)
#define Sword       get_item(259)

#endif /* item_h */