#include "string.hpp"
#include <iostream>

using namespace std;

char *String::strdup(const char *src) {
    int len = strlen(src);
    char *copy = new char[len + 1];
    strcpy(copy, src);
    return copy;
}

int String::strlen(const char *s) {
    int len = 0;
    while (s[len] != '\0') {
        ++len;
    }
    return len;
}

char *String::strcpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
    return dest;
}