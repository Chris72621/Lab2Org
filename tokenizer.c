#include <stdio.h>
#include "tokenizer.h"

/*
    This function takes two pointers:
    - str: An array of characters to be split into tokens based on delimiter characters.
    - delims: An array of characters used to split `str`.

    The function returns a null-terminated array of pointers. Each pointer points to a substring of `str` delimited by characters found in `delims`.
    
    The return value is an array of pointers of size k+1, where k is the number of times that a character from `delims` was found in `str`.
    
    Note that the pointers in the return value must point to memory locations within `str`. Therefore, each substring in `str` must be null-terminated, and the pointers must point to the beginning of each substring.
*/
char ** tokenize(char *str, const char *delims) {
    int length = 0;
    int delim_count = get_delim_count(str,delims) + 1; // k + 1

    // while (*str != '\0') {
    //     *str++;
    // }

    return NULL;
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

int main () {
    char str[] = "H,el,lo,;World";
    const char delims[] = ",;";

    // Call tokenize function with addresses of str and delims
    char **result = tokenize(str, delims);
    return 0;
}