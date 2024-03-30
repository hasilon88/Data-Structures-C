#include <stdio.h>
#include <stdbool.h>
#include "../ArrayList/ArrayList.h"

void test_add() {
    ArrayList list = initArrayList();

    // Add elements
    for (int i = 0; i < 10; i++) {
        list.add(&list, i);
    }

    // Check size after adding
    if (list.size == 10)
        printf("Add test: Passed\n");
    else
        printf("Add test: Failed\n");

    // Destroy the ArrayList to free memory
    list.destroy(&list);
}

void test_add_all() {
    ArrayList list = initArrayList();

    int arr[] = {10, 11, 12, 13, 14};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Add all elements
    list.addAll(&list, arr, size);

    // Check size after adding all
    if (list.size == 5)
        printf("Add all test: Passed\n");
    else
        printf("Add all test: Failed\n");

    // Destroy the ArrayList to free memory
    list.destroy(&list);
}

void test_delete() {
    ArrayList list = initArrayList();

    // Add elements
    for (int i = 0; i < 10; i++) {
        list.add(&list, i);
    }

    // Delete an element
    list.delete(&list, 3);

    // Check size after deletion
    if (list.size == 9)
        printf("Delete test: Passed\n");
    else
        printf("Delete test: Failed\n");

    // Destroy the ArrayList to free memory
    list.destroy(&list);
}

void test_clear() {
    ArrayList list = initArrayList();

    // Add elements
    for (int i = 0; i < 10; i++) {
        list.add(&list, i);
    }

    // Clear the ArrayList
    list.clear(&list);

    // Check size after clearing
    if (list.size == 0)
        printf("Clear test: Passed\n");
    else
        printf("Clear test: Failed\n");

    // Destroy the ArrayList to free memory
    list.destroy(&list);
}

void test_get() {
    ArrayList list = initArrayList();

    // Add elements
    for (int i = 0; i < 10; i++) {
        list.add(&list, i * 2);
    }

    // Get elements at specific indices
    bool passed = true;
    for (int i = 0; i < 10; i++) {
        if (list.get(&list, i) != i * 2) {
            passed = false;
            break;
        }
    }
    if (passed)
        printf("Get test: Passed\n");
    else
        printf("Get test: Failed\n");

    // Destroy the ArrayList to free memory
    list.destroy(&list);
}

void test_index_of() {
    ArrayList list = initArrayList();

    // Add elements
    for (int i = 0; i <= 10; i++) {
        list.add(&list, i * 2);
    }

    // Get index of specific elements
    if (list.indexOf(&list, 6) == 3 && list.indexOf(&list, 15) == -1 && list.indexOf(&list, 20) == 10)
        printf("Index of test: Passed\n");
    else
        printf("Index of test: Failed\n");

    // Destroy the ArrayList to free memory
    list.destroy(&list);
}

void test_contains() {
    ArrayList list = initArrayList();

    // Add elements
    for (int i = 0; i <= 10; i++) {
        list.add(&list, i * 2);
    }

    // Check if ArrayList contains specific elements
    if (list.contains(&list, 6) && !list.contains(&list, 15) && list.contains(&list, 20))
        printf("Contains test: Passed\n");
    else
        printf("Contains test: Failed\n");

    // Destroy the ArrayList to free memory
    list.destroy(&list);
}

void test_to_string() {
    ArrayList list = initArrayList();

    // Add elements
    for (int i = 0; i < 10; i++) {
        list.add(&list, i * 2);
    }

    // Print the ArrayList
    printf("To String test:\n");
    list.toString(&list);

    // Destroy the ArrayList to free memory
    list.destroy(&list);
}

int main() {
    test_add();
    test_add_all();
    test_delete();
    test_clear();
    test_get();
    test_index_of();
    test_contains();
    test_to_string();

    return 0;
}
