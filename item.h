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
int is_placeable(int w);

/* BLOCKS */
#define Unknown      get_item(-1)
#define Air          get_item( 0)
#define Grass        get_item( 1)
#define Sand         get_item( 2)
#define Stone        get_item( 3)
#define Brick        get_item( 4)
#define Wood         get_item( 5)
#define Cement       get_item( 6)
#define Dirt         get_item( 7)
#define Plank        get_item( 8)
#define Snow         get_item( 9)
#define Glass        get_item(10)
#define Cobblestone  get_item(11)
#define LightStone   get_item(12)
#define DarkStone    get_item(13)
#define Chest        get_item(14)
#define Leaves       get_item(15)
#define Cloud        get_item(16)
#define TallGrass    get_item(17)
#define YellowFlower get_item(18)
#define RedFlower    get_item(19)
#define PurpleFlower get_item(20)
#define SunFlower    get_item(21)
#define WhiteFlower  get_item(22)
#define BlueFlower   get_item(23)
#define RedWool      get_item(24)
#define GreenWool    get_item(25)
#define BlueWool     get_item(26)
#define OrangeWool   get_item(27)
#define PurpleWool   get_item(28)
#define BeigeWool    get_item(29)
#define Furnace      get_item(30)
#define Workbench    get_item(31)
/* ITEMS */
#define Pickaxe     get_item(256)
#define Shovel      get_item(257)
#define Axe         get_item(258)
#define Sword       get_item(259)
#define Stick       get_item(260)

#define EMPTY 0
#define GRASS 1
#define SAND 2
#define STONE 3
#define BRICK 4
#define WOOD 5
#define CEMENT 6
#define DIRT 7
#define PLANK 8
#define SNOW 9
#define GLASS 10
#define COBBLE 11
#define LIGHT_STONE 12
#define DARK_STONE 13
#define CHEST 14
#define LEAVES 15
#define CLOUD 16
#define TALL_GRASS 17
#define YELLOW_FLOWER 18
#define RED_FLOWER 19
#define PURPLE_FLOWER 20
#define SUN_FLOWER 21
#define WHITE_FLOWER 22
#define BLUE_FLOWER 23
#define RED_WOOL 24
#define GREEN_WOOL 25
#define BLUE_WOOL 26
#define ORANGE_WOOL 27
#define PURPLE_WOOL 28
#define BEIGE_WOOL 29

extern const int items[];
extern int item_count;
extern const int blocks[256][6];
extern const int plants[256];

#endif
