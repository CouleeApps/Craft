#include "crafting.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "item.h"

typedef struct {
    const char *input_pattern;
    int *ids;
    int output_id;
    int output_count;
} Recipe;

static Recipe *recipes;
static int recipe_count;

void init_crafting() {
    recipe_count = 0;
    recipes = calloc(256, sizeof(Recipe));

    /*
     Grid layout is like this:

     "111"
     " 0 "
     " 0 "
     
     Fill them with the index of the required item like such:
     0 = Stick, 1 = Cobblestone

     Example of how this works is shown here:

     recipes[recipe_count] = (Recipe){
         "111"
         " 0 "
         " 0 ",
         NULL, Output_Item.id, output_quantity};
     recipes[recipe_count].ids = calloc(number_of_unique_items, sizeof(int));
     recipes[recipe_count].ids[0] = Unique_Item_0.id;
     recipes[recipe_count].ids[1] = Unique_Item_1.id;
     recipe_count ++;
     */

    recipes[recipe_count] = (Recipe){
        "0  "
        "   "
        "   ",
        NULL, Grass.id, 1};
    recipes[recipe_count].ids = calloc(1, sizeof(int));
    recipes[recipe_count].ids[0] = Dirt.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        "0  "
        "0  "
        "   ",
        NULL, Snow.id, 2};
    recipes[recipe_count].ids = calloc(1, sizeof(int));
    recipes[recipe_count].ids[0] = Dirt.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        "0  "
        "   "
        "   ",
        NULL, Stone.id, 1};
    recipes[recipe_count].ids = calloc(1, sizeof(int));
    recipes[recipe_count].ids[0] = Cobblestone.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        "00 "
        "00 "
        "   ",
        NULL, LightSlab.id, 4};
    recipes[recipe_count].ids = calloc(1, sizeof(int));
    recipes[recipe_count].ids[0] = Stone.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        "000"
        "   "
        "   ",
        NULL, Slab.id, 3};
    recipes[recipe_count].ids = calloc(1, sizeof(int));
    recipes[recipe_count].ids[0] = Stone.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        "0  "
        "   "
        "   ",
        NULL, DarkSlab.id, 1};
    recipes[recipe_count].ids = calloc(1, sizeof(int));
    recipes[recipe_count].ids[0] = LightSlab.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        "0  "
        "   "
        "   ",
        NULL, LightSlab.id, 1};
    recipes[recipe_count].ids = calloc(1, sizeof(int));
    recipes[recipe_count].ids[0] = DarkSlab.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        "0  "
        "   "
        "   ",
        NULL, Plank.id, 4};
    recipes[recipe_count].ids = calloc(1, sizeof(int));
    recipes[recipe_count].ids[0] = Wood.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        "0  "
        "   "
        "   ",
        NULL, Glass.id, 1};
    recipes[recipe_count].ids = calloc(1, sizeof(int));
    recipes[recipe_count].ids[0] = Sand.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        "000"
        "0 0"
        "000",
        NULL, WoodBox.id, 8};
    recipes[recipe_count].ids = calloc(1, sizeof(int));
    recipes[recipe_count].ids[0] = Plank.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        " 1 "
        "101"
        " 1 ",
        NULL, Brick.id, 4};
    recipes[recipe_count].ids = calloc(2, sizeof(int));
    recipes[recipe_count].ids[0] = Sand.id;
    recipes[recipe_count].ids[1] = Cobblestone.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        "0  "
        "0  "
        "   ",
        NULL, Stick.id, 4};
    recipes[recipe_count].ids = calloc(1, sizeof(int));
    recipes[recipe_count].ids[0] = Plank.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        "111"
        " 0 "
        " 0 ",
        NULL, Pickaxe.id, 1};
    recipes[recipe_count].ids = calloc(2, sizeof(int));
    recipes[recipe_count].ids[0] = Stick.id;
    recipes[recipe_count].ids[1] = Cobblestone.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        "11 "
        "01 "
        "0  ",
        NULL, Axe.id, 1};
    recipes[recipe_count].ids = calloc(2, sizeof(int));
    recipes[recipe_count].ids[0] = Stick.id;
    recipes[recipe_count].ids[1] = Cobblestone.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        "1  "
        "0  "
        "0  ",
        NULL, Shovel.id, 1};
    recipes[recipe_count].ids = calloc(2, sizeof(int));
    recipes[recipe_count].ids[0] = Stick.id;
    recipes[recipe_count].ids[1] = Cobblestone.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        "1  "
        "1  "
        "0  ",
        NULL, Sword.id, 1};
    recipes[recipe_count].ids = calloc(2, sizeof(int));
    recipes[recipe_count].ids[0] = Stick.id;
    recipes[recipe_count].ids[1] = Cobblestone.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        "1  "
        "0  "
        "   ",
        NULL, Grass.id, 3};
    recipes[recipe_count].ids = calloc(2, sizeof(int));
    recipes[recipe_count].ids[0] = Dirt.id;
    recipes[recipe_count].ids[1] = Leaf.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        "1  "
        "0  "
        "   ",
        NULL, Snow.id, 3};
    recipes[recipe_count].ids = calloc(2, sizeof(int));
    recipes[recipe_count].ids[0] = Dirt.id;
    recipes[recipe_count].ids[1] = Sand.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        "00 "
        "00 "
        "   ",
        NULL, Workbench.id, 1};
    recipes[recipe_count].ids = calloc(1, sizeof(int));
    recipes[recipe_count].ids[0] = Plank.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        "000"
        "0 0"
        "000",
        NULL, Furnace.id, 1};
    recipes[recipe_count].ids = calloc(1, sizeof(int));
    recipes[recipe_count].ids[0] = Cobblestone.id;
    recipe_count ++;
}

