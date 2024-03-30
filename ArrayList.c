#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ArrayList ArrayList;

struct ArrayList {
    int *array;
    int size;

    bool (*add)(ArrayList *self, int value);
    bool (*addAll)(ArrayList *self, int array[], int size);
    bool (*delete)(ArrayList *self, int index);
    bool (*clear)(ArrayList *self);

    int (*get)(ArrayList *self, int index);
    bool (*contains)(ArrayList *self, int value);

    void (*toString)(ArrayList *self);
    void (*deleteArrayList)(ArrayList *self);
};

bool add(ArrayList *self, int value) {
    if (self->size < 10) {
        self->array[self->size++] = value;
        return true;
    } else {
        int *temp = realloc(self->array, (self->size + 1) * sizeof(int));
        if (temp == NULL) {
            printf("Realloc error, Memory reallocation failed\n");
            return false;
        }
        self->array = temp;
        self->array[self->size++] = value;
        return true;
    }
}

bool addAll(ArrayList *self, int array[], int size) {
    int initialSize = self->size;

    for (int i = 0; i < size; ++i) {
        if (!self->add(self, array[i]))
            return false;
    }

    return initialSize != self->size;
}

bool delete(ArrayList *self, int index) {
    if (self->size < 1 || (index > self->size-1 || index < 0)) {
        return false;
    }

    self->size--;

    int *tempArray = (int *)malloc(self->size * sizeof(int));
    if (tempArray == NULL) {
        printf("Malloc error, Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int j = 0;
    for (int i = 0; i < self->size + 1; ++i) {
        if (i != index) {
            tempArray[j++] = self->array[i];
        }
    }

    free(self->array);
    self->array = (self->size == 0) ? NULL : tempArray;

    return true;
}

bool clear(ArrayList *self) {
    free(self->array);

    int *tempArray = (int *)malloc(10 * sizeof(int));
    if (tempArray == NULL) {
        printf("Malloc error, Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    self->array = tempArray;
    self->size = 0;
    return true;
}

int get(ArrayList *self, int index) {
    if (index < 0 || index > self->size-1) {
        printf("Out of range");
        return -1;
    }
    return self->array[index];
}

bool contains(ArrayList *self, int value) {
    for (int i = 0; i < self->size; ++i) {
        if (self->array[i] == value)
            return true;
    }
    return false;
}

void toString(ArrayList* arrayList) {
    printf("\n[");
    for (int i = 0; i < arrayList->size - 1; i++) {
        printf("%d,", arrayList->array[i]);
    }
    if (arrayList->size > 0) {
        printf("%d", arrayList->array[arrayList->size - 1]);
    }
    printf("]\n");
}

void deleteArrayList(ArrayList* arrayList) {
    free(arrayList->array);
}

ArrayList createArrayList() {
    ArrayList arrayList;
    arrayList.array = (int *)malloc(10 * sizeof(int));
    if (arrayList.array == NULL) {
        printf("Malloc error, Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    arrayList.size = 0;

    arrayList.add = add;
    arrayList.addAll = addAll;
    arrayList.delete = delete;
    arrayList.get = get;
    arrayList.contains = contains;
    arrayList.toString = toString;
    arrayList.deleteArrayList = deleteArrayList;
    arrayList.clear = clear;

    return arrayList;
}