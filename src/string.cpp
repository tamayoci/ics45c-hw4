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

char *String::strncpy(char *dest, const char *src, int n) {
    int i = 0;
    for (; i < n && src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    for (int j = i + 1; j < n; ++j) {
        dest[j] = '\0';
    }
    return dest;
}

char *String::strcat(char *dest, const char *src) {
    int j = strlen(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[j] = src[i];
        ++i;
        ++j;
    }
    dest[j] = '\0';
    return dest;
}

char *String::strncat(char *dest, const char *src, int n) {
    int j = strlen(dest);
    int i = 0;
    while (i < n && src[i] != '\0') {
        dest[j] = src[i];
        ++i;
        ++j;
    }
    dest[j] = '\0';
    return dest;
}

int String::strcmp(const char *left, const char *right) {
    int i = 0;
    while (left[i] != '\0' && right[i] != '\0') {
        if (left[i] != right[i]) {
            return left[i] - right[i];
        }
        ++i;
    }
    return left[i] - right[i];
}

int String::strncmp(const char *left, const char *right, int n) {
    int i = 0;
    while (i < n && left[i] != '\0' && right[i] != '\0') {
        if (left[i] != right[i]) {
            return left[i] - right[i];
        }
        ++i;
    }
    if (i == n) {
        return 0;
    }
    return left[i] - right[i];
}