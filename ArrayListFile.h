#ifndef ArrayListFile_h
#define ArrayListFile_h

#include <stdio.h>

typedef struct {
    int size;
    void **data;
}ArrayList_t; //name of struct

/*
 Task: Initialize an array list that can store 0 elements.
 Return value: Pointer to an ArrayList_t variable if successful, NULL otherwise.
 Run time: O(1).
 */
ArrayList_t *AL_init(void);

/*
 Task: Delete all AL elements store in heap including AL itself.
 Return value: Return 0 if everything was free successfully, 1 otherwise.
 Run time: O(n).
 */
int AL_free(ArrayList_t *AL, int (*delete_data)(void *));

/*
 Task: Print all AL data elements in AL.
 Return value: N/A.
 Run time: O(n).
 */
void AL_print(ArrayList_t *AL, void (*print_data)(void *));

/*
 Task: Return the pointer that points to the element in AL at index I.
 Return value: Pointer to the element if retrieve successfully, NULL otherwise.
 Run time: O(1).
 */
void *AL_get_at(ArrayList_t *AL, size_t i);

/*
 Task: Overwrite the element pointed to at index i in AL.
 Return value: Return 0 if overwrite successfully, 1 otherwise.
 Run time: O(1).
 */
int AL_set_at(ArrayList_t *AL, size_t i, void *elem, void*(*copy_data)(void *), int (*delete_data)(void *));

/*
 Task: Add elem as the first element in AL.
 Return value: Return 0 if pre-append successfully, 1 otherwise.
 Run time: O(1) amortize.
 */
int AL_insert_first(ArrayList_t *AL, void *elem, void*(*copy_data)(void *));

/*
 Task: Delete first element in AL.
 Return value: Return 0 if first element was deleted successfully, 1 otherwise.
 Run time: O(1) amortize.
 */
int AL_delete_first(ArrayList_t *AL, int (*delete_data)(void *));

/*
 Task: Add an element as the last element of AL.
 Return value: Return 0 if appended successfully, 1 otherwise.
 Run time: O(1) amortize.
 */
int AL_insert_last(ArrayList_t *AL, void *elem, void*(*copy_data)(void *));

/*
 Task: Delete the last element in AL.
 Return value: Return 0 if deleted successfully, 1 otherwise.
 Run time: O(1) amortize.
 */
int AL_delete_last(ArrayList_t *AL, int (*delete_data)(void *));

/*
 Task: Insert an element at index i in AL.
 Return value: Return 0 if the element was added successfully, 1 otherwise.
 Run time: O(n).
 
 Note:
 ▪ If insertion location is greater than the store number of elements in AL, add elem at
 the end of the list.
 */
int AL_insert_at(ArrayList_t *AL, size_t i, void *elem, void*(*copy_data)(void *));

/*
 Task: Delete an element at index i in AL.
 Return value: Return 0 if the element was added successfully, 1 otherwise.
 Run time: O(n).
 
 Note:
 ▪ If deletion location is greater than the store number of elements in AL, return failure
 case.
 */
int AL_delete_at(ArrayList_t *AL, size_t i, int (*delete_data)(void*));

#endif /* ArrayListFile_h */
