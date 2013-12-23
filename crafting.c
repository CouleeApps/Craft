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

    recipes[recipe_count] = (Recipe){
        "   "
        " 0 "
        "   ",
        NULL, Grass.id, 1};
    recipes[recipe_count].ids = calloc(1, sizeof(int));
    recipes[recipe_count].ids[0] = Dirt.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        "   "
        " 0 "
        " 0 ",
        NULL, Snow.id, 2};
    recipes[recipe_count].ids = calloc(1, sizeof(int));
    recipes[recipe_count].ids[0] = Dirt.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        "   "
        " 0 "
        "   ",
        NULL, Stone.id, 1};
    recipes[recipe_count].ids = calloc(1, sizeof(int));
    recipes[recipe_count].ids[0] = Cobblestone.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        "   "
        " 00"
        " 00",
        NULL, LightSlab.id, 4};
    recipes[recipe_count].ids = calloc(1, sizeof(int));
    recipes[recipe_count].ids[0] = Stone.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        "   "
        "   "
        "000",
        NULL, Slab.id, 3};
    recipes[recipe_count].ids = calloc(1, sizeof(int));
    recipes[recipe_count].ids[0] = Stone.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        "   "
        " 0 "
        "   ",
        NULL, DarkSlab.id, 1};
    recipes[recipe_count].ids = calloc(1, sizeof(int));
    recipes[recipe_count].ids[0] = LightSlab.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        "   "
        " 0 "
        "   ",
        NULL, LightSlab.id, 1};
    recipes[recipe_count].ids = calloc(1, sizeof(int));
    recipes[recipe_count].ids[0] = DarkSlab.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        "   "
        " 0 "
        "   ",
        NULL, Plank.id, 4};
    recipes[recipe_count].ids = calloc(1, sizeof(int));
    recipes[recipe_count].ids[0] = Wood.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        "   "
        " 0 "
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
        "   "
        " 0 "
        " 0 ",
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
        "10 "
        " 0 ",
        NULL, Axe.id, 1};
    recipes[recipe_count].ids = calloc(2, sizeof(int));
    recipes[recipe_count].ids[0] = Stick.id;
    recipes[recipe_count].ids[1] = Cobblestone.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        " 1 "
        " 0 "
        " 0 ",
        NULL, Shovel.id, 1};
    recipes[recipe_count].ids = calloc(2, sizeof(int));
    recipes[recipe_count].ids[0] = Stick.id;
    recipes[recipe_count].ids[1] = Cobblestone.id;
    recipe_count ++;
    //-------------------------------------------------
    recipes[recipe_count] = (Recipe){
        " 1 "
        " 1 "
        " 0 ",
        NULL, Sword.id, 1};
    recipes[recipe_count].ids = calloc(2, sizeof(int));
    recipes[recipe_count].ids[0] = Stick.id;
    recipes[recipe_count].ids[1] = Cobblestone.id;
    recipe_count ++;
}

Item get_crafting_result(Item *input) {
    /* Input comes in this format:
     678
     345
     012

       But recipe is in this format:
     012
     345
     678
     */
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