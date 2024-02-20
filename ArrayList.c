#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"

ArrayList_t *AL_init(void){
    ArrayList_t *arraylist;
    
    arraylist = (ArrayList_t *)malloc(sizeof(ArrayList_t));
    
    arraylist -> size = 0;
    
    return arraylist;
}

int AL_free(ArrayList_t *AL, int (*delete_data)(void *)){
    ArrayList_t *size, *data;
    
    if(AL == NULL){
        return 1;
    }
    /*
    while (AL -> size != 0) {
        delete_data(AL -> data);
        AL -> size--;
    }
    
     */
    
    if (delete_data != NULL) {
        for (int i = 0; i < AL->size; i++) {
            delete_data(AL->data[i]);
        }
    }
    
    free(AL -> data);
    free(AL);
    return 0;
}

void AL_print(ArrayList_t *AL, void (*print_data)(void *)) {
    if (AL == NULL || AL->size == 0) {
        printf("ArrayList is empty.\n");
        return;
    }

    for (int i = 0; i < AL->size; i++) {
        print_data(AL->data[i]);
    }
}

void *AL_get_at(ArrayList_t *AL, size_t i){
    if(AL == NULL || i > AL -> size){
        return NULL;
    }
    return (AL -> data[i]);
}

int AL_set_at(ArrayList_t *AL, size_t i, void *elem, void*(*copy_data)(void *), int (*delete_data)(void *)){
    
    if(AL == NULL || i > AL -> size){
        return 1;
    }
    
    if(delete_data != NULL){
        delete_data(AL-> data[i]);
    }
    
    if(copy_data != NULL){
        AL -> data[i] = copy_data(elem);
    }else{
        AL -> data[i] = elem;
    }
    return 0;
}

int AL_insert_first(ArrayList_t *AL, void *elem, void*(*copy_data)(void *)) {
    if (AL == NULL || copy_data == NULL) {
        return 1;
    }
    
    // Reallocate memory to accommodate the new element
    AL-> data = realloc(AL-> data, (AL-> size + 1) * sizeof(void *));
    if (AL-> data == NULL) {
        return 1;
    }
    
    // Shift existing elements to the right
    for (int i = AL-> size; i > 0; i--) {
        AL-> data[i] = AL-> data[i - 1];
    }
    
    // Copy new element to the first position
    AL-> data[0] = copy_data(elem);
    AL-> size++;
    
    return 0; // Success
}

int AL_delete_first(ArrayList_t *AL, int (*delete_data)(void *)) {
    if (AL == NULL || AL-> size == 0) {
        return 1; // Error: Invalid ArrayList or empty list
    }
    
    // Delete the first element if delete_data function is provided
    if (delete_data != NULL) {
        delete_data(AL-> data[0]);
    }
    
    // Shift remaining elements to the left
    for (int i = 1; i < AL-> size; i++) {
        AL-> data[i - 1] = AL-> data[i];
    }
    
    // Reallocate memory to resize the data array
    AL-> data = realloc(AL-> data, (AL-> size - 1) * sizeof(void *));
    if (AL-> data == NULL && AL-> size > 1) {
        return 1; // Error: Memory reallocation failed
    }
    
    AL-> size--;
    
    return 0; // Success
}

int AL_insert_last(ArrayList_t *AL, void *elem, void*(*copy_data)(void *)) {
    if (AL == NULL || elem == NULL) {
        return 1; // Invalid ArrayList or element
    }
    
    AL->size++;
    void **new_data = realloc(AL->data, AL->size * sizeof(void *));
    if (new_data == NULL) {
        // Memory reallocation failed, rollback size
        AL->size--;
        return 1;
    }
    
    AL->data = new_data;
    AL->data[AL->size - 1] = copy_data(elem);
    return 0; // Success
}

int AL_delete_last(ArrayList_t *AL, int (*delete_data)(void *)){
    if(delete_data == NULL || AL -> size == 0){
        return 1;
    }
    
    delete_data(AL -> data[(AL -> size)-1]);
    AL-> data = realloc(AL-> data, (AL-> size - 1) * sizeof(void *));
    AL -> size--;
    return 0;
    
}

int AL_insert_at(ArrayList_t *AL, size_t i, void *elem, void *(*copy_data)(void *)) {
    if (copy_data == NULL || AL == NULL) {
        return 1; // Return 1 indicating failure
    }
    
    AL->size++;
    if (i > AL-> size) {
        AL-> data = realloc(AL-> data, AL-> size * sizeof(void *));
        if (AL-> data == NULL) {
            return 1; // Return 1 indicating failure
        }
        AL-> data[AL-> size - 1] = copy_data(elem); // Add elem at the end of the list
        return 0; // Return 0 indicating success
    }
    
    AL-> data = realloc(AL-> data, AL-> size * sizeof(void *));
    if (AL-> data == NULL) {
        return 1; // Return 1 indicating failure
    }
    
    // Shift elements to make space for the new element
    for (int location = AL-> size; location > i; location--) {
        AL-> data[location] = AL-> data[location - 1];
    }
    
    AL-> data[i] = copy_data(elem);
    AL -> size++;
    return 0;
}

int AL_delete_at(ArrayList_t *AL, size_t i, int (*delete_data)(void*)) {
    if (AL == NULL || delete_data == NULL || i >= AL->size) {
        return 1; // Invalid ArrayList, delete_data is NULL, or index out of bounds
    }
    
    // Delete data at index i
    delete_data(AL->data[i]);
    
    // Shift remaining elements to the left
    for (size_t j = i; j < AL->size - 1; j++) {
        AL->data[j] = AL->data[j + 1];
    }
    
    // Resize the data array
    void **new_data = realloc(AL->data, (AL->size - 1) * sizeof(void *));
    if (new_data == NULL && AL->size > 1) {
        return 1; // Memory reallocation failed
    }
    
    AL->data = new_data;
    AL->size--;
    
    return 0; // Success
}



