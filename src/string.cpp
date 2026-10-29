#include "string.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

char *String::strdup(const char *src) {
    int len = strlen(src);
    char *copy = new char[len + 1];
    strcpy(copy, src);
    return copy;
}

String::String(const char *s) {
    buf = strdup(s);
}

String::String(const String &s) {
    buf = strdup(s.buf);
}

String::String(int length) {
    buf = new char[length + 1];
    buf[0] = '\0';
}

String::String(String &&s) {
    buf = s.buf;
    s.buf = nullptr;
}

void String::swap(String &s) {
    std::swap(buf, s.buf);
}

String &String::operator=(String s) {
    swap(s);
    return *this;
}

char &String::operator[](int index) {
    if (!in_bounds(index)) {
        cout << "ERROR: Index Out Of Bounds" << endl;
        return buf[0];
    }
    return buf[index];
}

const char &String::operator[](int index) const {
    if (!in_bounds(index)) {
        cout << "ERROR: Index Out Of Bounds" << endl;
        return buf[0];
    }
    return buf[index];
}


int String::size() const {
    return strlen(buf);
}

String String::reverse() const {
    String result(size());
    reverse_cpy(result.buf, buf);
    return result;
}

int String::indexOf(char c) const {
    const char *ptr = strchr(buf, c);

    if (ptr == nullptr) {
        return -1;
    }

    return ptr - buf;
}

int String::indexOf(const String &s) const {
    const char *ptr = strstr(buf, s.buf);

    if (ptr == nullptr) {
        return -1;
    }

    return ptr - buf;
}

bool String::operator==(const String &s) const {
    return strcmp(buf, s.buf) == 0;
}

bool String::operator!=(const String &s) const {
    return strcmp(buf, s.buf) != 0;
}

bool String::operator<(const String &s) const {
    return strcmp(buf, s.buf) < 0;
}

bool String::operator>(const String &s) const {
    return strcmp(buf, s.buf) > 0;
}

bool String::operator<=(const String &s) const {
    return strcmp(buf, s.buf) <= 0;
}

bool String::operator>=(const String &s) const {
    return strcmp(buf, s.buf) >= 0;
}

String String::operator+(const String &s) const {
    int len1 = strlen(buf);
    int len2 = strlen(s.buf);

    String result(len1 + len2);

    strcpy(result.buf, buf);
    strcat(result.buf, s.buf);

    return result;
}

String &String::operator+=(const String &s) {
    String result = *this + s;
    swap(result);
    return *this;
}

void String::print(std::ostream &out) const {
    out << buf;
}

void String::read(std::istream &in) {
    char temp[1024];
    in >> temp;
    delete[] buf;
    buf = strdup(temp);
}

String::~String() {
    delete[] buf;
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

void String::reverse_cpy(char *dest, const char *src) {
    int len = strlen(src);
    for (int i = 0; i < len; ++i) {
        dest[i] = src[len - 1 - i];
    }
    dest[len] = '\0';
}

const char *String::strchr(const char *str, char c) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            return &str[i];
        }
        ++i;
    }
    if (c == '\0') {
        return &str[i];
    }
    return nullptr;
}

const char *String::strstr(const char *haystack, const char *needle) {
    if (needle[0] == '\0') {
        return haystack;
    }
    for (int i = 0; haystack[i] != '\0'; ++i) {
        int j = 0;
        while (needle[j] != '\0' && haystack[i + j] == needle[j]) {
            ++j;
        }
        if (needle[j] == '\0') {
            return &haystack[i];
        }
    }
    return nullptr;
}

std::ostream &operator<<(std::ostream &out, String s) {
    s.print(out);
    return out;
}

std::istream &operator>>(std::istream &in, String &s) {
    s.read(in);
    return in;
}