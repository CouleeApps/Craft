#ifndef _config_h_
#define _config_h_

// From math.h
#define M_PI_2 1.57079632679489661923132169163975144   /* pi/2           */

// app parameters
#define FULLSCREEN 0
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 768
#define VSYNC 1
#define SCROLL_THRESHOLD 0.1
#define MAX_MESSAGES 4
#define DB_PATH "craft.db"
#define USE_CACHE 1
#define DAY_LENGTH 300

// rendering options
#define SHOW_PLANTS 1
#define SHOW_CLOUDS 1
#define SHOW_TREES 1
#define SHOW_ITEM 1
#define SHOW_CROSSHAIRS 1
#define SHOW_WIREFRAME 1
#define SHOW_INFO_TEXT 1
#define SHOW_CHAT_TEXT 1
#define SHOW_PLAYER_NAMES 1

// key bindings
#define CRAFT_KEY_QUIT GLFW_KEY_BACKSPACE
#define CRAFT_KEY_FORWARD 'W'
#define CRAFT_KEY_BACKWARD 'S'
#define CRAFT_KEY_LEFT 'A'
#define CRAFT_KEY_RIGHT 'D'
#define CRAFT_KEY_DROP 'Q'
#define CRAFT_KEY_JUMP GLFW_KEY_SPACE
#define CRAFT_KEY_FLY GLFW_KEY_TAB
#define CRAFT_KEY_OBSERVE 'O'
#define CRAFT_KEY_OBSERVE_INSET 'P'
#define CRAFT_KEY_INVENTORY 'E'
#define CRAFT_KEY_BLOCK_TYPE 'R'
#define CRAFT_KEY_ZOOM GLFW_KEY_LEFT_SHIFT
#define CRAFT_KEY_ORTHO 'F'
#define CRAFT_KEY_CHAT 't'
#define CRAFT_KEY_COMMAND '/'

// keys for moving along axes
#define CRAFT_KEY_XM 'Z'
#define CRAFT_KEY_XP 'X'
#define CRAFT_KEY_YM 'C'
#define CRAFT_KEY_YP 'V'
#define CRAFT_KEY_ZM 'B'
#define CRAFT_KEY_ZP 'N'

// advanced parameters
#define CREATE_CHUNK_RADIUS 6
#define RENDER_CHUNK_RADIUS 6
#define DELETE_CHUNK_RADIUS 12
#define CHUNK_SIZE 32
#define COMMIT_INTERVAL 5

// inventory
#define INVENTORY_SLOTS 9
#define INVENTORY_ROWS 4
#define INVENTORY_CRAFT_SIZE 3
#define MAX_SLOT_SIZE 64
#define INVENTORY_ITEM_SIZE 48
#define INVENTORY_FONT_SIZE 20
#define INVENTORY_UNLIMITED 0x7fffffff

// creative
#define CREATIVE_MODE 0

// hide inventory things
#define SHOW_CRAFT_SCREEN 0
#define SHOW_INVENTORY_COUNTS 1
#define SHOW_INVENTORY_ITEMS 1
#define SHOW_INVENTORY_BG 1
#define SHOW_INVENTORY_WINDOW 1
#define SHOW_INVENTORY_BAR 1
#define SHOW_INVENTORY_SELECTION 0

#endif
