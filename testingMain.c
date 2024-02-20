#include <stdio.h>
#include <stdlib.h>
#include "methodsForLab.h"

typedef struct {
    int value;
} Data;

// Function to print Data
void printData(void *ptr) {
    Data *data = (Data *)ptr;
    printf("%d ", data-> value);
}

// Function to copy Data
void *copyData(void *ptr) {
    Data *data = (Data *)ptr;
    Data *newData = (Data *)malloc(sizeof(Data));
    if (newData != NULL) {
        newData->value = data->value;
    }
    return newData;
}

// Function to delete Data
int deleteData(void *ptr) {
    if (ptr != NULL) {
        free(ptr);
        return 0;
    }
    return 1;
}


int main (void){
    // Initialize ArrayList
        ArrayList_t *list = AL_init();
        
        // Insert elements
        for (int i = 0; i < 5; i++) {
            Data *data = (Data *)malloc(sizeof(Data));
            data->value = i + 1;
            AL_insert_last(list, data, copyData);
        }
        
        // Print elements
        printf("Initial List: ");
        AL_print(list, printData);
        printf("\n");
        
        // Test AL_get_at
        printf("Element at index 2: ");
        Data *element = (Data *)AL_get_at(list, 2);
        if (element != NULL) {
            printf("%d\n", element->value);
        } else {
            printf("Index out of bounds or list empty.\n");
        }
        
        // Test AL_set_at
        Data *newData = (Data *)malloc(sizeof(Data));
        newData->value = 10;
        if (AL_set_at(list, 2, newData, copyData, deleteData) == 0) {
            printf("List after setting element at index 2 to 10: ");
            AL_print(list, printData);
            printf("\n");
        } else {
            printf("Failed to set element at index 2.\n");
        }
        
        // Test AL_insert_first
        Data *firstData = (Data *)malloc(sizeof(Data));
        firstData->value = 100;
        if (AL_insert_first(list, firstData, copyData) == 0) {
            printf("List after inserting 100 at the beginning: ");
            AL_print(list, printData);
            printf("\n");
        } else {
            printf("Failed to insert 100 at the beginning.\n");
        }
        
        // Test AL_delete_at
        if (AL_delete_at(list, 2, deleteData) == 0) {
            printf("List after deleting element at index 2: ");
            AL_print(list, printData);
            printf("\n");
        } else {
            printf("Failed to delete element at index 2.\n");
        }
        
        // Free memory
        AL_free(list, deleteData);
        
        return 0;
    }
