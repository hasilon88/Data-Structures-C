#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    char *(*toString)(ArrayList *self);
    void (*destroy)(ArrayList *self);
};

bool arraylist_add(ArrayList *self, int value) {
    if (self->length >= 10) {
        int *temp = realloc(self->array, (self->length + 1) * sizeof(int));
        if (temp == NULL) {
            printf("Realloc error, Memory reallocation failed\n");
            return false;
        }
        self->array = temp;
    }
    self->array[self->length++] = value;
    return true;
}

bool arraylist_add_all(ArrayList *self, int array[], int length) {
    int initialLength = self->length;

    for (int i = 0; i < length; ++i) {
        if (!self->add(self, array[i]))
            return false;
    }

    return initialLength != self->length;
}

bool arraylist_delete(ArrayList *self, int index) {
    if (self->length < 1 || (index > self->length-1 || index < 0)) {
        return false;
    }

    self->length--;

    int *tempArray = (int *)malloc(self->length * sizeof (int));
    if (tempArray == NULL) {
        printf("Malloc error, Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int j = 0;
    for (int i = 0; i < self->length + 1; ++i) {
        if (i != index) {
            tempArray[j++] = self->array[i];
        }
    }

    free(self->array);
    self->array = (self->length == 0) ? NULL : tempArray;

    return true;
}

bool arraylist_clear(ArrayList *self) {
    free(self->array);

    int *tempArray = (int *)malloc(10 * sizeof (int));
    if (tempArray == NULL) {
        printf("Malloc error, Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    self->array = tempArray;
    self->length = 0;
    return true;
}

int arraylist_get(ArrayList *self, int index) {
    if (index < 0 || index > self->length-1) {
        printf("Out of range");
        return -1;
    }
    return self->array[index];
}

int arraylist_index_of(ArrayList *self, int value) {
    for (int i = 0; i < self->length; ++i) {
        if (self->get(self, i) == value)
            return i;
    }

    return -1;
}

bool arraylist_contains(ArrayList *self, int value) {
    for (int i = 0; i < self->length; ++i) {
        if (self->array[i] == value) {
            return true;
        }
    }
    return false;
}

int size(ArrayList *self) {
    return self->length;
}

char *arraylist_toString(ArrayList *arrayList) {
    char *str = (char *)malloc(1);
    str[0] = '\0';

    if (arrayList->length == 0) {
        return str;
    }

    int totalLength = 0;
    for (int i = 0; i < arrayList->length; i++) {
        int numLength = snprintf(NULL, 0, "%d", arrayList->array[i]);
        totalLength += numLength + 2;
    }
    totalLength += 3;

    str = (char *)realloc(str, totalLength);
    if (str == NULL) {
        free(str);
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    strcpy(str, "[");
    for (int i = 0; i < arrayList->length - 1; i++) {
        char numStr[12];
        sprintf(numStr, "%d, ", arrayList->array[i]);
        strcat(str, numStr);
    }
    char numStr[12];
    sprintf(numStr, "%d", arrayList->array[arrayList->length - 1]);
    strcat(str, numStr);
    strcat(str, "]");

    return str;
}

void arraylist_destroy(ArrayList* arrayList) {
    free(arrayList->array);
}

ArrayList initArrayList() {
    ArrayList arrayList;
    arrayList.array = (int *)malloc(10 * sizeof (int));
    if (arrayList.array == NULL) {
        printf("Malloc error, Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    arrayList.length = 0;

    arrayList.add = arraylist_add;
    arrayList.addAll = arraylist_add_all;
    arrayList.delete = arraylist_delete;
    arrayList.get = arraylist_get;
    arrayList.indexOf = arraylist_index_of;
    arrayList.contains = arraylist_contains;
    arrayList.toString = arraylist_toString;
    arrayList.destroy = arraylist_destroy;
    arrayList.clear = arraylist_clear;
    arrayList.size = size;

    return arrayList;
}