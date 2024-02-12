#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my_string.h"


/*
    find length of string - The strnlen() function returns either the same result as strlen() or maxlen, whichever is smaller.
*/ // TESTED & GOOD
int str_len(const char *s) {
    int length = 0;
    const char *pointer = s; // Enters the "Array" to the Chars

    while (*pointer != '\0') { // '\0' is basically empty 
        length++;
        pointer++; // Moves forward
    }

    return length;
}

/*
    functions lexicographically compare the null-terminated strings s1 and s2.
    return an integer greater than, equal to, or less than 0, according as the string s1 is greater than, equal to, or less than the string s2. 
*/ // TESTED & GOOD
int str_cmp(const char *s1, const char *s2) {
    int largest_str = get_largest_length(s1,s2);

    while (largest_str != 0) {
        int s1_char_val = (int) *s1; // ASCII Value of current Char 
        int s2_char_val = (int) *s2;

        if (s1_char_val < s2_char_val) {
            return s1_char_val - s2_char_val; // return diffrence=
        } else if (s1_char_val > s2_char_val) {
            return s1_char_val - s2_char_val; // return diffrence
        }
        
        s1++, s2++, largest_str--;
    }

    return 0;
}

int get_largest_length(const char *s1, const char *s2) {
    int length_s1 = str_len(s1);
    int length_s2 = str_len(s2);

    if (length_s1 >= length_s2) {
        return length_s1;
    }

    return length_s2;
}

int main () {

    
    
    return 0;
}