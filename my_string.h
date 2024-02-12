#ifndef __MY_STRING_H__
#define __MY_STRING_H__
#include <stdlib.h>
#include <string.h>

// REQUIRED
/*
    find length of string - The strnlen() function returns either the same result as strlen() or maxlen, whichever is smaller.
*/
int str_len(const char *s); 

/*
    functions lexicographically compare the null-terminated strings s1 and s2.
    return an integer greater than, equal to, or less than 0, according as the string s1 is greater than, equal to, or less than the string s2. 
*/
int str_cmp(const char *s1, const char *s2); 
int str_n_cmp(const char *s1, const char *s2, size_t n);

/*
    function copies n bytes from memory area src to memory area dst.
    returns the original value of dst.
*/
void * mem_cpy(void * restrict_dst, const void *restrict_src, size_t n);

/*
    locates the first occurrence of c (converted to a char) in the string pointed to by s.
    return a pointer to the located character, or NULL if the character does not appear in the string.
*/
char * str_chr(const char *s, int c);

/*
    locates in the null-terminated string s the first occurrence of any character in the string charset and returns a pointer to this character.
    If no characters from charset occur anywhere in s strpbrk() returns NULL.
*/
char * str_pbrk(const char *s, const char *charset);

/*
    finds the first occurrence of any character from a set of characters in a given string. 
    It replaces that character with a null terminator and returns the part of the string before the delimiter. 
    If the string is empty or the end is reached, it returns NULL.
*/
char * str_sep(char **stringp, const char *delim);

/*
    function appends not more than n characters from s2, and then adds a terminating ‘\0’.
    return the pointer s1.
*/
char * str_cat(char *s1, const char *s2);

// Supplimentry

int get_largest_length(const char *s1, const char *s2);

#endif