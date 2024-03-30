#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ArrayList ArrayList;

struct ArrayList {
    int *array;
    int length;

    bool (*add)(ArrayList *self, int value);
    bool (*addAll)(ArrayList *self, int array[], int length);
    bool (*delete)(ArrayList *self, int index);
    bool (*clear)(ArrayList *self);

    int (*get)(ArrayList *self, int index);
    int (*indexOf)(ArrayList *self, int value);
    bool (*contains)(ArrayList *self, int value);
    int (*size)(ArrayList *self);
    char *(*toString)(ArrayList *self); // Modified to return string
    void (*destroy)(ArrayList *self);
};

ArrayList initArrayList();

#endif /* ARRAYLIST_H */
