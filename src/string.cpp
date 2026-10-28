#include "string.hpp"
#include <iostream>

using namespace std;

int String::strlen(const char *s) {
    int len = 0;
    while (s[len] != '\0') {
        ++len;
    }
    return len;
}