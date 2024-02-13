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

// TESTED & GOOD
int str_n_cmp(const char *s1, const char *s2, size_t n) {

    while (n != 0) {
        int s1_char_val = (int) *s1; // ASCII Value of current Char 
        int s2_char_val = (int) *s2;

        if (s1_char_val < s2_char_val) {
            return s1_char_val - s2_char_val; // return diffrence
        } else if (s1_char_val > s2_char_val) {
            return s1_char_val - s2_char_val; // return diffrence
        }

        s1++, s2++, n--;
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

/*
    locates the first occurrence of c (converted to a char) in the string pointed to by s.
    return a pointer to the located character, or NULL if the character does not appear in the string.
*/ // TESTED & GOOD
char * str_chr(const char *s, int c){
    while (*s != '\0') {
        if (*s == (char) c) {
            return (char *)s;
        }
        s++;
    }

    return NULL;
}


/*
    locates in the null-terminated string s the first occurrence of any character in the string charset and returns a pointer to this character.
    If no characters from charset occur anywhere in s strpbrk() returns NULL.
*/  // TESTED & GOOD
char * str_pbrk(const char *s, const char *charset) {
    const char *resetCharSet = charset;

    while (*s != '\0') {
        charset = resetCharSet;

        while (*charset != '\0') {
            if (*charset == *s) {
                return (char *)s;
            }
            charset++;
        }
        s++;
    }

    return NULL;
}

/*
    finds the first occurrence of any character from a set of characters in a given string. 
    It replaces that character with a null terminator and returns the part of the string before the delimiter. 
    If the string is empty or the end is reached, it returns NULL.
*/
char * str_sep(char **stringp, const char *delim) {

    return NULL;
}


/*
    function appends not more than n characters from s2, and then adds a terminating ‘\0’.
    return the pointer s1. 
*/ // TESTED AND DONE
char * str_cat(char *s1, const char *s2) {
    char *start = s1; // Need the point of the start of s1 because it doesnt "reset"

    while (*s1) {
        s1++; // Go to end of s1. "Last Index" 
    } 

    while (*s2) { // Adding s2 Chars to s1 from s1 "Last Index"
        *s1 = *s2; // *s1 & *s2 are characters
        s1++;
        s2++; 
    } // Works because s1 doesnt "reset" 

    *s1 = '\0';
    
    return start;
}


int main () {

    char s1[20] = "Hello";
    const char *s2 =  "CHANGE";

    char *test = str_cat(s1,s2);
    char *actual = strcat(s1,s2);

    printf("Test result: %s\n", test);
    printf("Actual result: %s\n", actual);

    return 0;
}