Item get_crafting_result(Item *raw_input) {
    /* Input comes in this format:
     678
     345
     012

       But recipe is in this format:
     012
     345
     678
     */

    //Move the input into the top left

    //Top
    int shift_up = 0;
    for (int y = 2; y > 0; y --) {
        int shift = 1;

        //If the row is empty
        for (int x = 0; x < 3; x ++) {
            int pos = x + (y * 3);
            if (raw_input[pos].w != 0) {
                shift = 0;
                break;
            }
        }
        if (shift)
            shift_up ++;
        else
            break;
    }
    //Left
    int shift_left = 0, shift_right = 0;
    for (int x = 0; x < 3; x ++) {
        int shift = 1;

        //If the col is empty
        for (int y = 0; y < 3; y ++) {
            int pos = x + (y * 3);
            if (raw_input[pos].w != 0) {
                shift = 0;
                break;
            }
        }
        if (shift)
            shift_left ++;
    }

    Item *input = calloc(9, sizeof(Item));
    for (int i = 0; i < 9; i ++) {
        input[i].w = 0;
        input[i].count = 0;
    }

    for (int x = 0; x < 3; x ++) {
        for (int y = 0; y < 3; y ++) {
            int pos_old = x + (y * 3);
            int pos_new = (x - shift_left) + (y + shift_up) * 3;
            if (pos_new >= 0 && pos_new < 9) {
                input[pos_new].w = raw_input[pos_old].w;
                input[pos_new].count = raw_input[pos_old].count;
            }
        }
    }

    for (int rec = 0; rec < recipe_count; rec ++) {
        Recipe recipe = recipes[rec];
        int len = strlen(recipe.input_pattern);

        int correct = 1;
        for (int i = 0; i < len; i ++) {
            char ch;
            strncpy(&ch, recipe.input_pattern + i, sizeof(char));

            int req_w = -1;
            if (ch == ' ')
                req_w = 0;
            else if (ch > 47 && ch < 58)
                req_w = recipe.ids[ch - 48];
            else
                printf("INVALID RECIPE INDEX: %c\n", ch);

            int input_w = input[(i % 3) + (3*(2-(i / 3)))].w;

            if (req_w != input_w) { //Nope
                correct = 0;
                break;
            }
        }

        if (correct) {
            Item ret;
            ret.w = recipe.output_id;
            ret.count = recipe.output_count;
            return ret;
        }
    }

    return(Item){0};
    for (int y = 0; y < 3; y ++) {
        int pos1 = (y * 3);
        int pos2 = (y * 3) + 2 - (shift_right + shift_left);
        //Swap them
        Item store;
        store.w = input[pos1].w;
        store.count = input[pos1].count;
        input[pos1].w = input[pos2].w;
        input[pos1].count = input[pos2].count;
        input[pos2].w = store.w;
        input[pos2].count = store.count;
    }

    //Attempt again reversed
    for (int rec = 0; rec < recipe_count; rec ++) {
        Recipe recipe = recipes[rec];
        int len = strlen(recipe.input_pattern);

        int correct = 1;
        for (int i = 0; i < len; i ++) {
            char ch;
            strncpy(&ch, recipe.input_pattern + i, sizeof(char));

            int req_w = -1;
            if (ch == ' ')
                req_w = 0;
            else if (ch > 47 && ch < 58)
                req_w = recipe.ids[ch - 48];
            else
                printf("INVALID RECIPE INDEX: %c\n", ch);

            int input_w = input[(i % 3) + (3*(2-(i / 3)))].w;

            if (req_w != input_w) { //Nope
                correct = 0;
                break;
            }
        }

        if (correct) {
            Item ret;
            ret.w = recipe.output_id;
            ret.count = recipe.output_count;
            return ret;
        }
    }

    return (Item){0};
}
