#include <gtest/gtest.h>
#include <string.h>

#include <algorithm>

#include "string.hpp"
#include "alloc.hpp"

TEST(StringFunction, strlen) {
    EXPECT_EQ(String::strlen(""), 0);
    EXPECT_EQ(String::strlen("foo"), 3);
}

TEST(StringFunction, strcpy) {
    char result[10];
    EXPECT_EQ(String::strcpy(result, "foo"), result);
    EXPECT_STREQ(result, "foo");

    EXPECT_EQ(String::strcpy(result, "a"), result);
    EXPECT_STREQ(result, "a");

    EXPECT_EQ(String::strcpy(result, ""), result);
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strdup) {
    char *result = String::strdup("foo");

    EXPECT_NE(result, nullptr);
    EXPECT_STREQ(result, "foo");
    EXPECT_NE(result, "foo");

    delete[] result;

    result = String::strdup("");

    EXPECT_NE(result, nullptr);
    EXPECT_STREQ(result, "");

    delete[] result;
}

TEST(StringFunction, strncpy) {
    char result[10] = "aso";
    EXPECT_EQ(String::strncpy(result, "as", 2), result);
    EXPECT_STREQ(result, "as");
    String::strncpy(result, "foo", 5);
    EXPECT_STREQ(result, "foo");
    EXPECT_EQ(result[3], '\0');
    EXPECT_EQ(result[4], '\0');
}

TEST(StringFunction, strcat) {
    char result[20] = "foo";
    EXPECT_EQ(String::strcat(result, "bar"), result);
    EXPECT_STREQ(result, "foobar");
    EXPECT_EQ(String::strcat(result, ""), result);
    EXPECT_STREQ(result, "foobar");
}

TEST(StringFunction, strncat) {
    char result[20] = "foo";
    EXPECT_EQ(String::strncat(result, "bar", 2), result);
    EXPECT_STREQ(result, "fooba");
    EXPECT_EQ(String::strncat(result, "z", 1), result);
    EXPECT_STREQ(result, "foobaz");
}

TEST(StringFunction, strcmp) {
    EXPECT_EQ(String::strcmp("abc", "abc"), 0);
    EXPECT_LT(String::strcmp("abc", "abd"), 0);
    EXPECT_GT(String::strcmp("abd", "abc"), 0);
    EXPECT_LT(String::strcmp("abc", "abcd"), 0);
    EXPECT_GT(String::strcmp("abcd", "abc"), 0);
}

TEST(StringFunction, strncmp) {
    EXPECT_EQ(String::strncmp("abc", "abc", 3), 0);
    EXPECT_EQ(String::strncmp("abc", "abd", 2), 0);
    EXPECT_LT(String::strncmp("abc", "abd", 3), 0);
    EXPECT_GT(String::strncmp("abd", "abc", 3), 0);
    EXPECT_LT(String::strncmp("abc", "abcd", 4), 0);
}

TEST(StringFunction, reverse_cpy) {
    char result[10];
    String::reverse_cpy(result, "abc");
    EXPECT_STREQ(result, "cba");
    String::reverse_cpy(result, "");
    EXPECT_STREQ(result, "");
    String::reverse_cpy(result, "a");
    EXPECT_STREQ(result, "a");
}

TEST(StringFunction, strchr) {
    const char *s = "hello";
    EXPECT_EQ(String::strchr(s, 'h'), s);
    EXPECT_EQ(String::strchr(s, 'e'), s + 1);
    EXPECT_EQ(String::strchr(s, 'o'), s + 4);
    EXPECT_EQ(String::strchr(s, 'z'), nullptr);
    EXPECT_EQ(String::strchr(s, '\0'), s + 5);
}

TEST(StringFunction, strstr) {
    const char *s = "hello";
    EXPECT_EQ(String::strstr(s, "h"), s);
    EXPECT_EQ(String::strstr(s, "ell"), s + 1);
    EXPECT_EQ(String::strstr(s, "lo"), s + 3);
    EXPECT_EQ(String::strstr(s, ""), s);
    EXPECT_EQ(String::strstr(s, "z"), nullptr);
}