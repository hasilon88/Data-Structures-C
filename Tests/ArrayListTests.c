#include <stdio.h>
#include "../ArrayList/ArrayList.h"

void test_arraylist_add() {
    ArrayList list = initArrayList();
    int i;

    for (i = 0; i < 5; ++i) {
        list.add(&list, i);
    }

    if (list.length == 5 && list.array[0] == 0 && list.array[4] == 4) {
        printf("test_arraylist_add: Passed\n");
    } else {
        printf("test_arraylist_add: Failed\n");
    }

    list.destroy(&list);
}

void test_arraylist_add_all() {
    ArrayList list = initArrayList();
    int testArray[5] = {10, 20, 30, 40, 50};
    int i;

    list.addAll(&list, testArray, 5);

    int passed = 1;
    for (i = 0; i < 5; ++i) {
        if (list.array[i] != testArray[i]) {
            passed = 0;
            break;
        }
    }

    if (list.length == 5 && passed) {
        printf("test_arraylist_add_all: Passed\n");
    } else {
        printf("test_arraylist_add_all: Failed\n");
    }

    list.destroy(&list);
}

void test_arraylist_delete() {
    ArrayList list = initArrayList();
    int testArray[5] = {10, 20, 30, 40, 50};

    list.addAll(&list, testArray, 5);
    list.delete(&list, 2); // Delete element at index 2 (value 30)

    int passed = (list.length == 4 && list.array[2] == 40);

    if (passed) {
        printf("test_arraylist_delete: Passed\n");
    } else {
        printf("test_arraylist_delete: Failed\n");
    }

    list.destroy(&list);
}

void test_arraylist_clear() {
    ArrayList list = initArrayList();
    int testArray[5] = {10, 20, 30, 40, 50};

    list.addAll(&list, testArray, 5);
    list.clear(&list);

    int passed = (list.size(&list) == 0 && list.array != NULL);

    if (passed) {
        printf("test_arraylist_clear: Passed\n");
    } else {
        printf("test_arraylist_clear: Failed\n");
    }

    list.destroy(&list);
}

void test_arraylist_get() {
    ArrayList list = initArrayList();
    int testArray[5] = {10, 20, 30, 40, 50};

    list.addAll(&list, testArray, 5);

    int passed = 1;
    int i;
    for (i = 0; i < 5; ++i) {
        if (list.get(&list, i) != testArray[i]) {
            passed = 0;
            break;
        }
    }

    if (passed) {
        printf("test_arraylist_get: Passed\n");
    } else {
        printf("test_arraylist_get: Failed\n");
    }

    list.destroy(&list);
}

void test_arraylist_index_of() {
    ArrayList list = initArrayList();
    int testArray[5] = {10, 20, 30, 40, 50};

    list.addAll(&list, testArray, 5);

    int passed = (list.indexOf(&list, 30) == 2);

    if (passed) {
        printf("test_arraylist_index_of: Passed\n");
    } else {
        printf("test_arraylist_index_of: Failed\n");
    }

    list.destroy(&list);
}

void test_arraylist_contains() {
    ArrayList list = initArrayList();
    int testArray[5] = {10, 20, 30, 40, 50};

    list.addAll(&list, testArray, 5);

    int passed = (list.contains(&list, 30) && !list.contains(&list, 60));

    if (passed) {
        printf("test_arraylist_contains: Passed\n");
    } else {
        printf("test_arraylist_contains: Failed\n");
    }

    list.destroy(&list);
}

void test_arraylist_size() {
    ArrayList list = initArrayList();
    int testArray[5] = {10, 20, 30, 40, 50};

    list.addAll(&list, testArray, 5);

    int passed = (list.size(&list) == 5);

    if (passed) {
        printf("test_arraylist_size: Passed\n");
    } else {
        printf("test_arraylist_size: Failed\n");
    }

    list.destroy(&list);
}

void test_arraylist_toString() {
    ArrayList list = initArrayList();
    int testArray[5] = {10, 20, 30, 40, 50};

    list.addAll(&list, testArray, 5);
    char *str = list.toString(&list);

    // Customize your own checks based on how you expect the string representation
    // of the array to be
    printf("ArrayList as String: %s\n", str);

    free(str);
    list.destroy(&list);
    printf("test_arraylist_toString: Passed\n");
}

int main() {
    test_arraylist_add();
    test_arraylist_add_all();
    test_arraylist_delete();
    test_arraylist_clear();
    test_arraylist_get();
    test_arraylist_index_of();
    test_arraylist_contains();
    test_arraylist_size();
    test_arraylist_toString();

    return 0;
}
