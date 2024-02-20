#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/*
    This function takes two pointers:
    - str: An array of characters to be split into tokens based on delimiter characters.
    - delims: An array of characters used to split `str`.

    The function returns a null-terminated array of pointers. Each pointer points to a substring of `str` delimited by characters found in `delims`.

    The return value is an array of pointers of size k+1, where k is the number of times that a character from `delims` was found in `str`.

    Note that the pointers in the return value must point to memory locations within `str`. Therefore, each substring in `str` must be null-terminated, and the pointers must point to the beginning of each substring.
*/
char **tokenize(char *str, const char *delims) {
    int delim_count = get_delim_count(str, delims) + 1; // k + 1 (Length of return array)
    char **result = get_null_arr(delim_count);   // Return Array with Null Pointer Pointers

    int result_idx = 0;
    char *token_location = str;

    while (*str != '\0') {
        const char *delim_pointer = delims;

        while (*delim_pointer != '\0') {
            if (*delim_pointer == *str) {
                *str = '\0'; // Terminate to Null
                result[result_idx] = token_location;
                result_idx++;
                token_location = str + 1;
                break;
            }

            delim_pointer++;
        }
        str++;
    }

    result[result_idx] = token_location;
    return result;
}

int get_delim_count(char *str, const char *delims) {
    int count = 0;
    const char *str_restart;

    while (*delims) {
        str_restart = str;
        while (*str_restart) {
            if (*str_restart == *delims) {
                count++;
            }
            str_restart++;
        }
        delims++;
    }
    return count;
}

char **get_null_arr(int size) {
    char **nulled_arr = (char **)malloc((size) * sizeof(char *)); // one time use

    for (int i = 0; i < size + 1; i++) {
        nulled_arr[i] = NULL;
    }
    return nulled_arr;
}

